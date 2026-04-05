#include "Commands.hpp"

std::string	Commands::buildJoinedMessage(int line)
{
	std::string msg;
	std::vector<std::string>::iterator it = this->_commandTokens.begin() + line;
	while (it != this->_commandTokens.end())
	{
		msg += *it;
		msg += " ";
		it++;
	}
	return(msg);
}

void	Commands::handlePrivmsgCommand()
{
	if (this->_commandTokens.size() < 3)
		this->_messages->sendErrNoRecipient(this->_clientFd);
	else if(this->_commandTokens.size() > 2)
	{
		if ((this->_commandTokens[1][0] == '#' || this->_commandTokens[1][0] == '&'))
		{
			if (doesChannelExist(this->_commandTokens[1]) == true && this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByFd(this->_clientFd) == true)
			{
				std::string msg = buildJoinedMessage(2);
				if (msg == ": ")
				{
					this->_messages->sendErrNoTextToSend(this->_clientFd);
					return ;
				}
				else
					this->_messages->sendRplPrivmsgChannel(this->_client->getNickname(), this->_commandTokens[1], msg, this->_server->getChannelByName(this->_commandTokens[1]), this->_clientFd);
			}
			else
			{
				this->_messages->sendErrCannotSendToChan(this->_commandTokens[1], this->_clientFd);
				return ;
			}
		}
		else if (this->_server->doesClientExist(this->_commandTokens[1]) == true)
		{
			if (buildJoinedMessage(2) == ": ")
			{
				this->_messages->sendErrNoTextToSend(this->_clientFd);
				return ;
			}
			else
			{
				this->_messages->sendRplPrivmsg(this->_client->getNickname(), this->_commandTokens[1], buildJoinedMessage(2), this->_server->getClient(this->_commandTokens[1])->getSocketFd());
				return ;
			}
		}
		else
		{
			this->_messages->sendErrNoSuchNick(this->_commandTokens[1], this->_clientFd);
			return ;
		}
	}
}

void	Commands::handleNoticeCommand()
{
	if (this->_commandTokens.size() < 3)
		this->_messages->sendErrNoRecipient(this->_clientFd);
	else if(this->_commandTokens.size() > 2)
	{
		if ((this->_commandTokens[1][0] == '#' || this->_commandTokens[1][0] == '&'))
		{
			if (doesChannelExist(this->_commandTokens[1]) == true && this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByFd(this->_clientFd) == true)
			{
				std::string msg = buildJoinedMessage(2);

				if (msg == ": ")
				{
					this->_messages->sendErrNoTextToSend(this->_clientFd);
					return ;
				}
				else
					this->_messages->sendRplPrivmsgChannel(this->_client->getNickname(), this->_commandTokens[1], msg, this->_server->getChannelByName(this->_commandTokens[1]), this->_clientFd);
			}
			else
			{
				this->_messages->sendErrCannotSendToChan(this->_commandTokens[1], this->_clientFd);
				return ;
			}
		}
		else if (this->_server->doesClientExist(this->_commandTokens[1]) == true)
		{
			if (buildJoinedMessage(2) == ": ")
			{
				this->_messages->sendErrNoTextToSend(this->_clientFd);
				return ;
			}
			else
			{
				this->_messages->sendRplNotice(this->_client->getNickname(), this->_commandTokens[1], buildJoinedMessage(2), this->_server->getClient(this->_commandTokens[1])->getSocketFd());
				return ;
			}
		}
		else
		{
			this->_messages->sendErrNoSuchNick(this->_commandTokens[1], this->_clientFd);
			return ;
		}
	}
}
