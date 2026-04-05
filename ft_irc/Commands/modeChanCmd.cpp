#include "Commands.hpp"

void	Commands::handleModeOnChannel()
{
	if(validateModeParameter() == 1)
		return;
	if(getIndex() == '\0')
		return;
	std::map<int, Client*> UserCo = this->_server->getChannelByName(this->_commandTokens[1])->getUsersByFd();
	if(this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByFd(this->_clientFd) == true)
	{
		for (std::map<int, Client*>::iterator it = UserCo.begin(); it != UserCo.end(); it++)
		{
			std::string	msg;
			if(this->_commandTokens.size() == 3)
				msg = ":" + this->_client->getNickname() + " " + this->_commandTokens[0] + " " + this->_commandTokens[1] + " " + this->_commandTokens[2] + "\r\n";
			else if (this->_commandTokens.size() == 4)
				msg = ":" + this->_client->getNickname() + " " + this->_commandTokens[0] + " " + this->_commandTokens[1] + " " + this->_commandTokens[2] + " " + this->_commandTokens[3] + "\r\n";
			send(it->first, msg.c_str(), msg.length(), 0);
		}
	}
	std::vector<char>::iterator	it = this->_optionList.begin();
	for(; it != this->_optionList.end(); ++it)
	{
		char option = *it;
		switch (option)
		{
			case 'i':
				setChannelInviteOnlyMode();
				break;

			case 't' :
				setChannelRestrictTopicMode();
				break;

			case 'k' :
				setChannelKeyMode();
				break;

			case 'o' :
				setChannelOperatorMode();
				break;

			case 'l' :
				setChannelLimitMode();
				break;

			default:
				this->_messages->sendErrUnknownModeFlag(this->_commandTokens[0], this->_clientFd);
				break;
		}
	}
	return;
}

int		Commands::validateModeTargetUser()
{
	std::vector<char>::iterator	it = this->_optionList.begin();
	for(; it != this->_optionList.end(); it++)
	{
		char	option = *it;
		if(option == 'o')
		{
			if(this->_commandTokens.size() == 3)
				return 1;
			if(getIndex() == '+' && this->_commandTokens.size() != 3)
			{
				if(!this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByNickname(this->_commandTokens[3]))
				{
					this->_messages->sendErrNoSuchNick(this->_commandTokens[3], this->_clientFd);
					this->_messages->sendErrUserNotInChannel(this->_commandTokens[3], this->_commandTokens[1], this->_clientFd);
					return 1;
				}
				else if(this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByNickname(this->_commandTokens[3]) && this->_server->getChannelByName(this->_commandTokens[1])->isOperator(this->_commandTokens[3]) == true)
					return 1;
			}
		}
	}
	return 0;
}

void	Commands::setChannelInviteOnlyMode()
{
	if(this->getIndex() == '+')
	{
		if (this->_server->getChannelByName(this->_commandTokens[1])->isOperator(this->_clientFd) == false)
		{
			this->_messages->sendErrChanOpPrivsNeeded(_client->getNickname(), this->_commandTokens[1], this->_clientFd);
			std::cout << " >> " <<  this->_server->getClient(this->_commandTokens[3])->getNickname() << " are not Channel Operator " << std::endl;
			return ;
		}
		else
			this->_server->getChannelByName(this->_commandTokens[1])->setInviteOnly(true);
	}
	else if (this->getIndex() == '-')
	{
		if (this->_server->getChannelByName(this->_commandTokens[1])->isOperator(this->_clientFd) == false)
		{
			this->_messages->sendErrChanOpPrivsNeeded(_client->getNickname(), this->_commandTokens[1], this->_clientFd);
			std::cout << " >> " << this->_server->getClient(this->_commandTokens[3])->getNickname() << " are not Channel Operator " << std::endl;
			return ;
		}
		else
			this->_server->getChannelByName(this->_commandTokens[1])->setInviteOnly(false);
	}
}

void	Commands::setChannelRestrictTopicMode(){

	if(this->getIndex() == '+')
		this->_server->getChannelByName(this->_commandTokens[1])->setTopicProtected(true);
	else if (this->getIndex() == '-')
		this->_server->getChannelByName(this->_commandTokens[1])->setTopicProtected(false);
}

void	Commands::setChannelKeyMode()
{
	if (this->_commandTokens.size() == 3)
		return ;
	if(this->getIndex() == '+')
		this->_server->getChannelByName(this->_commandTokens[1])->setKey(this->_commandTokens[3]);
	else if (this->getIndex() == '-')
		this->_server->getChannelByName(this->_commandTokens[1])->setKey("");
}

void	Commands::setChannelOperatorMode()
{
	if (this->getIndex() == '+')
	{
		this->_server->getChannelByName(this->_commandTokens[1])->addOperator(this->_server->getClient(this->_commandTokens[3]), this->_server->getClient(this->_commandTokens[3])->getSocketFd());
		std::cout << " >> " << this->_server->getClient(this->_commandTokens[3])->getNickname() << " is now Channel Operator " << std::endl;
	}
	else if (this->getIndex() == '-')
	{
		this->_server->getChannelByName(this->_commandTokens[1])->removeOperator(this->_commandTokens[3]);
		std::cout << " >> " << this->_server->getClient(this->_commandTokens[3])->getNickname() << " is removed of Channel Operators " << std::endl;
	}
}

void	Commands::setChannelLimitMode()
{
	if (this->getIndex() == '-')
	{
		this->_server->getChannelByName(this->_commandTokens[1])->setSizeMax(-1);
		return ;
	}
	if (this->_commandTokens.size() == 3)
		return ;
	if(this->getIndex() == '+')
		this->_server->getChannelByName(this->_commandTokens[1])->setSizeMax(stringToInt(this->_commandTokens[3]));
}
