#ifndef CLAP_OPTION_HH
#define CLAP_OPTION_HH

#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include "./Parser.hh"

namespace Clap
{
class Option
{
protected:
	std::string description;
	std::vector<Parser *> parsers;

public:
	Option(const std::string &description);
	~Option();
	virtual void addPOSIXParser(char label);
	virtual void addGNUParser(const std::string &label);
	virtual void parse(int argc, char **argv, std::vector<bool> &unused) = 0;
	virtual void print(std::ostream &os) const = 0;
	friend std::ostream& operator<<(std::ostream &os, const Option &arg);
};
} // namespace Clap
#endif
