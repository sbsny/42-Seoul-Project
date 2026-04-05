#include <iostream>
#include <sys/socket.h>
#include "Channel.hpp"
#include <iostream>
#include <sys/socket.h>

Channel::Channel(std::string name, Client* c): _name(name), _creator(c), _key(),
											_topic(), _usersByFd(), _operatorsByFd(),
											_channelPassword(), _maxSize(10),
											_inviteOnly(false), _invitedNicks()
{
	initializeBotClient();
	this->addUser(c, c->getSocketFd());
	this->addOperator(c, c->getSocketFd());
	this->addUser(this->_botClient, this->_botClient->getSocketFd());
	this->addOperator(this->_botClient, this->_botClient->getSocketFd());
}

Channel::Channel(std::string name,  Client* c, std::string key): _name(name), _creator(c), _key(key),
																_topic(), _usersByFd(), _operatorsByFd(),
																_channelPassword(), _maxSize(10),
																_inviteOnly(false), _invitedNicks()
{
	initializeBotClient();
	this->addUser(c, c->getSocketFd());
	this->addOperator(c, c->getSocketFd());
	this->addUser(this->_botClient, this->_botClient->getSocketFd());
	this->addOperator(this->_botClient, this->_botClient->getSocketFd());
}

Channel::~Channel()
{
	delete this->_botClient;
}

Channel*	Channel::operator=(Channel const *c)
{
	this->_name = c->_name;
	this->_creator = c->_creator;
	this->_key = c->_key;
	this->_topic = c->_topic;
	this->_usersByFd = c->_usersByFd;
	this->_operatorsByFd = c->_operatorsByFd;
	this->_channelPassword = c->_channelPassword;
	return (this);
}

void						Channel::initializeBotClient()
{
	this->_botClient = new Client();

	this->_botClient->setNickname("42Bot1");
	this->_botClient->setUsername("42Bot2");
	this->_botClient->setRealName("42Bot3");
	this->_botClient->setPasswordState();
	this->_botClient->setSocketFd(0);

}

void	Channel::displayUsers()
{
	for (std::map<int, Client *>::iterator it = this->_usersByFd.begin(); it != this->_usersByFd.end(); it++)
	{
		if (!it->second->getNickname().empty())
			std::cout << "- " << ((it->second->getNickname().empty()) ? it->second->getUsername() : it->second->getNickname()) << std::endl;
	}
}

void	Channel::displayOperators()
{
	for (std::map<int, Client *>::iterator it = this->_operatorsByFd.begin(); it != this->_operatorsByFd.end(); it++)
	{
		if (!it->second->getNickname().empty())
			std::cout << "- " << ((it->second->getNickname().empty()) ? it->second->getUsername() : it->second->getNickname()) << std::endl;
	}
}

bool	Channel::isUserInChannelByFd(int user)
{
	for (std::map<int, Client*>::iterator it = this->_usersByFd.begin(); it != this->_usersByFd.end(); it++)
		if (it->first == user)
			return (true);
	return (false);
}

void	Channel::broadcastMessage(int senderFd, std::string msg)
{
	for (std::map<int, Client*>::iterator it = this->_usersByFd.begin(); it != this->_usersByFd.end(); it++)
		if (it->first != senderFd && it->first != 0)
			send(it->first, msg.c_str(), msg.size(), 0);
}

bool	Channel::isOperator(int fd)
{
	for (std::map<int, Client *>::iterator itop = this->_operatorsByFd.begin(); itop != this->_operatorsByFd.end(); itop++)
	{
		if (itop->first == fd)
			return (true);
	}
	return (false);
}

int		Channel::countUsersInChannel()
{
	int	i = 0;
	for (std::map<int, Client*>::iterator it = this->_usersByFd.begin(); it != this->_usersByFd.end(); it++)
		i++;
	return (i);
}

bool	Channel::isInvited(std::string nickname)
{
	if (!this->_invitedNicks.empty())
	{
		for (std::vector<std::string>::iterator it = this->_invitedNicks.begin(); it != this->_invitedNicks.end(); it++)
		{
			if (*it == nickname)
				return (true);
		}
	}
	return (false);
}

std::string	Channel::getName()
{
	return (this->_name);
}

void		Channel::setName(std::string name)
{
	this->_name = name;
}

std::map<int, Client*>	Channel::getUsersByFd()
{
	return (this->_usersByFd);
}

void					Channel::addUser(Client *cl, int clientFd)
{
	if (this->_inviteOnly && !this->isInvited(cl->getNickname()))
		return ;
	this->_usersByFd.insert(std::pair<int, Client*>(clientFd, cl));
}

void					Channel::removeUser(std::string username)
{
	for (std::map<int, Client *>::iterator it = this->_usersByFd.begin(); it != this->_usersByFd.end(); it++)
	{
		if (it->second->getUsername() == username || it->second->getNickname() == username)
		{
			if (isInvited(it->second->getNickname()))
			{
				this->removeInvitedNick(username);
			}
			this->_usersByFd.erase(it->first);
			return ;
		}
	}
}

std::map<int, Client*>	Channel::getOperatorsByFd()
{
	return (this->_operatorsByFd);
}

void					Channel::addOperator(Client *cl, int clientFd)
{
	this->_operatorsByFd.insert(std::pair<int, Client*>(clientFd, cl));
}

void					Channel::removeOperator(std::string username)
{
	for (std::map<int, Client *>::iterator it = this->_operatorsByFd.begin(); it != this->_operatorsByFd.end(); it++)
	{
		if (it->second->getUsername() == username || it->second->getNickname() == username)
		{
			this->_operatorsByFd.erase(it->first);
			return ;
		}
	}
}

std::string	Channel::getTopic() const
{
	return (this->_topic);
}

void		Channel::setTopic(std::string topic)
{
	this->_topic = topic;
}

void		Channel::unsetTopic(std::string topic)
{
	this->_topic = topic;
}

bool		Channel::topicIsSet()
{
	if(this->_topic.empty())
		return false;
	else
		return true;
}

std::string	Channel::getKey() const
{
	return (this->_key);
}

void		Channel::setKey(std::string key)
{
	this->_key = key;
}

int	Channel::getSizeMax() const
{
	return (this->_maxSize);
}

void	Channel::setSizeMax(int size)
{
	this->_maxSize = size;
}

std::vector<std::string>	Channel::getInvitedNicks()
{
	return (this->_invitedNicks);
}

void						Channel::addInvitedNick(std::string nickname)
{
	this->_invitedNicks.push_back(nickname);
}

void						Channel::removeInvitedNick(std::string nickname)
{
	if (!this->_invitedNicks.empty())
	{
		for (std::vector<std::string>::iterator it = this->_invitedNicks.begin(); it != this->_invitedNicks.end(); it++)
		{
			if (*it == nickname)
			{
				this->_invitedNicks.erase(it);
				return ;
			}
		}
	}
}

Client*	Channel::getCreator()
{
	return (this->_creator);
}

bool	Channel::getInviteOnly() const
{
	return this->_inviteOnly;
}

void	Channel::setInviteOnly(bool set){

	this->_inviteOnly = set;
}

bool	Channel::getTopicProtected() const
{
	return this->_topicProtected;
}

void	Channel::setTopicProtected(bool protect)
{
	this->_topicProtected = protect;
}

bool	Channel::isUserInChannelByNickname(std::string nickname)
{
	std::map<int, Client *>::iterator	it = this->_usersByFd.begin();
	for(; it != this->_usersByFd.end(); it++)
	{
		if(nickname == it->second->getNickname())
			return true;
	}
	return false;
}

bool	Channel::isOperator(std::string nickname)
{
	std::map<int, Client *>::iterator	it = this->_operatorsByFd.begin();
	for(; it != this->_operatorsByFd.end(); it++)
	{
		if(nickname == it->second->getNickname())
			return true;
	}
	return false;
}
