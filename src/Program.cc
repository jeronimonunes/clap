#include "./Program.hh"

using namespace std;
using namespace Clap;

Program::Program(const string &title, const string &version, const string &description)
{
	this->title = title;
	this->version = version;
	this->description = description;
};

void Program::addOption(Option &param)
{
	this->options.push_back(param);
};

bool Program::parse(int argc, char **argv)
{
	if (argc)
	{
		this->executable = argv[0];
		vector<bool> unused(argc, true);
		unused[0] = false;
		for (auto itr = this->options.begin(); itr != this->options.end(); itr++)
		{
			Option &option = *itr;
			option.parse(argc, argv, unused);
		}
	}
	return true; // TODO
}
namespace Clap
{
std::ostream &operator<<(std::ostream &os, const Program &x)
{
	os << endl
	   << x.title << " " << x.version << endl
	   << endl
	   << "SYNOPSIS:" << endl
	   << "\t" << x.executable << " [OPTION]..." << endl
	   << endl
	   << "DESCRIPTION:" << endl
	   << "\t " << x.description << endl
	   << endl
	   << "OPTIONS:" << endl;
	for (auto itr = x.options.begin(); itr != x.options.end(); itr++)
	{
		os << *itr << endl;
	}
	return os;
}
} // namespace Clap
