CXX       := g++
TOP_DIR		:= /home/hjortur/Documents/Gits/Shooter
SRC_DIR		:= src
BIN_DIR   := bin
OBJ_DIR   := $(BIN_DIR)/obj
CPP_DIRS  := $(wildcard $(SRC_DIR)/*)
SH_FILE   := app
CPP_FILES := $(shell find $(SRC_DIR) -name "*.cpp")
H_FILES   := $(shell find $(SRC_DIR) -name "*.h")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_FILES))

LIB_DIR   := -L$(SFML_DIR)/lib
LD_FLAGS  := -O3 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

$(shell mkdir -p $(OBJ_DIR))

all: compile $(BIN_DIR)/$(SH_FILE)

$(BIN_DIR)/$(SH_FILE): $(OBJ_FILES)
	$(CXX) $(LIB_DIR) $(OBJ_FILES) -o $(BIN_DIR)/$(SH_FILE) $(LD_FLAGS)

compile:
	$(MAKE) -C /home/hjortur/Documents/Gits/Shooter/src/Components
	$(MAKE) -C /home/hjortur/Documents/Gits/Shooter/src/Core
	$(MAKE) -C /home/hjortur/Documents/Gits/Shooter/src/Entities
	$(MAKE) -C /home/hjortur/Documents/Gits/Shooter/src/Launcher
	$(MAKE) -C /home/hjortur/Documents/Gits/Shooter/src/Managers
	$(MAKE) -C /home/hjortur/Documents/Gits/Shooter/src/Math
	$(MAKE) -C /home/hjortur/Documents/Gits/Shooter/src/MemoryPools
	$(MAKE) -C /home/hjortur/Documents/Gits/Shooter/src/Scenes
	$(MAKE) -C /home/hjortur/Documents/Gits/Shooter/src/Systems

run:
	cd $(BIN_DIR) && ./$(SH_FILE)

clean:
	rm -r $(BIN_DIR)