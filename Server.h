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
	void InvokeServer(int gamePort, char* ipAddr, int maxPlayers, char* serverName);
};