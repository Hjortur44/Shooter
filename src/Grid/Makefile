SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .cpp .h .o

CPP      := g++
TOPDIR	 := /home/hjortur/Documents/Gits/Shooter
BINDIR   := $(TOPDIR)/bin
OBJDIR   := $(BINDIR)/obj
CURRDIR  := $(notdir $(shell pwd))
SRCFILES := $(wildcard *.cpp)
OBJFILES := $(patsubst %.cpp, $(OBJDIR)/$(CURRDIR)/%.o, $(wildcard *.cpp))
INCDIRS  := -I$(CURRDIR) -I$(SFMLDIR)/include
CPPFLAGS := -O3 -std=c++17 -Wall -Werror

$(shell mkdir -p $(OBJDIR)/$(CURRDIR))

all: $(OBJFILES)

include $(SRCFILES:.cpp=.d)

# compile
$(OBJDIR)/$(CURRDIR)/%.o: %.cpp %.h
	$(CPP) $(CPPFLAGS) $(INCDIRS) -c $< -o $@

%.d: %.cpp
	@set -e; \
	rm -f $@; \
	$(CPP) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$