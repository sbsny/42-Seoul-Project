#include "Commands.hpp"

void	Commands::handleInviteCommand()
{
	std::string	msg;

	if (this->_commandTokens.size() < 3)
	{
		this->_messages->sendErrNeedMoreParams(this->_clientFd);
		return ;
	}
	else if(_server->doesClientExist(this->_commandTokens[1]) == false)
	{
		this->_messages->sendErrNoSuchNick(this->_commandTokens[1], this->_clientFd);
		return ;
	}
	else if (!doesChannelExist(this->_commandTokens[2]))
	{
		this->_messages->sendErrNoSuchChannel(this->_commandTokens[2], this->_clientFd);
		return ;
	}
	else if (!this->_server->getChannelByName(this->_commandTokens[2])->isUserInChannelByFd(this->_clientFd))
	{
		this->_messages->sendErrNotOnChannel(this->_clientFd, this->_commandTokens[2]);
		return ;
	}
	else if (this->_server->getChannelByName(this->_commandTokens[2])->isUserInChannelByFd(this->_server->getClient(this->_commandTokens[1])->getSocketFd()))
	{
		this->_messages->sendErrUserOnChannel(this->_clientFd, this->_commandTokens[1], this->_commandTokens[2]);
		return ;
	}
	if (this->_server->getChannelByName(this->_commandTokens[2])->isOperator(this->_clientFd))
	{
		this->_messages->sendRplInviting(_client->getNickname(), _client->getUsername(), this->_server->getClient(this->_commandTokens[1])->getNickname(), this->_commandTokens[2], this->_clientFd);
		this->_messages->sendRplInvite(_client->getNickname(), _client->getUsername(), this->_server->getClient(this->_commandTokens[1])->getNickname(), this->_commandTokens[2], this->_server->getClient(this->_commandTokens[1])->getSocketFd());

		this->_server->getChannelByName(this->_commandTokens[2])->addInvitedNick(this->_server->getClient(this->_commandTokens[1])->getNickname());
	}
	else
	{
		std::cout << "operator NOT" << std::endl;
		this->_messages->sendErrChanOpPrivsNeeded(this->_client->getNickname(), this->_commandTokens[2], this->_clientFd);
		return ;
	}

}
