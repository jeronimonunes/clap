#ifndef CLAP_GNU_PARSER_HH
#define CLAP_GNU_PARSER_HH

#include "./Parser.hh"

namespace Clap
{
class GNUParser : public Parser
{
private:
	const std::string label;

public:
	GNUParser(std::string label);
	virtual std::string getFormattedLabel() const;
	virtual std::vector<std::string> parseParam(int argc, char **argv, std::vector<bool> &unused);
	virtual bool parseFlag(int argc, char **argv, std::vector<bool> &unused);
};
} // namespace Clap
#endif
