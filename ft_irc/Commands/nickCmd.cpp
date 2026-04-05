#include "Commands.hpp"

bool	nicknameIsValid(std::string nick)
{
	for (int i = 0; nick[i]; i++)
	{
		if (i == 0 && (nick[i] == '$' || nick[0] == ':' || nick[0] == '#' || nick[0] == '&'))
			return (false);
		if (nick[i] == ' ' || nick[0] == ',' || nick[0] == '?' || nick[0] == '!'
			|| nick[0] == '@' || nick[0] == '*' || nick[0] == '.')
			return (false);
	}
	return (true);
}

void	Commands::handleNickCommand()
{
	std::string	msg;

	if (this->_commandTokens.size() == 1 )
		this->_messages->sendErrNoNicknameGiven(this->_clientFd);
	else if(this->_commandTokens.size() >= 2)
	{
		if (this->_server->doesClientExist(this->_commandTokens[1]))
			this->_messages->sendErrNicknameInUse(this->_commandTokens[1], this->_clientFd);
		else if (nicknameIsValid(this->_commandTokens[1]) == true)
		{
			if(this->_client->isNicknameSet())
			{
				std::string	msg = ":" +  _client->getNickname() + "!" + _client->getUsername() + "@localhost NICK :" + this->_commandTokens[1] + "\r\n";
				if(send(this->_clientFd, msg.c_str(), msg.length(), 0) < 0)
					_messages->errorMsg("Failed Send");
			}
			this->_client->setNickname(this->_commandTokens[1]);
			std::cout << " >> " << "Nickname: " << this->_client->getNickname() <<"\n";
		}
		else
			this->_messages->sendErrErroneousNickname(this->_commandTokens[1], this->_clientFd);
	}
}
