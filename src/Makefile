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
	Argument.o \
	Param.o \
	Flag.o

library-headers = \
	Parser.hh \
	GNUParser.hh \
	POSIXParser.hh \
	Program.hh \
	Argument.hh \
	Param.hh \
	Flag.hh


# To ``make the library'', make all its objects using the implicit rule.
library: $(library-objects)

# Conservatively assume that all the objects depend on all the headers.
$(library-objects): $(library-headers)

# Components of the program.
program = sample.exe
program-objects = sample.o

# Conservatively assume all the program source files depend on all the library
# headers.  You can change this if it is not the case.
$(program-objects) : $(library-headers)

# How to link the program.  The implicit rule covers individual objects.
$(program) : $(program-objects) $(library-objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Delete all generated files we know about.
clean :
	$(RM) $(library-objects) $(program-objects) $(program)

all : library $(program)
