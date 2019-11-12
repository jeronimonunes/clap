#include "./Program.hh"

using namespace std;
using namespace Clap;

Program::Program(const string &title, const string &version, const string &description)
{
	this->title = title;
	this->version = version;
	this->description = description;
};

void Program::addArgument(Argument &param)
{
	this->arguments.push_back(param);
};

bool Program::parse(int argc, char **argv)
{
	vector<bool> unused(argc, true);
	for (auto itr = this->arguments.begin(); itr != this->arguments.end(); itr++)
	{
		Argument &argument = *itr;
		argument.parse(argc, argv, unused);
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
	   << "DESCRIPTION:" << endl
	   << "\t " << x.description << endl
	   << endl
	   << "Arguments:" << endl;
	for (auto itr = x.arguments.begin(); itr != x.arguments.end(); itr++)
	{
		os << *itr << endl;
	}
	return os;
}
} // namespace Clap
