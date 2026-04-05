#include "Commands.hpp"
// mode

void	Commands::handleModeCommand(){

	if (this->_commandTokens.size() == 1)
	{
		this->_messages->sendErrNeedMoreParams(this->_clientFd);
		return;
	}
	if (this->_commandTokens.size() == 2)
		return;
	if (this->_server->doesClientExist(this->_commandTokens[1]))
		return;
	else if (doesChannelExist(this->_commandTokens[1]))
		handleModeOnChannel();
	else
	{
		this->_messages->sendErrNoSuchNick(this->_commandTokens[1], this->_clientFd);
		return ;
	}
}

char	Commands::findModePrefix()
{
	char	c = '\0';

	if(this->_commandTokens[2].size() == 1)
		return c;
	else
	{
		c = this->_commandTokens[2][0];
		if(isalpha(c) || isdigit(c))
			return '\0';
	}
	return c;
}

void		Commands::splitModeOptionFlags()
{
	for(int i = 0; i < (int)this->_commandTokens[2].size(); i++)
	{
		if((i == 0 && (this->_commandTokens[2][0] == '+' || this->_commandTokens[2][0] == '-')))
			continue;
		this->_optionList.push_back(this->_commandTokens[2][i]);
	}
}

int		Commands::stringToInt(std::string &s)
{
	int i = 0;
	std::istringstream(s) >> i;
	return i;
}

int		Commands::validateModeParameter()
{
	if(!doesChannelExist(this->_commandTokens[1])){
		this->_messages->sendErrNoSuchChannel(this->_commandTokens[1], this->_clientFd);
		return 1;
	}
	if(!this->_server->getChannelByName(this->_commandTokens[1])->isUserInChannelByFd(this->_clientFd)) //user not on channel
	{
		this->_messages->sendErrNotOnChannel(this->_client->getNickname(), this->_commandTokens[1], this->_clientFd);
		return 1;
	}
	if(!this->_server->getChannelByName(this->_commandTokens[1])->isOperator(this->_clientFd))
	{
		this->_messages->sendErrChanOpPrivsNeeded(this->_commandTokens[0], this->_clientFd);
		std::cout << " >> " << this->_client->getNickname() << " are not Channel Operator " << std::endl;
		return 1;
	}
	char index = findModePrefix();
	if( index != '+' && index != '-'){
		setIndex('\0');
		return 1;
	}
	this->setIndex(index);
	splitModeOptionFlags();
	if(validateModeTargetUser() == 1)
		return 1;
	return 0;
}
