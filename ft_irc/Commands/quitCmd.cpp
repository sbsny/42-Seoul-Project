#include "Commands.hpp"

bool	Commands::isClientOnChannel()
{
	int fd;
	std::map<std::string, Channel *> listChannel = this->_server->getChannelsByName();
	std::map<int, Client*>	listClient = this->_server->getClientsByFd();

	for (std::map<int, Client*>::iterator it = listClient.begin(); it != listClient.end(); it++)
	{
		fd = it->first;
		for (std::map<std::string, Channel *>::iterator it = listChannel.begin(); it != listChannel.end(); it++)
		{
			if (this->_server->getChannelByName(it->first)->isUserInChannelByFd(fd) == true)
				return true;
			else
				return false;
		}
	}
	return false;
}

Channel*	Commands::rplToAllChan()
{
	Channel *c;
	int fd;
	std::map<std::string, Channel *> listChannel = _server->getChannelsByName();

	std::map<int, Client*>	listClient = _server->getClientsByFd();

	for (std::map<int, Client*>::iterator it = listClient.begin(); it != listClient.end(); it++)
	{
		fd = it->first;
		for (std::map<std::string, Channel *>::iterator it = listChannel.begin(); it != listChannel.end(); it++)
		{
			if (this->_server->getChannelByName(it->first)->isUserInChannelByFd(fd) == true)
				c = this->_server->getChannelByName(it->first);
		}
	}
	return(c);
}

void	Commands::handleQuitCommand()
{
	if(isClientOnChannel() == true)
	{
		this->_messages->sendRplQuit(this->_client->getNickname(), this->_client->getUsername(), buildJoinedMessage(1) , rplToAllChan());
		if (this->_client->isNicknameSet() == false)
			std::cout << " >> " << "Client " << this->_clientFd << " has been disconnected." << std::endl;
		else
			std::cout << " >> " << this->_client->getNickname() << " has been disconnected." << std::endl;
		this->_server->addDisconnectedFd(this->_clientFd);
	}
	else
	{
		if (this->_client->isNicknameSet() == false)
			std::cout << " >> " << "Client " << this->_clientFd << " has been disconnected." << std::endl;
		else
			std::cout << " >> " << this->_client->getNickname() << " has been disconnected." << std::endl;
		this->_server->addDisconnectedFd(this->_clientFd);
	}
}

