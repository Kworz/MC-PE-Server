#pragma comp
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

char* splitCfgLine(string entry, char splitter);
void loadCfg();
char* getProperty(char* arg);