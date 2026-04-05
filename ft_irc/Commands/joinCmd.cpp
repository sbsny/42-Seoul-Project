#include "Commands.hpp"

void	Commands::createOrJoinChannel(std::string channelName, std::string key)
{
	std::string	msg;

	bool		doesChannelExist = this->doesChannelExist(channelName);

	if (!doesChannelExist)
	{
		Channel	*chan;

		if (!key.empty())
			chan = new Channel(channelName, this->_client, key);
		else
			chan = new Channel(channelName, this->_client);
		this->_server->addChannel(chan);
		std::cout << "Channel name: " << channelName << " has been created by " << this->_server->getChannelByName(channelName)->getCreator()->getNickname() << std::endl;
	}
	else
	{
		if (!this->_server->getChannelByName(channelName)->getKey().empty() && key != this->_server->getChannelByName(channelName)->getKey())
			this->_messages->sendErrCannotJoin(this->_client->getSocketFd(), channelName, 475);
		else if (this->_server->getChannelByName(channelName)->getSizeMax() != -1 && this->_server->getChannelByName(channelName)->countUsersInChannel() >= this->_server->getChannelByName(channelName)->getSizeMax())
			this->_messages->sendErrCannotJoin(this->_client->getSocketFd(), channelName, 471);
		else if (this->_server->getChannelByName(channelName)->getInviteOnly() == true && this->_server->getChannelByName(channelName)->isInvited(this->_client->getNickname()) == false)
			this->_messages->sendErrCannotJoin(this->_client->getSocketFd(), channelName, 473);
		else
		{
			this->_server->getChannelByName(channelName)->addUser(this->_client, this->_clientFd);
			std::cout << " >> " << this->_client->getNickname() << " has joined " << channelName <<"\n";
		}
	}
	if (!this->_server->getChannelByName(channelName)->isUserInChannelByFd(this->_client->getSocketFd()))
		return ;
	Channel*	c = this->_server->getChannelByName(channelName);

	this->_messages->sendRplJoin(this->_client->getNickname(), this->_client->getUsername(), channelName, c);
	if (!c->topicIsSet())
		this->_messages->sendRplNoTopic(c);
	else
		this->_messages->sendRplTopic(c);
	this->_messages->sendRplNameReply(c, this->_client->getSocketFd());
	this->_messages->sendRplEndOfNames(c, this->_client->getSocketFd(), this->_client->getNickname());
}


void	Commands::handleJoinCommand()
{
	bool	isKeyEmpty = true;

	if (this->_commandTokens.size() > 2 && this->_commandTokens[2].empty() != 1)
			isKeyEmpty = false;
	if (this->_commandTokens.size() == 1)
		this->_messages->sendErrNeedMoreParams(this->_clientFd);
	if (this->_commandTokens[1].find(',') != std::string::npos)
	{
		std::string					tmp;
		std::vector<std::string>	split;
		unsigned long				endIndex = 0;
		unsigned long				startIndex = 0;
		std::vector<std::string>	channelList = this->_server->splitBufferByDelimiter(this->_commandTokens[1], ',');
		std::vector<std::string>	keyList;
		if (isKeyEmpty == false)
		{
			for (unsigned long j = 0; j <= _commandTokens[2].size(); j++)
			{
				if (_commandTokens[2][j] == ',' || j == _commandTokens[2].size())
				{
					endIndex = j;
					tmp.clear();
					tmp.append(_commandTokens[2], startIndex, endIndex - startIndex);
					if (!tmp.empty())
						keyList.push_back(tmp);
					startIndex = endIndex + 1;
				}
			}
		}

		unsigned long long			i = 0;
		while (i < channelList.size())
		{
			if (!isKeyEmpty && !keyList[i].empty())
				createOrJoinChannel(channelList[i], keyList[i]);
			else
				createOrJoinChannel(channelList[i], "");
			i++;
		}
	}
	else
	{
		if (!isKeyEmpty)
			createOrJoinChannel(this->_commandTokens[1], this->_commandTokens[2]);
		else
			createOrJoinChannel(this->_commandTokens[1], "");
	}
}
