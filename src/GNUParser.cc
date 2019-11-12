#include "./GNUParser.hh"

using namespace Clap;
using namespace std;

GNUParser::GNUParser(string label) : Parser(label) {}

void GNUParser::parseParam(int argc, char **argv, const std::vector<bool> &unused)
{
}

void GNUParser::parseFlag(int argc, char **argv, const std::vector<bool> &unused)
{
}

string GNUParser::getFormattedLabel() const
{
	return "--" + this->label;
}
