#ifndef CLAP_PARAM_HH
#define CLAP_PARAM_HH

#include "./Option.hh"

namespace Clap
{
class Param : public Option
{
private:
	bool optional;
	std::string type;
	std::string defaultValue;
	std::vector<std::string> values;

public:
	Param(const std::string &description, bool optional, const std::string &type, const std::string &defaultValue = "");
	virtual void parse(int argc, char **argv, std::vector<bool> &unused);
	virtual void print(std::ostream& os) const;
};
} // namespace Clap
#endif
