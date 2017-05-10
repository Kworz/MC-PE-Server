#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "PacketPriority.h"
#include "RakNetVersion.h"
#include "Util.h"

#define SERVER_PORT 19132
#define MAX_CLIENTS 20
#define TPS 20
#define SERVER_NAME "MC++SERVER"
#define MCPE_PROTOCOL "107"
#define MCPE_VERSION "1.0.7" //Major-Minor-Patch

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
	
	//Raknet stuff
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::Packet *packet;
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	peer->Startup(MAX_CLIENTS, &sd, 1);

	if(peer->IsActive())
	{
		printf("Started listening on 0.0.0.0:%d\n", SERVER_PORT);

		peer->SetMaximumIncomingConnections(MAX_CLIENTS);

		//Motd
		std::ostringstream motdstream;
		motdstream << "MCPE;" << SERVER_NAME << ";" << MCPE_PROTOCOL << ";" << MCPE_VERSION << ";0;" << MAX_CLIENTS;

		string message = motdstream.str();

		//Adding size of packet (fk u raknet)
		message.insert(message.begin(), message.size());
		message.insert(message.begin(), 0x00);

		peer->SetOfflinePingResponse(message.c_str(), message.size());
		//peer->InitializeSecurity("MHYwEAYHKoZIzj0CAQYFK4EEACIDYgAEDEKneqEvcqUqqFMM1HM1A4zWjJC+I8Y+aKzG5dl+6wNOHHQ4NmG2PEXRJYhujyodFH+wO0dEr4GM1WoaWog8xsYQ6mQJAC0eVpBM96spUB1eMN56+BwlJ4H3Qx4TAvAs", "MB8CAQAwEAYHKoZIzj0CAQYFK4EEACIECDAGAgEBBAEB");

		//infinite loop + tps
		while (1)
		{
			for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive())
			{
				switch(packet->data[0])
				{
					case 0x00:
					{
						printf("[%s]null case\n", processHex(packet->data[0]));
						break;
					}
					case ID_UNCONNECTED_PING:
					{
						break;
					}
					case ID_NEW_INCOMING_CONNECTION:
					{
						printf("Player(%s) tried to join server (packet inc connexion)\n", packet->systemAddress.ToString());
					}
					default: 
					{
						printf("[0x%s]%s\n", processHex(packet->data[0]).c_str(), processHex(packet->data[1]).c_str());
						
						break;
					}
				}
			}

			Sleep(1000 / TPS);
		}
	}
	else
	{
		printf("Error while binding Port:%d\n", SERVER_PORT);
		system("pause");
	}
}
