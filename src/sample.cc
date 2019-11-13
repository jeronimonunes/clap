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

	vector<bool> test(0, true);
	bool success = true;
	vector<bool> unused = program.parse(argc, argv);
	for(int i = 0; i < argc; i++) {
		if(unused[i]) {
			cerr << "Unrecognized option: " << argv[i] << endl;
			success = false;
		}
	}
	if(success) {
		cerr << program << endl;
		return 0;
	} else {
		cerr << "Use --help to get info about how to set options" << endl;
		return -1;
	}
}
