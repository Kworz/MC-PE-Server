#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

string validKey[24] = { "motd", "server-port" ,"server-port","viewdistance", "white-list","achievements","announce-player-achievements","spawn-protection","max-players", "allow-flight", "spawn-animals", "spawn-mobs", "gamemode", "force-gamemode", "hardcore", "pvp", "difficulty", "generator-settings", "level-name", "level-seed", "leveltype", "auto-save", "force-ressources" };
string defaultVal[24] = { "Default MC++PEServer Motd", "19132", "0.0.0.0", "10", "off", "on", "on", "16", "20", "off", "on", "on", "0", "off", "off", "on", "1", "", "world", "", "DEFAULT", "on", "off" };
map<char*, char*> properties;

string* splitCfgLine(string entry, char splitter)
{
	printf("%s\n", entry.c_str());
	std::stringstream  data(entry);
	std::string line;

	int i = 0;
	string test[2];

	while (std::getline(data, line, splitter))
	{
		test[i] = (char*)line.c_str();
		printf("[%d]%s\n", i, test[i]);
		i++;
	}
	return test;
}

void loadCfg()
{
	ifstream config("./server.properties", ios::in);

	if(config)
	{
		string line;
		while(getline(config, line))
		{
			if(line.c_str()[0] == '#')
				continue;

			printf("%s\n", line.c_str());
			//splitCfgLine(line, '=');
			string test2[2];
		}
	}
	else
	{
		printf("Unable to open server.properties (file does not exist) creating one instead...");
	}
}

char* getProperty(char* arg)
{
	char* value;

	value = properties[arg];

	if(value == "")
	{
		int index = validKey->find(arg, 0);
		value = (char*)defaultVal[index].c_str();
	}
	return value;
}