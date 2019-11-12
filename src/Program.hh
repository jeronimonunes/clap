#ifndef PROGRAM_HH
#define PROGRAM_HH

#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include "./Argument.hh"

namespace Clap
{
class Program
{
private:
	std::string title;
	std::string version;
	std::string description;
	std::vector<std::reference_wrapper<Argument>> arguments;

public:
	Program(const std::string &title, const std::string &version, const std::string &description);
	void addArgument(Argument &argument);
	bool parse(int argc, char **argv);
	friend std::ostream &operator<<(std::ostream &os, const Program &x);
};

} // namespace Clap

#endif
