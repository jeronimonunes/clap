#ifndef CLAP_POSIX_PARSER_HH
#define CLAP_POSIX_PARSER_HH

#include "./Parser.hh"

using namespace Clap;
using namespace std;

namespace Clap
{
class POSIXParser : public Parser
{
private:
	char label;

public:
	POSIXParser(char label);
	virtual std::string getFormattedLabel() const;
	virtual std::vector<std::string> parseParam(int argc, char **argv, std::vector<bool> &unused);
	virtual bool parseFlag(int argc, char **argv, std::vector<bool> &unused);
};
} // namespace Clap
#endif
