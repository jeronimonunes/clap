#include "./Argument.hh"
#include "./POSIXParser.hh"
#include "./GNUParser.hh"

using namespace std;
using namespace Clap;

Argument::Argument(const string &description) : description(description){};

Argument::~Argument() {
	for(auto v : this->parsers) {
		delete v;
	}
}

void Argument::addParser(const std::string& label, Parser *parser)
{
	this->parsers.push_back(parser);
}

void Argument::addPOSIXParser(const std::string& label)
{
	this->addParser(label, new POSIXParser(label));
}

void Argument::addGNUParser(const std::string& label)
{
	this->addParser(label, new GNUParser(label));
}

namespace Clap
{
std::ostream &operator<<(std::ostream &os, const Argument &x)
{
	x.print(os);
	return os;
}
} // namespace Clap
