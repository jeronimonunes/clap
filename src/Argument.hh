#ifndef CLAP_ARGUMENT_HH
#define CLAP_ARGUMENT_HH

#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include "./Parser.hh"

namespace Clap
{
class Argument
{
protected:
	std::string description;
	std::vector<Parser *> parsers;
	void addParser(const std::string &label, Parser *parser);

public:
	Argument(const std::string &description);
	~Argument();
	virtual void addPOSIXParser(const std::string &label);
	virtual void addGNUParser(const std::string &label);
	virtual void parse(int argc, char **argv, const std::vector<bool> &unused) = 0;
	virtual void print(std::ostream &os) const = 0;
	friend std::ostream& operator<<(std::ostream &os, const Argument &arg);
};
} // namespace Clap
#endif
