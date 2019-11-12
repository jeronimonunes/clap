#include "./Parser.hh"

using namespace std;
using namespace Clap;

Parser::Parser(const string& label) : label(label) {}

namespace Clap
{
std::ostream &operator<<(std::ostream &os, const Parser &x)
{
	return os << x.getFormattedLabel();
}
} // namespace Clap
