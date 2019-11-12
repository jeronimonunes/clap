#ifndef CLAP_FLAG_HH
#define CLAP_FLAG_HH

#include "./Option.hh"

namespace Clap
{
class Flag : public Option
{
private:
	bool wasSet;

public:
	Flag(const std::string &description);
	virtual void parse(int argc, char **argv, const std::vector<bool> &unused);
	virtual bool isSet() const;
	virtual void print(std::ostream& os) const;
};
} // namespace Clap
#endif
