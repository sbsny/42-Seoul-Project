#include "Commands.hpp"

void	Commands::handlePassCommand()
{
	if (!this->_client->isPasswordSet())
	{
		if (this->_commandTokens.size() < 2)
			this->_messages->sendErrNeedMoreParams(this->_clientFd);
		else if (this->_commandTokens[1] == this->_server->getServerPassword())
		{
			this->_client->setPasswordState();
			std::cout << " >> " << "Correct password!"  << std::endl;
		}
		else
		{
			this->_messages->sendErrPasswordMismatch(this->_clientFd);
			this->_client->incrementPassAttemptCount();
			std::cout << " >> " << "Incorrect password!" << std::endl;
			if (this->_client->getPassAttemptCount() == 3)
			{
				this->_server->addDisconnectedFd(this->_clientFd);
				std::cout << " >> " <<  "Client: " << this->_clientFd << " has been disconnected." << std::endl;
			}
		}
	}
	else if (this->_commandTokens[0] == "PASS" && this->_client->isPasswordSet())
		this->_messages->sendErrAlreadyRegistered(this->_clientFd);
}
