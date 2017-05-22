#include <stdio.h>
#include <iostream>

using namespace std;

namespace ConsoleCommands
{
	void HandleCommands()
	{

		char command[256];

		cin.get(command, 256);

		printf(command);

		if(command == "quit")
		{
			//Only closes current thread
			exit(0);
		}
	}
};