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

# GCC
CC := gcc

# Flex
FLEX := flex

# Bison
BISON := bison

# rules

prebuild: build_flex build_bison

all: build

build: build_flex build_bison
	@ $(CC) -g $(SRCDIR)/$(PROJ_NAME).tab.c -I $(INCDIR) -o $(BINDIR)/$(PROJ_NAME).exe 

build_flex:
	@ $(FLEX) -o $(SRCDIR)/$(PROJ_NAME).lex.c $(GENDIR)/$(PROJ_NAME).l

build_bison:
	@ $(BISON) -v -t -o $(SRCDIR)/$(PROJ_NAME).tab.c --header=$(INCDIR)/$(PROJ_NAME).tab.h $(GENDIR)/$(PROJ_NAME).y