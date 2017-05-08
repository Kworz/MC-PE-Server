#include <stdio.h>
#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "PacketPriority.h"
#include <string>

#define SERVER_PORT 19132
#define MAX_CLIENTS 20


int main(void)
{
	printf("Starting MC++ PE Server \n");
	
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::Packet *packet;

	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	peer->Startup(MAX_CLIENTS, &sd, 1);

	peer->SetMaximumIncomingConnections(MAX_CLIENTS);

	const char* message = "MCPE;TEST server for PE;107;1.0.7;0;20";

	peer->SetOfflinePingResponse(message, 38);

	while(1)
	{
		for(packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive())
		{
			switch(packet->data[0])
			{
				default:
					//printf("else\n");
					break;
			}
		}
	}
}