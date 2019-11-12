all:

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

ifdef OS
   RM = del /Q
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
   endif
endif

# Components of the library.
library-objects = \
	Parser.o \
	GNUParser.o \
	POSIXParser.o \
	Program.o \
	Option.o \
	Param.o \
	Flag.o

library-headers = \
	Parser.hh \
	GNUParser.hh \
	POSIXParser.hh \
	Program.hh \
	Option.hh \
	Param.hh \
	Flag.hh


# To ``make the library'', make all its objects using the implicit rule.
library: $(library-objects)

# Conservatively assume that all the objects depend on all the headers.
$(library-objects): $(library-headers)

# Components of the program.
program = sample.exe


# How to link the program.  The implicit rule covers individual objects.
$(program) : sample.cc $(library-objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Delete all generated files we know about.
clean :
	$(RM) $(library-objects) $(program)

all : library $(program)
