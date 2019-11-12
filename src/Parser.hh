#ifndef CLAP_PARSER_HH
#define CLAP_PARSER_HH

#include <vector>
#include <string>
namespace Clap
{
class Parser
{

public:
	virtual std::vector<std::string> parseParam(int argc, char **argv, std::vector<bool> &unused) = 0;
	virtual bool parseFlag(int argc, char **argv, std::vector<bool> &unused) = 0;
	virtual std::string getFormattedLabel() const = 0;
	friend std::ostream &operator<<(std::ostream &os, const Parser &x);
};
} // namespace Clap
#endif
