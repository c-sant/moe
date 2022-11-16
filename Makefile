# project name

PROJ_NAME = moe

# paths

# generators folder
GENDIR := ./generators

# C source files
SRCDIR := ./src

# C header files
INCDIR := ./include

# Output binaries dir
BINDIR := ./bin

# Flex
FLEX := D:/msys64/usr/bin/flex.exe

# Bison
BISON := D:/msys64/usr/bin/bison.exe

# rules

all: build_flex build_bison

build_flex:
	@ $(FLEX) -o $(SRCDIR)/$(PROJ_NAME).lex.c $(GENDIR)/$(PROJ_NAME).l

build_bison:
	@ $(BISON) -v -t -o $(SRCDIR)/$(PROJ_NAME).tab.c --header=$(INCDIR)/$(PROJ_NAME).tab.h $(GENDIR)/$(PROJ_NAME).y