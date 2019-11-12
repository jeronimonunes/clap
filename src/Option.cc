#include "./Option.hh"
#include "./POSIXParser.hh"
#include "./GNUParser.hh"

using namespace std;
using namespace Clap;

Option::Option(const string &description) : description(description){};

Option::~Option() {
	for(auto v : this->parsers) {
		delete v;
	}
}

void Option::addPOSIXParser(char label)
{
	this->parsers.push_back(new POSIXParser(label));
}

void Option::addGNUParser(const std::string& label)
{
	this->parsers.push_back(new GNUParser(label));
}

namespace Clap
{
std::ostream &operator<<(std::ostream &os, const Option &x)
{
	x.print(os);
	return os;
}
} // namespace Clap
