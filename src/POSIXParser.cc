#include "./POSIXParser.hh"

using namespace Clap;
using namespace std;

POSIXParser::POSIXParser(const char label) : label(label) {}

vector<string> POSIXParser::parseParam(int argc, char **argv, std::vector<bool> &unused)
{
	vector<string> values;
	for (unsigned int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-' && argv[i][1] != '-')
		{
			string arg = argv[i];
			arg = arg.substr(1);
			auto found = arg.find(this->label);
			if (found != string::npos)
			{
				string value;
				unused[i] = false;
				if (i + 1 < argc)
				{
					value = argv[++i];
					unused[i] = false;
				}
				values.push_back(value);
			}
		}
	}
	return values;
}

bool POSIXParser::parseFlag(int argc, char **argv, std::vector<bool> &unused)
{
	for (unsigned int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-' && argv[i][1] != '-')
		{
			for (unsigned int j = 1; argv[i][j]; j++)
			{
				if (argv[i][j] == this->label)
				{
					unused[i] = false;
					return true;
				}
			}
		}
	}
	return false;
}

string POSIXParser::getFormattedLabel() const
{
	return string("-") + this->label;
}
