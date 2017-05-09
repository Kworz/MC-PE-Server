#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "RakNet/RakPeerInterface.h"
#include "RakNet/MessageIdentifiers.h"
#include "RakNet/PacketPriority.h"

#define SERVER_PORT 19132
#define MAX_CLIENTS 20

using namespace std;

int main(void)
{
	vector<int> motd;

	//Hello wurld
	printf("Starting MC++ PE Server \n");
	
	//Raknet stuff
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::Packet *packet;
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	peer->Startup(MAX_CLIENTS, &sd, 1);
	peer->SetMaximumIncomingConnections(MAX_CLIENTS);
	
	string message = "MCPE;Blyat;107;1.0.7;0;20";

	
	message.insert(message.begin(), message.size());
	message.insert(message.begin(), 0x00);

	peer->SetOfflinePingResponse(message.c_str(), message.size());

	while(1)
	{

	}
}
