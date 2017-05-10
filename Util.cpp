#include <string>
#include <sstream>

using namespace std;

string processHex(int dec)
{
	int rem;
	ostringstream sout;
	const char *hex = "0123456789ABCDEF";
	while (dec > 0) 
	{
		rem = dec % 16;
		sout << hex[rem];
		dec = dec / 16;
	}
	std::string s(sout.str());
	std::reverse(s.begin(), s.end());

	return s;
}
