#include "Commands.hpp"

Commands::Commands(Server *s, Client *c, int clientFd, std::vector<std::string> commandTokens, Messages msg): _server(s), _client(c), _clientFd(clientFd), _commandTokens(commandTokens)
{
	this->_messages = &msg;
}

Commands::~Commands(){}

void	Commands::executeCommandLine()
{
	std::string	msg;

	if (this->_server->isIrcCommand(this->_commandTokens[0]) == false)
	{
		this->_messages->sendErrUnknownCommand(this->_commandTokens[0], this->_clientFd);
		return ;
	}
	if (this->_client->isRegistrationComplete() == false) // user register
		handleConnectionCommands();
	else
	{
		if (this->_commandTokens[0] == "PASS")
			handlePassCommand();
		else if (this->_commandTokens[0] == "USER")
			handleUserCommand();
		else if (this->_commandTokens[0] == "NICK")
			handleNickCommand();
		else if (this->_commandTokens[0] == "PRIVMSG")
			handlePrivmsgCommand();
		else if (this->_commandTokens[0] == "JOIN")
			handleJoinCommand();
		else if (this->_commandTokens[0] == "QUIT")
			handleQuitCommand();
		else if (this->_commandTokens[0] == "NOTICE")
			handleNoticeCommand();
		else if (this->_commandTokens[0] == "INVITE")
			handleInviteCommand();
		else if (this->_commandTokens[0] == "PART")
			handlePartCommand();
		else if (this->_commandTokens[0] == "TOPIC")
			handleTopicCommand();
		else if (this->_commandTokens[0] == "KICK")
			handleKickCommand();
		else if (this->_commandTokens[0] == "MODE")
			handleModeCommand();
		else if (this->_commandTokens[0] == "WHOIS")
			return ;
		else if (this->_commandTokens[0] == "WHO")
			return ;
		else if (this->_commandTokens[0] == "PING")
		{
			std::string msg = ":localhost PONG :localhost\r\n";
			send(this->_clientFd, msg.c_str(), msg.size(), 0);
		}
	}
}

// Commands to connects

void	Commands::handleConnectionCommands()
{
	if (this->_commandTokens[0] == "PASS")
		handlePassCommand();
	else if (_commandTokens[0] == "USER" && this->_client->isPasswordSet() == true)
		handleUserCommand();
	else if (_commandTokens[0] == "NICK" && this->_client->isPasswordSet() == true)
		handleNickCommand();
	else if(_commandTokens[0] != "CAP")
		this->_messages->sendErrNotRegistered(this->_clientFd);

	if (this->_client->isRegistrationComplete())
		this->_messages->welcome(this->_client, this->_clientFd);
}

// CHANNELS

bool	Commands::doesChannelExist(std::string channelName)
{
	std::map<std::string, Channel*> map = this->_server->getChannelsByName();
	std::map<std::string, Channel*>::iterator it = map.begin();

	if (!map.empty())
	{
		while (it != map.end())
		{
			if (it->first == channelName)
				return (true);
			it++;
		}
	}
	return (false);
}

char	Commands::getIndex(){
	return this->_index;
}

void	Commands::setIndex(char operand){
	this->_index = operand;
}

