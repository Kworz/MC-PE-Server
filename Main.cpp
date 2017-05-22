#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>

#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "PacketPriority.h"
#include "RakNetVersion.h"
#include "BitStream.h"

#include "Util.h"
#include "Server.h"
#include "consolecommands.h"

#define MAX_CLIENTS 20
#define TPS 20
#define SERVER_NAME "MC++SERVER"

using namespace std;

int playerCount;
int tps[20] = { 20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20 };

int main(void)
{
	//Hello wurld

	printf("Starting %s\n", SERVER_NAME);
	printf("RakNet Protocol : %d\n", RAKNET_PROTOCOL_VERSION);
	printf("MCPE Version : [%s]%s\n", MCPE_PROTOCOL, MCPE_VERSION);
	printf("Maximum player count : %d\n", MAX_CLIENTS);


	thread server([] { Packets::InvokeServer(19132, "0.0.0.0", 20, "MC++ testserver");  });
	thread CommandHandler([] { ConsoleCommands::HandleCommands(); });

	server.join();
	CommandHandler.join();

	while (1);

}
