#include "Commands.hpp"

void	Commands::handleUserCommand()
{
	std::string realname;

	if(!this->_client->isRealNameSet())
	{
		if (this->_commandTokens.size() < 5 || this->_commandTokens[4][0] != ':')
		{
			this->_messages->sendErrNeedMoreParams(this->_clientFd);
			return;
		}
		if (this->_commandTokens[4][0] == ':' && this->_commandTokens[4].size() >= 2)
		{
			this->_commandTokens[4] = this->_commandTokens[4].substr(1, this->_commandTokens[4].size() - 1);
			if(this->_commandTokens.size() == 5)
			{
				std::string realname = this->_commandTokens[4];
				this->_client->setRealName(realname);
			}
			else if(this->_commandTokens.size() >= 2 && this->_commandTokens.size() != 5)
			{
				std::string realname = this->_commandTokens[4] + " " + this->_commandTokens[5];
				this->_client->setRealName(realname);
			}
			this->_client->setUsername(this->_commandTokens[1]);
			std::cout << " >> " << "Realname: " << this->_client->getRealName() << std::endl;
			std::cout << " >> " << "User: " << this->_client->getUsername() << std::endl;
		}
	}
	else if(_commandTokens[0] == "USER" && this->_client->isRealNameSet())
		this->_messages->sendErrAlreadyRegistered(this->_clientFd);

}
