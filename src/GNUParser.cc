#include "./GNUParser.hh"
#include <iostream>
using namespace Clap;
using namespace std;

GNUParser::GNUParser(string label) : label(label) {}

vector<string> GNUParser::parseParam(int argc, char **argv, std::vector<bool> &unused)
{
	vector<string> values;
	for (unsigned int i = 1; i < argc; i++)
	{
		if (unused[i])
		{
			if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2])
			{
				string arg = argv[i];
				auto found = arg.find_first_of("\n\r\t =");
				string name;
				if (found != string::npos)
				{
					name = arg.substr(2, found - 2);
				}
				else
				{
					name = arg.substr(2);
				}
				if (name == this->label)
				{
					string value;
					unused[i] = false;
					if (found != string::npos)
					{
						value = arg.substr(found + 1);
					}
					else
					{
						value = argv[++i];
						unused[i] = false;
					}
					values.push_back(value);
				}
			}
		}
	}
	return values;
}

bool GNUParser::parseFlag(int argc, char **argv, std::vector<bool> &unused)
{
	for (unsigned int i = 1; i < argc; i++)
	{
		if (unused[i])
		{
			if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2])
			{
				string arg = argv[i];
				if (arg.substr(2) == this->label)
				{
					unused[i] = false;
					return true;
				}
			}
		}
	}
	return false;
}

string GNUParser::getFormattedLabel() const
{
	return "--" + this->label;
}
