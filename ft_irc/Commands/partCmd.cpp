#include "Commands.hpp"

void	Commands::leaveMultipleChannels()
{
	std::vector<std::string> channels = _server->splitBufferByDelimiter(this->_commandTokens[1], ',');

	for(unsigned int i = 0; i < channels.size(); i++)
	{
		if ((channels[i][0] == '#') && doesChannelExist(channels[i]) == true)
		{
			std::map<int, Client*> UserCo = this->_server->getChannelByName(channels[i])->getUsersByFd();
			if(this->_server->getChannelByName(channels[i])->isUserInChannelByFd(this->_clientFd) == true)
			{
				for (std::map<int, Client*>::iterator it = UserCo.begin(); it != UserCo.end(); it++)
				{
					this->_messages->sendRplLeftChannel(this->_client->getNickname(), this->_client->getUsername(), channels[i], it->first);
				}
				this->_server->getChannelByName(channels[i])->removeUser(_client->getNickname());
				std::cout << " >> " << this->_client->getNickname() << " has left channel " << channels[i] << std::endl;
			}
			else
				this->_messages->sendErrNotOnChannel(this->_client->getNickname(), channels[i], this->_clientFd);
		}
		else
		{
			this->_messages->sendErrNoSuchChannel(this->_commandTokens[1], this->_clientFd);
			return ;
		}
	}
}

void	Commands::handlePartCommand()
{
	std::string::iterator searchMulti = find(this->_commandTokens[1].begin(), this->_commandTokens[1].end(), ',');
	if (this->_commandTokens.size() < 1)
	{
		this->_messages->sendErrNeedMoreParams(this->_clientFd);
		return ;
	}
	if(*searchMulti == ',')
	{
		leaveMultipleChannels();
		return ;
	}
	if ((this->_commandTokens[1][0] == '#') && doesChannelExist(this->_commandTokens[1]) == true && *searchMulti != ',')
	{
		std::map<int, Client*> UserCo = this->_server->getChannelByName(this->_commandTokens[1])->getUsersByFd();
		if(this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByFd(this->_clientFd) == true)
		{
			for (std::map<int, Client*>::iterator it = UserCo.begin(); it != UserCo.end(); it++)
			{
				this->_messages->sendRplLeftChannel(this->_client->getNickname(), this->_client->getUsername(), this->_commandTokens[1], it->first);
			}
			this->_server->getChannelByName(this->_commandTokens[1])->removeUser(this->_client->getNickname());
			std::cout << " >> " <<  this->_client->getNickname() << " has left channel " << this->_commandTokens[1] << std::endl;
		}
		else
			this->_messages->sendErrNotOnChannel(this->_client->getNickname(), this->_commandTokens[1], this->_clientFd);
	}
	else
	{
		this->_messages->sendErrNoSuchChannel(this->_commandTokens[1], this->_clientFd);
		return ;
	}
	if (this->_server->getChannelByName(this->_commandTokens[1])->getUsersByFd().size() == 1)
       this->_server->disconnectEmptyChannels();
}
