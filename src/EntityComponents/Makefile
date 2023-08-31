SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .cpp .h .o

CXX       := g++
TOP_DIR		:= /home/hjortur/Documents/Gits/Shooter
BIN_DIR   := $(TOP_DIR)/bin
OBJ_DIR   := $(BIN_DIR)/obj
CURR_DIR  := $(notdir $(shell pwd))
OBJ_FILES := $(patsubst %.cpp, $(OBJ_DIR)/$(CURR_DIR)/%.o, $(wildcard *.cpp))
INC_DIRS  := -I$(CURR_DIR) -I$(SFML_DIR)/include
CPP_FLAGS  = -O3 -std=c++17 -Wall -Werror

$(shell mkdir -p $(OBJ_DIR)/$(CURR_DIR))

all: $(OBJ_FILES)

include $(SOURCES:.cpp=.d)

# compile
$(OBJ_DIR)/$(CURR_DIR)/%.o: %.cpp %.h
	$(CXX) $(CPP_FLAGS) $(INC_DIRS) -c $< -o $@

%.d: %.cpp
	@set -e && rm -f $@ && $(CPP) -MM $(CPPFLAGS) $< > $@.$$$$ $(LDFLAGS) && sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@ && rm -f $@.$$$$