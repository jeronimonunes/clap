#include "./Program.hh"
#include "./Param.hh"
#include "./Flag.hh"
#include <iostream>

using namespace std;
using namespace Clap;

int main(int argc, char **argv)
{
	Program program("Software title", "1.0.0", "What does this software do");

	Param firstParam("Perform calculation of cristalyte size", true, "boolean", "true");
	firstParam.addPOSIXParser('a');
	firstParam.addGNUParser("activate-a");
	program.addOption(firstParam);

	Flag help = Flag("\t\tShow this info message");
	help.addPOSIXParser('h');
	help.addGNUParser("help");
	program.addOption(help);

	if (program.parse(argc, argv))
	{
		cout << program << endl;
		return 0;
	}
	else
	{
		cout << "Unrecognized parameters use " << argv[0] << " --help to get help" << endl;
		return -1;
	}
}
