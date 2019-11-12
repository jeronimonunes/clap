#include "./POSIXParser.hh"

using namespace Clap;
using namespace std;

POSIXParser::POSIXParser(const char label) : Parser({label}) {}

void POSIXParser::parseParam(int argc, char **argv, const std::vector<bool> &unused)
{
}

void POSIXParser::parseFlag(int argc, char **argv, const std::vector<bool> &unused)
{
}

string POSIXParser::getFormattedLabel() const {
	return "-" + this->label;
}
