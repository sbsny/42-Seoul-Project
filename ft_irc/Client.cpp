#include "Client.hpp"

Client::Client(): _passTry(0), _isPasswordSet(false) {}

Client::~Client() {}

int			Client::getPassAttemptCount()
{
	return (this->_passTry);
}

void		Client::incrementPassAttemptCount()
{
	this->_passTry++;
}

bool		Client::isPasswordSet()
{
	return (this->_isPasswordSet);
}

void		Client::setPasswordState()
{
	if (this->_isPasswordSet == false)
		this->_isPasswordSet = true;
	else
		this->_isPasswordSet = false;
}

std::string Client::getNickname()
{
	return (this->_nickname);
}

void	Client::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}
bool	Client::isNicknameSet()
{
	if (this->_nickname.empty())
		return false;
	else
		return true;
}

// realname
std::string Client::getRealName()
{
	return (this->_realName);
}

void	Client::setRealName(std::string realname)
{
	this->_realName = realname;
}

bool	Client::isRealNameSet()
{
	if (this->_realName.empty())
		return false;
	else
		return true;
}

// username
std::string Client::getUsername()
{
	return (this->_username);
}

void	Client::setUsername(std::string user)
{
	this->_username = user;
}

bool	Client::isUsernameSet()
{
	if (this->_username.empty())
		return false;
	else
		return true;
}

int Client::getSocketFd()
{
	return (this->_socketFd);
}

void Client::setSocketFd(int fd)
{
	this->_socketFd = fd;
}

bool	Client::isRegistrationComplete()
{
	if (isNicknameSet() == true && isPasswordSet() == true && isUsernameSet())
		return true;
	else
		return false;
}
