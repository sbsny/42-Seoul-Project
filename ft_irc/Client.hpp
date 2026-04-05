#pragma once
#include <string>

class Commands;

class Client
{
	private :
		int			_socketFd;
		int			_passTry;
		bool		_isPasswordSet;
		std::string	_nickname;
		std::string	_username;
		std::string _realName;

    public :
        Client();
        ~Client();
		std::string	inputBuffer;

		// Utils
		bool		isRegistrationComplete();
		int			getPassAttemptCount();
		void		incrementPassAttemptCount();

		// getters, setters
		std::string getRealName();
		void		setRealName(std::string user);
		bool		isRealNameSet();

		void		setNickname(std::string nickname);
		std::string getNickname();
		bool		isNicknameSet();

		std::string getUsername();
		void		setUsername(std::string user);
		bool		isUsernameSet();

		bool		isPasswordSet();
		void		setPasswordState();

		int 		getSocketFd();
		void 		setSocketFd(int fd);
};
