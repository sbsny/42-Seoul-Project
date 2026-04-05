#pragma once

#include <algorithm>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <map>
#include <netinet/in.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

#include "Messages.hpp"
#include "Channel.hpp"
#include "Commands/Commands.hpp"
#include "Client.hpp"

class Commands;
class Channel;
class Messages;

class Server
{
	private:
		struct sockaddr_in			_addr;
		int							_addrLen;
		int							_serverFd;
		fd_set						_fdSet;
		std::string					_serverPassword;
		std::vector<std::string>	_commandList;
		std::vector<int>			_disconnectedFds;
		std::map<int, Client*>		_clientsByFd;
		std::map<std::string, Channel*>	_channelsByName;
		std::map<int, Client> _users;

	public:
		Server();
		virtual	~Server();

		// Server setup
		void						createServer(int port);
		void						runServerLoop();
		void						acceptClient();
		std::string					receiveMessage(int *len, int senderFd, bool &err);
		void						dispatchToCommands(int senderFd, std::string buf);
		void 						handleCommandLine(int senderFd, std::string buf);

		// Utils
		int							countCharInStringBuffer(std::string buf, char c);
		std::vector<std::string>	splitBufferByDelimiter(std::string buf, char charset);

		void						disconnectClients();
		void						disconnectEmptyChannels();
		bool						isIrcCommand(std::string str);
		bool 						doesClientExist(std::string nick);

		// getters, setters
		std::vector<int>			getDisconnectedFds();
		void						addDisconnectedFd(int fdUsersDc);

		std::string					getServerPassword();
		void						setServerPassword(std::string pwd);

		std::map<int, Client*>		getClientsByFd();
		void						addClientByFd(int fd, Client *user);
		Client *					getClient(std::string nick);

		std::map<std::string, Channel*>	getChannelsByName();
		Channel*						getChannelByName(std::string chann);
		void							addChannel(Channel *c);

};
