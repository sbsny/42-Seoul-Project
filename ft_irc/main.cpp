#include "Channel.hpp"
#include "Messages.hpp"
#include "Server.hpp"

bool checkIpAddress(char *port)
{
    int ip;
    for(int i = 0; port[i]; i++)
    {
        if(!isdigit(port[i]))
            return(true);
    }
    ip = atoi(port);
    if (ip <= 0 || ip > 65535)
        return(true);
    return(false);
}

int main(int argc, char **argv)
{
	Server irc;
	Messages msg;

    if (argc != 3)
		msg.errorMsg("Error parameters ");
    if (checkIpAddress(argv[1]) == true)
        msg.errorMsg("Error: port range betwen 0 and 65535");
    irc.createServer(atoi(argv[1]));
	irc.setServerPassword(std::string(argv[2]));
	std::cout << "Waiting for connections" <<  std::endl;
	irc.runServerLoop();
}
