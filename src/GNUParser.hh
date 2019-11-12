#ifndef CLAP_GNU_PARSER_HH
#define CLAP_GNU_PARSER_HH

#include "./Parser.hh"

namespace Clap
{
class GNUParser : public Parser
{
public:
	GNUParser(std::string label);
	virtual std::string getFormattedLabel() const;
	virtual void parseParam(int argc, char **argv, const std::vector<bool> &unused);
	virtual void parseFlag(int argc, char **argv, const std::vector<bool> &unused);
};
} // namespace Clap
#endif
