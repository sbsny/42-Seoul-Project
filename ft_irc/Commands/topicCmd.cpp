#include "Commands.hpp"

void	Commands::handleTopicCommand()
{
	std::string msg;

	if (this->_commandTokens.size() == 1)
	{
		this->_messages->sendErrNeedMoreParams(_clientFd);
		return ;
	}
	if ((this->_commandTokens[1][0] != '#' || this->_commandTokens[1][0] != '&') && doesChannelExist(this->_commandTokens[1]) == false)
	{
		this->_messages->sendErrNoSuchChannel(this->_commandTokens[1], _clientFd);
		return;
	}
	if (this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByFd(this->_clientFd) && this->_server->getChannelByName(this->_commandTokens[1])->getTopicProtected() == true)
	{
		if(this->_server->getChannelByName(this->_commandTokens[1])->isOperator(this->_clientFd) == false)
		{
			this->_messages->sendErrChanOpPrivsNeeded(this->_client->getNickname(), this->_commandTokens[1], this->_clientFd);
			return ;
		}
		else
		{
			if (this->_commandTokens[2] == "::")
			{
				msg = ":" + this->_client->getNickname() + "!" + this->_client->getUsername() + "@localhost TOPIC :" + this->_commandTokens[1] + "\r\n";
				this->_server->getChannelByName(this->_commandTokens[1])->broadcastMessage(-1, msg);
				this->_server->getChannelByName(this->_commandTokens[1])->unsetTopic("");
			}
			else if (this->_commandTokens.size() > 2 && this->_commandTokens[2] != "::")
			{
				msg = ":" + this->_client->getNickname() + "!" + this->_client->getUsername() + "@localhost TOPIC " + this->_commandTokens[1] + " :" + buildJoinedMessage(2) + "\r\n";
				this->_server->getChannelByName(this->_commandTokens[1])->broadcastMessage(-1, msg);
				this->_server->getChannelByName(this->_commandTokens[1])->setTopic(buildJoinedMessage(2));
			}
			if (this->_server->getChannelByName(this->_commandTokens[1])->topicIsSet() && this->_commandTokens[2] != "::")
				this->_messages->sendRplTopic(this->_server->getChannelByName(this->_commandTokens[1]));
			else
				this->_messages->sendRplNoTopic(this->_server->getChannelByName(this->_commandTokens[1]));
		}
	}
	else if (this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByFd(this->_clientFd) && this->_server->getChannelByName(this->_commandTokens[1])->getTopicProtected() == false)
	{
		if (this->_commandTokens[2] == "::")
		{
			msg = ":" + this->_client->getNickname() + "!" + this->_client->getUsername() + "@localhost TOPIC :" + this->_commandTokens[1] + "\r\n";
			this->_server->getChannelByName(this->_commandTokens[1])->broadcastMessage(-1, msg);
			this->_server->getChannelByName(this->_commandTokens[1])->unsetTopic("");
		}
		else if (this->_commandTokens.size() > 2 && this->_commandTokens[2] != "::")
		{
			msg = ":" + this->_client->getNickname() + "!" + this->_client->getUsername() + "@localhost TOPIC " + this->_commandTokens[1] + " :" + buildJoinedMessage(2) + "\r\n";
			this->_server->getChannelByName(this->_commandTokens[1])->broadcastMessage(-1, msg);
			this->_server->getChannelByName(this->_commandTokens[1])->setTopic(buildJoinedMessage(2));
		}
		if (this->_server->getChannelByName(this->_commandTokens[1])->topicIsSet() && this->_commandTokens[2] != "::")
			this->_messages->sendRplTopic(this->_server->getChannelByName(this->_commandTokens[1]));
		else
			this->_messages->sendRplNoTopic(this->_server->getChannelByName(this->_commandTokens[1]));
	}
	else
		this->_messages->sendErrNotOnChannel(this->_client->getNickname(), this->_commandTokens[1], this->_clientFd);
}
