#pragma once

#include <string>
#include "Channel.hpp"
#include "Client.hpp"

class Messages
{
	public :
	Messages();
	~Messages();
	void	welcome(Client *clientUser, int clientFd);
	void	errorMsg(std::string responseMessage);
	void	displayMessageOnServer(std::string const &rawBuffer, int senderFd);

	// NICK ERR
	void	sendErrNoSuchNick(std::string nick, int clientFd);
	void	sendErrNoNicknameGiven(int clientFd);
	void	sendErrNicknameInUse(std::string nick, int clientFd);
	void	sendErrErroneousNickname(std::string nick, int clientFd);

	// PASS & USER ERR
	void	sendErrNeedMoreParams(int clientFd);
	void	sendErrAlreadyRegistered(int clientFd);
	void	sendErrPasswordMismatch(int clientFd);

	// PRIVMSG ERR
	void	sendErrNoRecipient(int clientFd);
	void	sendErrNoTextToSend(int clientFd);
	void	sendErrUnknownCommand(std::string cmd, int clientFd);
	void	sendErrNotRegistered(int clientFd);

	// ERR OPERATOR
	void	sendErrNoPrivileges(std::string nick, int clientFd);

	// ERR CHANNELS
	void	sendErrNoSuchChannel(std::string channel, int clientFd);
	void	sendErrChanOpPrivsNeeded(std::string cmd, int clientFd);
	void 	sendErrChanOpPrivsNeeded(std::string nick, std::string channel, int clientFd);
	void	sendErrUnknownModeFlag(std::string cmd, int clientFd);
	void	sendErrNotOnChannel(std::string nick, std::string channel, int clientFd);
	void	sendErrNotOnChannel(int clientFd, std::string channelName);
	void	sendErrUserNotInChannel(std::string nick, std::string channel, int clientFd);
	void	sendErrCannotSendToChan(std::string target, int clientFd);
	void	sendErrUserOnChannel(int clientFd, std::string nick, std::string channelName);

	// REPLY ERR
	void	sendRplLeftChannel(std::string nick, std::string clientUser, std::string channelArg, int clientFd);
	void 	sendRplKick(std::string nick, std::string clientUser, std::string channel, std::string kickedNick, std::string reason, int clientFd);
	void	sendRplInviting(std::string nick, std::string clientUser, std::string invited, std::string channelName, int clientFd);
	void	sendRplInvite(std::string nick, std::string clientUser, std::string invited, std::string channelName, int clientFd);
	void	sendRplNoTopic(Channel *channel);
	void	sendRplTopic(Channel *channel);
	void	sendRplPrivmsgChannel(std::string nick, std::string channelName, std::string responseMessage, Channel *targetChannel, int clientFd);
	void	sendRplPrivmsg(std::string nick, std::string channelName, std::string responseMessage, int clientFd);
	void	sendRplNotice(std::string nick, std::string channelName, std::string responseMessage, int clientFd);
	void	sendRplQuit(std::string nick, std::string clientUser, std::string reason, Channel *channel);
	void	sendRplJoin(std::string nick, std::string clientUser, std::string channelName, Channel *channel);
	void	sendRplError(std::string nick, std::string clientUser, std::string reason, int clientFd);

	// RPL JOIN ERR
	void	sendRplNameReply(Channel *channel, int clientFd);
	void	sendRplEndOfNames(Channel *channel, int clientFd, std::string nickname);
	void	sendErrCannotJoin(int clientFd, std::string channelName, int errorCode);


};
