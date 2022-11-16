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

# rules

all: build_flex build_bison

build_flex:
	@ flex -o $(SRCDIR)/$(PROJ_NAME).lex.c $(GENDIR)/$(PROJ_NAME).l

build_bison:
	@ bison -v -t -o $(SRCDIR)/$(PROJ_NAME).tab.c --header=$(INCDIR)/$(PROJ_NAME).tab.h $(GENDIR)/$(PROJ_NAME).y