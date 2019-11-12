# CLAP

A Command Line Arguments parser for C++

This library was inspired by [Apache Commons CLI](http://commons.apache.org/proper/commons-cli/index.html)

This library supports two types of options:

* POSIX like options: `tar -zxvf foo.tar.gz`
* GNU like options: `du --human-readable --max-depth=1`

## Integration

This library can be used with any c++ project since it only uses the std library. It is composed of .hh and .cc files, which mean that you will have to compile and link the code to your program. I recomend adding this repo as a submodule of your git repo.

## Usage

You will first need to define a Program object, which will contain a title, version and description. These information are only used to build the help message:

```cpp
Program program("Software title", "1.0.0", "What does this software do");
```

Then you can add options for latter be parsed. The arguments can be Params or Flags. Flags have boolean state, they eighter have been set or haven't; while Params must have a value.

### Adding a Flag

```cpp
Flag help = Flag("\t\tShow this info message");
help.addPOSIXParser('h');
help.addGNUParser("help");
program.addOption(help);
```

The Flag constructor receives the description of the parameter. The ```addPOSIXParser(<label>)``` makes the flag enabable via -h.

### Adding a Param

```cpp
Param firstParam("Detailed description of a", true, "boolean", "true");
firstParam.addPOSIXParser('a');
firstParam.addGNUParser("activate-a");
program.addOption(firstParam);
```

The Param constructor also gets the description as first argument but it also receives a bool for wether the option is optional or not, a type for its value (human readable) and a default value. All the information is used only to provide the help message and will not cause any exception or errors.

### Parsing

The parsing phase is to be implemented
