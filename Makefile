SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .cpp .h .d .o

CXX      := g++
CXXFLAGS := -O2 -std=c++2a -Wall -Werror -MMD -MP
LDFLAGS  := -fstack-protector-all -O2 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

TOPDIR   := $(shell pwd)
SRCDIR   := src
BUILDDIR := $(TOPDIR)/build
INCDIRS  := $(shell find $(SRCDIR) -type d)

SRCS := $(shell find $(SRCDIR) -name "*.cpp")
OBJS := $(SRCS:%.cpp=$(BUILDDIR)/%.o)
DEPS := $(OBJS:.o=.d)

TARGET := Prog

all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	cd $(BUILDDIR) && ./$(TARGET)

clean:
	rm -r $(BUILDDIR)

-include $(DEPS)

.PHONY: clean
.PHONY: run