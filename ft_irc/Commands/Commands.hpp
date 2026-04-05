#pragma once

#include <string>
#include <vector>
#include "../Server.hpp"

# define BUFFER_SIZE 150

class Server;
class Messages;
class Channel;
class Client;

class Commands
{
	private :
		Messages*					_messages;
		Server* 					_server;
		Client*						_client;
		Client*						_botClient;
		int							_clientFd;
		std::vector<std::string>	_commandTokens;
		char						_index;
		std::vector<char>			_optionList;

	public :
		Commands(Server *s, Client *c, int clientFd, std::vector<std::string> commandTokens, Messages msg);
		~Commands();

		void						executeCommandLine();
		bool						doesChannelExist(std::string channelName);
		void						handleConnectionCommands();

		char						getIndex();
		void						setIndex(char operand);

		// commands
		void						handlePassCommand();
		void						handleUserCommand();
		void						handleNickCommand();
		void						handlePrivmsgCommand();
		void						handleNoticeCommand();
		void						handleJoinCommand();
		void						handleQuitCommand();
		void						handleInviteCommand();
		void						handleKickCommand();
		void						handlePartCommand();
		void						handleTopicCommand();
		// mode
		void						handleModeCommand();
		void						handleModeOnChannel();
		// mode on
		void						setChannelInviteOnlyMode(); //i
		void						setChannelRestrictTopicMode(); //t
		void						setChannelKeyMode(); //k
		void						setChannelOperatorMode(); //o
		void						setChannelLimitMode(); //l
		int							validateModeParameter();
		char						findModePrefix();
		void						splitModeOptionFlags();
		int							stringToInt(std::string &s);
		int							validateModeTargetUser();
		//utils
		Channel *					rplToAllChan();
		std::string					buildJoinedMessage(int line);
		void						leaveMultipleChannels();
		void						createOrJoinChannel(std::string channelName, std::string key);
		bool						isClientOnChannel();

		void 						initializeBotClient();
};
