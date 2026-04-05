#include <iostream>
#include <sys/socket.h>
#include "Messages.hpp"
#include <iostream>
#include <sys/socket.h>

Messages::Messages(){}

Messages::~Messages(){}

void	Messages::welcome(Client *clientUser, int clientFd)
{
	std::string responseMessage = ":localhost 001 " + clientUser->getNickname() + "\r\n"
	+ "\"Welcome to the Internet Relay Chat Network " + clientUser->getNickname() + "!" + clientUser->getUsername()
	+ "@localhost" + "\"" + "\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void	Messages::sendErrNoSuchNick(std::string nick, int clientFd) // 401
{
	std::string responseMessage = ":irc.com 401 ERR_NOSUCHNICK " + nick + " :No such nick/channel\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void	Messages::sendErrNoNicknameGiven(int clientFd) // 431
{
	std::string responseMessage = ":irc.com 431 ERR_NONICKNAMEGIVEN :No nickname given\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
	return ;
}

void	Messages::sendErrNicknameInUse(std::string nick, int clientFd) // 433
{
	std::string responseMessage = ":irc.com 433 ERR_NICKNAMEINUSE " + nick + " :Nickname is already in use\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
	return ;
}

void	Messages::sendErrErroneousNickname(std::string nick, int clientFd) // 432
{
	std::string responseMessage = ":irc.com 432 ERR_ERRONEUSNICKNAME " + nick + " :Erroneus nickname\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
	return ;
}


void	Messages::sendErrNeedMoreParams(int clientFd) // 461
{
	std::string responseMessage = ":irc.com 461 ERR_NEEDMOREPARAMS :Not enough parameters given\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void	Messages::sendErrAlreadyRegistered(int clientFd) // 462
{
	std::string responseMessage = ":irc.com 462 ERR_ALREADYREGISTRED :You may not reregister\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void	Messages::sendErrPasswordMismatch(int clientFd) // 464
{
	std::string	responseMessage = ":irc.com 464 ERR_PASSWDMISMATCH :Password incorrect\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void Messages::sendErrNoRecipient(int clientFd) // 411
{
	std::string responseMessage = ":irc.com 411 ERR_NORECIPIENT :No recipient given (<command>)\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void Messages::sendErrNoTextToSend(int clientFd) // 412
{
	std::string responseMessage = ":irc.com 412 ERR_NOTEXTTOSEND :No text to send\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void Messages::sendErrUnknownCommand(std::string cmd, int clientFd) // 421
{
	std::string responseMessage = ":irc.com 421 ERR_UNKNOWNCOMMAND " + cmd + " :Unknown command\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void Messages::sendErrNotRegistered(int clientFd) // 451
{
	std::string responseMessage = ":irc.com 451 ERR_NOTREGISTERED :You have not registered\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
	return;
}

// Channel

void	Messages::sendErrCannotSendToChan(std::string target, int clientFd) //404
{
	std::string responseMessage = ":localhost 404 ERR_CANNOTSENDTOCHAN " + target + " :Cannot send to channel\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}


void Messages::sendErrNoSuchChannel(std::string channel, int clientFd) // 403
{
	std::string responseMessage = ":irc.com 403 ERR_NOSUCHCHANNEL " + channel + " :No such channel\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}
//ERR DIFFERENT
void Messages::sendErrChanOpPrivsNeeded(std::string nick, std::string channel, int clientFd) // 482
{
	std::string responseMessage = ":irc.com 482 ERR_CHANOPRIVSNEEDED " + nick + " " + channel + " :You're not channel operator\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}
void	Messages::sendErrChanOpPrivsNeeded(std::string cmd, int clientFd) // 482
{
	std::string responseMessage = ":irc.com 482 ERR_CHANOPRIVSNEEDED " + cmd + " :Not channel operator\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void	Messages::sendErrNotOnChannel(int clientFd, std::string channelName) // 442
{
	std::string	responseMessage = ":irc.com 442 ERR_NOTONCHANNEL " + channelName + " :You're not on that channel\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void	Messages::sendErrUserOnChannel(int clientFd, std::string nick, std::string channelName) // 443
{
	std::string	responseMessage = ":irc.com 443 ERR_USERONCHANNEL " + channelName + nick + " :is already on channel\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}


void Messages::sendErrUserNotInChannel(std::string nick, std::string channel, int clientFd) // 441
{
	std::string responseMessage = ":irc.com 441 ERR_USERNOTINCHANNEL " + nick + " " + channel + " :They aren't on that channel\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void	Messages::sendErrNotOnChannel(std::string nick, std::string channel, int clientFd) //442
{
	std::string responseMessage = ":localhost 442 ERR_NOTONCHANNEL " + nick + " " + channel + " :You're not on that channel\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

// operator
void	Messages::sendErrNoPrivileges(std::string nick, int clientFd) // 481
{
	std::string responseMessage = "481 " + nick + " :Permission Denied- You're not an IRC operator\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}


//INVITE
void Messages::sendRplInviting(std::string nick, std::string clientUser, std::string invited, std::string channelName, int clientFd)
{
	std::string	responseMessage = ":" + nick + "!" + clientUser + "@localhost" + " 341 " + nick + " " + invited + " " + channelName + "\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void Messages::sendRplInvite(std::string nick, std::string clientUser, std::string invited, std::string channelName, int clientFd)
{
	std::string	responseMessage = ":" + nick + "!" + clientUser + "@localhost" + " INVITE " + invited + " " + channelName + "\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}
//QUIT
void Messages::sendRplQuit(std::string nick, std::string clientUser, std::string reason, Channel *channel)
{
	std::string responseMessage = ":" + nick + "!" + clientUser + "@localhost" + " QUIT :Quit: " + reason + "\r\n";
	channel->broadcastMessage(-1, responseMessage);
}


//PRIVMSG
void Messages::sendRplPrivmsgChannel(std::string nick, std::string channelName, std::string responseMessage, Channel *targetChannel, int clientFd)
{
	std::string outboundMessage = ":" + nick + " PRIVMSG " + channelName + " " + responseMessage + "\r\n";
	targetChannel->broadcastMessage(clientFd, outboundMessage);
}

void Messages::sendRplPrivmsg(std::string nick, std::string channelName, std::string responseMessage, int clientFd)
{
	std::string	outboundMessage = ":" + nick + " PRIVMSG " + channelName + " " + responseMessage + "\r\n";
	send(clientFd, outboundMessage.c_str(), outboundMessage.length(), 0);
}
void Messages::sendRplNotice(std::string nick, std::string channelName, std::string responseMessage, int clientFd)
{
	std::string	outboundMessage = ":" + nick + " NOTICE " + channelName + " " + responseMessage + "\r\n";
	send(clientFd, outboundMessage.c_str(), outboundMessage.length(), 0);
}

//PART
void Messages::sendRplLeftChannel(std::string nick, std::string clientUser, std::string channelArg, int clientFd)
{
	std::string	responseMessage = ":" +  nick + "!" + clientUser + "@localhost " + "PART" + " :" + channelArg + "\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}
//KICK
void Messages::sendRplKick(std::string nick, std::string clientUser, std::string channelName, std::string kickedNick, std::string reason, int clientFd)
{
	std::string	responseMessage = ":" +  nick + "!" + clientUser + "@localhost" + " KICK " + channelName + " " + kickedNick +  " " + reason + "\r\n";

	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}
//TOPIC
void	Messages::sendRplNoTopic(Channel *channel) // 331
{
	std::string	responseMessage = ":irc.com 331 RPL_NOTOPIC " + channel->getName() + " :No topic is set\r\n";
	channel->broadcastMessage(-1, responseMessage);
}

void	Messages::sendRplTopic(Channel *channel) // 332
{
	std::string	responseMessage = ":irc.com 332 RPL_TOPIC " + channel->getName() + " :" + channel->getTopic() + "\r\n";
	channel->broadcastMessage(-1, responseMessage);
}
//JOIN
void	Messages::sendRplJoin(std::string nick, std::string clientUser, std::string channelName, Channel *channel)
{
	std::string	responseMessage = ":" + nick + "!" + clientUser + "@localhost" + " JOIN " + channelName + "\r\n";
	channel->broadcastMessage(-1, responseMessage);
}

void	Messages::sendRplError(std::string nick, std::string clientUser, std::string reason, int clientFd)
{
	std::string	responseMessage = ":" + nick + "!" + clientUser + "@localhost" + " ERROR :" + reason + "\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

//unknown mode
void	Messages::sendErrUnknownModeFlag(std::string cmd, int clientFd) // 501
{
	std::string responseMessage = ":irc.com 501 ERR_UMODUUNKNOWNFLAG " + cmd + " :Unknown mode\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}


void	Messages::sendRplNameReply(Channel *channel, int clientFd) // 353
{
	std::map<int, Client*>	map = channel->getUsersByFd();
	std::string	responseMessage = ":irc.com 353 " + channel->getCreator()->getUsername() + " = " + channel->getName() + " :";
	for (std::map<int, Client*>::iterator it = map.begin(); it != map.end(); it++)
	{
		if (channel->isOperator(it->first))
			responseMessage += "@" + it->second->getNickname() + " ";
		else
			responseMessage += it->second->getNickname() + " ";
	}
	responseMessage += "\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

void	Messages::sendRplEndOfNames(Channel *channel, int clientFd, std::string nickname) // 366
{
	std::string	responseMessage = ":irc.com 366 " + nickname + " " + channel->getName() + " :End of /NAMES list\r\n";
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}
void	Messages::sendErrCannotJoin(int clientFd, std::string channelName, int errorCode) // 471, 473, 474, 475
{
	std::string	mode;
	std::string	type;

	if (errorCode == 471)
	{
		type = " ERR_CHANNELISFULL ";
		mode = "(+l)\r\n";
	}
	else if (errorCode == 473)
	{
		type = " ERR_INVITEONLYCHAN ";
		mode = "(+i)\r\n";
	}
	else
	{
		type = " ERR_BADCHANNELKEY ";
		mode = "(+k)\r\n";
	}

	std::string	responseMessage = ":irc.com " + std::to_string(errorCode) + type + channelName + " :Cannot join channel " + mode;
	send(clientFd, responseMessage.c_str(), responseMessage.length(), 0);
}

// Error responseMessage handling
void	Messages::errorMsg(std::string responseMessage)
{
    std::cout << responseMessage << std::endl;
	exit(EXIT_FAILURE);
}

void	Messages::displayMessageOnServer(std::string const &rawBuffer, int senderFd)
{
	if (rawBuffer == "\n")
		return;
    std::cout << "[Client] Msg sended from client "<< senderFd << " >> " << rawBuffer <<  std::endl;
}
