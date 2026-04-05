#include "Server.hpp"

Server::Server() {}

Server::~Server()
{
	std::cout << "Server Down" << std::endl;
	return ;
}

// getters, setters
void	Server::addDisconnectedFd(int fdUsersDc)
{
	this->_disconnectedFds.push_back(fdUsersDc);
}

std::vector<int>	Server::getDisconnectedFds()
{
	return (this->_disconnectedFds);
}

std::string	Server::getServerPassword()
{
    return (this->_serverPassword);
}

<<<<<<< codex/rename-variables-and-functions-in-ft_irc-j15bju
void	Server::setServerPassword(std::string pwd)
=======
void	Server::setPasswordState(std::string pwd)
>>>>>>> main
{
    this->_serverPassword = pwd;
}

std::map<int, Client*>	Server::getClientsByFd()
{
	return (this->_clientsByFd);
}

Client *Server::getClient(std::string nick)
{	for (std::map<int, Client *>::iterator it = _clientsByFd.begin(); it != _clientsByFd.end(); it++)
	{
		if (it->second->getNickname() == nick)
			return (it->second);
	}
	return (NULL);
}

void	Server::addClientByFd(int fd, Client *user)
{
	this->_clientsByFd.insert(std::pair<int, Client*>(fd, user));
}

std::map<std::string, Channel*>	Server::getChannelsByName()
{
	return (this->_channelsByName);
}

Channel*	Server::getChannelByName(std::string chann)
{
	return (this->_channelsByName[chann]);
}

void	Server::addChannel(Channel *c)
{
	this->_channelsByName.insert(std::pair<std::string, Channel*>(c->getName(), c));
}

// Setup
void	Server::createServer(int port)
{
	Messages	msg;
	int			opt = 1;

	if ((this->_serverFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		msg.errorMsg("Socket Error");

	if (setsockopt(this->_serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
		msg.errorMsg("Setsockopt Error");
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_addr.s_addr = INADDR_ANY;
	this->_addr.sin_port = htons(port);

	if (bind(this->_serverFd, (struct sockaddr*) &this->_addr, sizeof(this->_addr)) < 0)
		msg.errorMsg("Bind Error");
	this->_addrLen = sizeof(this->_addr);

	if (listen(this->_serverFd, 500) < 0)
		msg.errorMsg("listen Error");

	this->_commandList.push_back("PASS");
	this->_commandList.push_back("NICK");
	this->_commandList.push_back("USER");
	this->_commandList.push_back("PRIVMSG");
	this->_commandList.push_back("JOIN");
	this->_commandList.push_back("QUIT");
	this->_commandList.push_back("PING");
	this->_commandList.push_back("CAP");
	this->_commandList.push_back("KICK");
	this->_commandList.push_back("INVITE");
	this->_commandList.push_back("TOPIC");
	this->_commandList.push_back("WHOIS");
	this->_commandList.push_back("WHO");
	this->_commandList.push_back("MODE");
	this->_commandList.push_back("PART");
	this->_commandList.push_back("NOTICE");

	std::cout << "Listening to port : " << port << std::endl;
}

void	Server::runServerLoop()
{
	while (true)
	{
		Messages msg;
		int		senderFd;

		acceptClient();

		for (std::map<int, Client *>::iterator it = this->_clientsByFd.begin(); it != this->_clientsByFd.end(); it++)
		{
			senderFd = it->first;
			if (FD_ISSET(senderFd, &this->_fdSet))
			{
				int		len = 0;
				bool	err;
				const char *inputBuffer;

				std::string buffer1 = receiveMessage(&len, senderFd, err);
				if(len <= 0)
				{
					this->_disconnectedFds.push_back(senderFd);
					std::cout << ">>" << "Client " << senderFd << " has been disconnected." << std::endl;
					continue;
				}
				inputBuffer = buffer1.c_str();
				msg.displayMessageOnServer(inputBuffer, senderFd);
				if (!err)
					continue;
				if (strncmp(inputBuffer, "", 1) != 0)
				{
					int nb;
					nb = countCharInStringBuffer(inputBuffer, '\n');
					if (nb > 1)
					{
						std::vector<std::string>	line;
						int							i = 0;
						line = splitBufferByDelimiter(inputBuffer, '\n');
						while (i < nb)
						{
							msg.displayMessageOnServer(line[i], senderFd);
							handleCommandLine(senderFd, line[i]);
							i++;
						}
					}
					else
						handleCommandLine(senderFd, inputBuffer);
				}
			}
		}
		if (!this->_disconnectedFds.empty())
			disconnectClients();
		if (!this->_channelsByName.empty())
			disconnectEmptyChannels();
	}
}

void	Server::acceptClient()
{
	Messages msg;
	int	maxFd;
	int	newUser;
	int	clientFd;

	FD_ZERO(&this->_fdSet);
	FD_SET(this->_serverFd, &this->_fdSet);

	maxFd = this->_serverFd;
	for (std::map<int, Client *>::iterator it = this->_clientsByFd.begin(); it != this->_clientsByFd.end(); it++)
	{
		clientFd = it->first;
		FD_SET(clientFd, &this->_fdSet);
		fcntl(clientFd, F_SETFL, O_NONBLOCK);
		maxFd = std::max(maxFd, clientFd);
	}
	if (select(maxFd + 1, &this->_fdSet, NULL, NULL, NULL) < 0)
		msg.errorMsg("Select Error");
	if (FD_ISSET(this->_serverFd, &this->_fdSet))
	{
		if ((newUser = accept(this->_serverFd, (struct sockaddr*) &this->_addr,(socklen_t*) &this->_addrLen)) < 0)
			msg.errorMsg("Accept Error");
		Client *cl = new Client();
		this->_clientsByFd.insert(std::pair<int, Client*>(newUser, cl));
		this->_clientsByFd[newUser]->setSocketFd(newUser);
		std::cout << std::endl;
		std::cout << " >> " << "Client Connected [ID: "<< newUser << "]" << std::endl;
	}
}

std::string	Server::receiveMessage(int *len, int senderFd, bool &err)
{
	std::string message;
	size_t ret = BUFFER_SIZE;

	err = true;
	int len1 = 0;
	char inputBuffer[BUFFER_SIZE + 1] = {0};
	ret = recv(senderFd, inputBuffer, BUFFER_SIZE, 0);
	if (ret == 0)
	{
		*len = 0;
		return (message);
	}
	while(inputBuffer[len1])
		len1++;
	if (inputBuffer[len1 - 2] == '\r')
	{
		*len = 1;
		message = inputBuffer;
		return message;
	}
	inputBuffer[len1] = '\0';
	if (ret > 0) {
		_users[senderFd].inputBuffer += inputBuffer;
		size_t nlPos = (_users[senderFd].inputBuffer).find('\n');
		if (nlPos != std::string::npos) {
			message = _users[senderFd].inputBuffer.substr(0, (int)nlPos);
			std::string tmp = _users[senderFd].inputBuffer.substr(nlPos + 1, std::string::npos);

			_users[senderFd].inputBuffer = tmp;
			err = true;

		}
		else {
			message = inputBuffer;
			err = false;
		}
	}

	*len = message.length();
	if(message == "")
		*len = 1;

	return (message);
}

void	Server::dispatchToCommands(int senderFd, std::string buf)
{
	Messages msg;
	if (buf.find('\r') != std::string::npos)
	{
		if (buf.find("\r\n") != std::string::npos)
			buf = buf.substr(0, buf.length() - 1);
		if (buf.length() > 1)
			buf = buf.substr(0, buf.length() - 1);
	}

	std::vector<std::string>	line = splitBufferByDelimiter(buf, ' ');

	Commands *cmd = new Commands(this, _clientsByFd[senderFd], senderFd, line, msg);
	cmd->executeCommandLine();
	delete cmd;
}

void	Server::handleCommandLine(int senderFd, std::string buf)
{
	std::string msg;

	if (buf.length() > 1000)
	{
		msg = "Error: Character Length Limit";
		send(senderFd, msg.c_str(), msg.size(), 0);
		return ;
	}
	if (buf[0] == '\n' || buf[0] == '\t')
		return ;
	dispatchToCommands(senderFd, buf);
}

// Utils
int		Server::countCharInStringBuffer(std::string buf, char c)
{
	int	count = 0;

	for (unsigned long i = 0; (i = buf.find(c, i)) != std::string::npos; i++)
        count++;
	return (count);
}

bool	Server::isIrcCommand(std::string str)
{

	for (unsigned int i = 0; i < this->_commandList.size(); i++)
	{
		if (this->_commandList[i] + '\n' == str || this->_commandList[i] == str)
			return (true);
	}
	return (false);
}

bool	Server::doesClientExist(std::string nick)
{
	for (std::map<int, Client *>::iterator it = _clientsByFd.begin(); it != _clientsByFd.end(); it++)
	{
		if (it->second->getNickname() == nick)
			return (true);
	}
	return (false);
}

std::vector<std::string>	Server::splitBufferByDelimiter(std::string buf, char charset)
{
	std::string					tmp;
	std::vector<std::string>	split;
	unsigned long				endIndex = 0;
	unsigned long				startIndex = 0;

	for (unsigned long i = 0; i <= buf.size(); i++)
	{
		if (buf[i] == charset || i == buf.size())
		{
			endIndex = i;
			tmp.clear();
			tmp.append(buf, startIndex, endIndex - startIndex);
			if (!tmp.empty())
				split.push_back(tmp);
			startIndex = endIndex + 1;
		}
	}
	return (split);
}

void	Server::disconnectClients()
{

	for (std::vector<int>::iterator it = this->_disconnectedFds.begin(); it != this->_disconnectedFds.end(); it++) {
		close(this->_clientsByFd.find(*it)->first);
		delete this->_clientsByFd.find(*it)->second;
		this->_clientsByFd.erase(this->_clientsByFd.find(*it)->first);
	}
	this->_disconnectedFds.clear();
}

void	Server::disconnectEmptyChannels()
{
	std::map<std::string, Channel*> map = this->_channelsByName;
	std::map<std::string, Channel*>::iterator it = map.begin();

	while (it != map.end())
	{
		if (it->second->getUsersByFd().size() == 1)
		{
			this->_channelsByName.erase(it->first);
			delete it->second;
		}
		it++;
	}
}
