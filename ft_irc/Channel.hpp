#pragma once

#include <map>
#include <string>
#include <vector>
#include "Client.hpp"

class Channel
{
	private:
		std::string					_name;
		Client*						_creator;
		std::string					_key;
		std::string					_topic;
		std::map<int, Client *>		_usersByFd;
		std::map<int, Client *>		_operatorsByFd;
		std::string					_channelPassword;
		int							_maxSize;
		bool						_inviteOnly;
		bool						_topicProtected; //topic
		std::vector<std::string>	_invitedNicks;
		Client*						_botClient;

	public:
		Channel(std::string name, Client* c);
		Channel(std::string name,  Client* c, std::string key);
		virtual	~Channel();

		Channel*	operator=(Channel const *c);

		bool	isUserInChannelByNickname(std::string nickname);
		bool	isOperator(std::string nickname);

		void	displayUsers();
		void	displayOperators();
		bool	isUserInChannelByFd(int user);
		void	broadcastMessage(int senderFd, std::string msg);
		bool	isOperator(int fd);
		int		countUsersInChannel();
		bool	isInvited(std::string nickname);


		std::string					getName();
		void						setName(std::string name);

		std::map<int, Client*>		getUsersByFd();
		void						addUser(Client *cl, int clientFd);
		void						removeUser(std::string username);

		std::map<int, Client*>		getOperatorsByFd();
		void						addOperator(Client *cl, int clientFd);
		void						removeOperator(std::string username);

		std::string					getTopic() const;
		void						setTopic(std::string topic);
		bool						topicIsSet();
		void						unsetTopic(std::string topic);

		std::string					getKey() const;
		void						setKey(std::string key);

		int							getSizeMax() const;
		void						setSizeMax(int size);

		void						setInviteOnly(bool set);
		bool						getInviteOnly() const;

		std::vector<std::string>	getInvitedNicks();
		void						addInvitedNick(std::string nickname);
		void						removeInvitedNick(std::string nickname);

		bool						getTopicProtected() const;
		void						setTopicProtected(bool protect);

		Client*						getCreator();

		void						initializeBotClient();

};
