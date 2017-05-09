#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "PacketPriority.h"
#include "RakNetVersion.h"

#define SERVER_PORT 19132
#define MAX_CLIENTS 20
#define TPS 20

using namespace std;

int main(void)
{
	//Hello wurld
	printf("Starting MC++ PE Server \n");
	printf("Protocal version : %d.\n", RAKNET_PROTOCOL_VERSION);
	
	//Raknet stuff
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::Packet *packet;
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	peer->Startup(MAX_CLIENTS, &sd, 1);
	peer->SetMaximumIncomingConnections(MAX_CLIENTS);
	
	//Motd
	string message = "MCPE;Blyat;107;1.0.7;0;20";

	//Adding size of packet (fk u raknet)
	message.insert(message.begin(), message.size());
	message.insert(message.begin(), 0x00);

	peer->SetOfflinePingResponse(message.c_str(), message.size());

	//infinite loop + tps
	while(1)
	{
		Sleep(1000 / TPS);
	}
}
