#include "./Param.hh"

using namespace Clap;
using namespace std;

Param::Param(const std::string &description, bool optional, const std::string &type, const std::string &defaultValue) : Option(description), optional(optional), type(type), defaultValue(defaultValue){};

void Param::parse(int argc, char **argv, std::vector<bool> &unused)
{
	for (auto parser : this->parsers)
	{
		auto results = parser->parseParam(argc, argv, unused);
		for(auto v : results) {
			this->values.push_back(v);
		}
	}
};

void Param::print(ostream &os) const
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
		if (this->optional)
		{
			os << " [" << this->type << "]";
		}
		else
		{
			os << " <" << this->type << ">";
		}
		os << "\t\t" << this->description << ".";
		if (this->defaultValue.size())
		{
			os << " Default: " << this->defaultValue;
		}
	}
}

const std::vector<std::string>& Param::getValues() const {
	return this->values;
}
