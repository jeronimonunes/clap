#ifndef CLAP_POSIX_PARSER_HH
#define CLAP_POSIX_PARSER_HH

#include "./Parser.hh"

using namespace Clap;
using namespace std;

namespace Clap
{
class POSIXParser : public Parser
{
public:
	POSIXParser(char label);
	virtual std::string getFormattedLabel() const;
	virtual void parseParam(int argc, char **argv, const std::vector<bool> &unused);
	virtual void parseFlag(int argc, char **argv, const std::vector<bool> &unused);
};
} // namespace Clap
#endif
