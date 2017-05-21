#include <stdio.h>
#include <sstream>
#include <chrono>

#include "RakPeerInterface.h"
#include "RakNetTypes.h"

#define MCPE_PROTOCOL "107"
#define MCPE_VERSION "1.0.7" //Major-Minor-Patch

using namespace std;
using namespace std::chrono;
using namespace RakNet;

namespace Packets
{
	int InvokeServer(int gamePort, char* ipAddr, int maxPlayers, char* serverName)
	{
		high_resolution_clock::time_point timeBefore = high_resolution_clock::now();

		RakPeerInterface *PeerInterface = RakPeerInterface::GetInstance();
		SocketDescriptor SocketDesc(gamePort, ipAddr);
		Packet *packet;

		if(PeerInterface->Startup(maxPlayers, &SocketDesc, 1) == RAKNET_STARTED)
		{
			PeerInterface->SetMaximumIncomingConnections(maxPlayers);

			//MOTD Stuff
			ostringstream motd;
			motd << "MCPE;" << serverName << ";" << MCPE_PROTOCOL << ";" << MCPE_VERSION << ";0;" << maxPlayers;

			string message = motd.str();

			//Adding size of packet (fk u raknet)
			message.insert(message.begin(), message.size());
			message.insert(message.begin(), 0x00);

			PeerInterface->SetOfflinePingResponse(message.c_str(), message.size());

			high_resolution_clock::time_point timeAfter = high_resolution_clock::now();

			auto ExecTime = duration_cast<milliseconds>(timeAfter - timeBefore).count();

			printf("Server Invoked, Took %dms\n", ExecTime);
			printf("Binded server on %s:%d\n", ipAddr, gamePort);

			return 0;
		}
		else
		{
			return 1;
		}
	}
};