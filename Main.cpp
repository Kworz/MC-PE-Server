#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "PacketPriority.h"
#include "RakNetVersion.h"
#include "BitStream.h"

#include "Util.h"
#include "Server.h"

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

	if(Packets::InvokeServer(19132, "0.0.0.0", 20, "MC++ testserver") == 0)
	{
		while (1);
	}
	else
	{
		printf("error");
		while (1);
	}


	/*
	//Raknet stuff
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::Packet *packet;
	RakNet::SocketDescriptor sd(SERVER_PORT, SERVER_IP);

	//Tell raknet to start server on SERVER_PORT
	peer->Startup(MAX_CLIENTS, &sd, 1);

	if(peer->IsActive())
	{

		printf("Started listening on %s:%d\n", SERVER_IP, SERVER_PORT);

		peer->SetMaximumIncomingConnections(MAX_CLIENTS);

		//Motd
		std::ostringstream motdstream;
		motdstream << "MCPE;" << SERVER_NAME << ";" << MCPE_PROTOCOL << ";" << MCPE_VERSION << ";0;" << MAX_CLIENTS;

		string message = motdstream.str();

		//Adding size of packet (fk u raknet)
		message.insert(message.begin(), message.size());
		message.insert(message.begin(), 0x00);

		peer->SetOfflinePingResponse(message.c_str(), message.size());

		//infinite loop + tps
		while (1)
		{
			for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive())
			{
				switch(packet->data[0])
				{
					case 0x00:
					{
						printf("[%s]Null case\n", processHex(packet->data[0]));
						break;
					}
					case ID_UNCONNECTED_PING:
					{
						break;
					}
					case ID_NEW_INCOMING_CONNECTION:
					{
						printf("New Player IP : %s\n", packet->systemAddress.ToString());
					}
					case 0xFE:
					{
						printf("MCPEPacket wrapper handler\n");
						printf("%s\n", packet->data);

						RakNet::BitStream send;

						send.Write((int) 0x02);
						send.Write((int) 1);

						if(peer->Send(&send, IMMEDIATE_PRIORITY, UNRELIABLE, NULL, packet->systemAddress, false, 1) == 0)
						{

						}
						break;
					}
					case 0x15:
					{
						printf("Client %s Disconnected\n", packet->systemAddress.ToString());
						break;
					}
					default: 
					{
						printf("[0x%s]%s\n", processHex(packet->data[0]).c_str(), packet->data);
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
	}
	*/
}
