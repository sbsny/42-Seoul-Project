#include "Commands.hpp"

void	Commands::handleKickCommand()
{
	std::string reason;
	if (this->_commandTokens.size() < 3)
	{
		this->_messages->sendErrNeedMoreParams(this->_clientFd);
		return;
	}
	if((this->_commandTokens[1][0] == '#') && doesChannelExist(this->_commandTokens[1]) == true)
	{
		if (this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByFd(this->_clientFd))
		{
			if (this->_server->getChannelByName(this->_commandTokens[1])->isOperator(this->_clientFd))
			{
				std::cout << " >> " <<  "Accepted : Channel Operator" << std::endl;
				if (this->_server->doesClientExist(this->_commandTokens[2]) && this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByFd(this->_server->getClient(this->_commandTokens[2])->getSocketFd()) == true)
				{
					if(this->_commandTokens[2] == this->_server->getClient(this->_commandTokens[2])->getNickname())
					{
						if(buildJoinedMessage(3) == ": ")
							reason = "No Reason";
						else
							reason = buildJoinedMessage(3);
						std::map<int, Client*> UserCo = this->_server->getChannelByName(this->_commandTokens[1])->getUsersByFd();
						for (std::map<int, Client*>::iterator it = UserCo.begin(); it != UserCo.end(); it++)
						{
							this->_messages->sendRplKick(_client->getNickname(), _client->getUsername(), this->_commandTokens[1], this->_server->getClient(this->_commandTokens[2])->getNickname(), reason, it->first);
						}
						std::cout << " >> " << this->_server->getClient(this->_commandTokens[2])->getNickname() << " is kicked from Channel " << this->_commandTokens[1] << std::endl;
						this->_server->getChannelByName(this->_commandTokens[1])->removeUser(this->_server->getClient(this->_commandTokens[2])->getNickname());
					}
				}
				else
				{
					this->_messages->sendErrUserNotInChannel(this->_client->getNickname(), this->_commandTokens[1], this->_clientFd);
					return ;
				}
			}
			else
			{
				std::cout << " >> " << "Denied : Not Channel Operator" << std::endl;
				this->_messages->sendErrChanOpPrivsNeeded(this->_client->getNickname(), this->_commandTokens[1], this->_clientFd);
				return ;
			}
		}
		else
			this->_messages->sendErrNotOnChannel(this->_client->getNickname(), this->_commandTokens[1], this->_clientFd);
	}
	else
		this->_messages->sendErrNoSuchChannel(this->_commandTokens[1], this->_clientFd);
}
