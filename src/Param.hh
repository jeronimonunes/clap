#ifndef CLAP_PARAM_HH
#define CLAP_PARAM_HH

#include "./Argument.hh"

namespace Clap
{
class Param : public Argument
{
private:
	bool optional;
	std::string type;
	std::string defaultValue;

public:
	Param(const std::string &description, bool optional, const std::string &type, const std::string &defaultValue = "");
	virtual void parse(int argc, char **argv, const std::vector<bool> &unused);
	virtual void print(std::ostream& os) const;
};
} // namespace Clap
#endif
