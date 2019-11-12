#ifndef CLAP_PARSER_HH
#define CLAP_PARSER_HH

#include <vector>
#include <string>
namespace Clap
{
class Parser
{
protected:
	std::string label;

public:
	Parser(const std::string &label);
	virtual void parseParam(int argc, char **argv, const std::vector<bool> &unused) = 0;
	virtual void parseFlag(int argc, char **argv, const std::vector<bool> &unused) = 0;
	virtual std::string getFormattedLabel() const = 0;
	friend std::ostream &operator<<(std::ostream &os, const Parser &x);
};
} // namespace Clap
#endif
