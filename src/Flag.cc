#include "./Flag.hh"

using namespace Clap;
using namespace std;

Flag::Flag(const string &description) : Option(description)
{
	this->wasSet = false;
};

void Flag::parse(int argc, char **argv, std::vector<bool> &unused)
{
	for (auto parser : this->parsers)
	{
		if (parser->parseFlag(argc, argv, unused))
		{
			wasSet = true;
			break;
		}
	}
};

bool Flag::isSet() const
{
	return this->wasSet;
}

void Flag::print(std::ostream &os) const
{
	auto itr = this->parsers.begin();
	if (itr != this->parsers.end())
	{
		const Parser *parser = *itr;
		os << "\t" << *parser;
		for (itr++; itr != this->parsers.end(); itr++)
		{
			const Parser *parser = *itr;
			os << ", " << *parser;
		}
		os << "\t\t" << this->description;
	}
}
