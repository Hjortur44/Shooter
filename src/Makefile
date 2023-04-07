CXX       := g++
TOP_DIR   := ~/Desktop/Shooter
SRC_DIR   := $(TOP_DIR)/src
BIN_DIR   := $(TOP_DIR)/bin
OBJ_DIR   := $(BIN_DIR)/obj
SH_FILE   := app
CPP_FILES := $(shell find $(SRC_DIR) -wholename "**/*.cpp")
H_FILES   := $(shell find $(SRC_DIR) -wholename "**/*.h")
OBJ_FILES := $(patsubst %.o,%.cpp,$(CPP_FILES))
CPP_FLAGS := -O3 -std=c++17
LD_FLAGS  := -O3 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(SH_FILE)

$(SH_FILE): $(OBJ_DIR)
	$(CXX) $(CPP_FLAGS) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@ $(LD_FLAGS)

## compiling, linking and creating executable.
$(OBJ_DIR): $(CPP_FILES) $(H_FILES) Makefile
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	cd $(OBJ_DIR) && $(CXX) -c $(CPP_FLAGS) $(CPP_FILES)

run:
	cd $(BIN_DIR) && ./$(SH_FILE)

clean:
	rm $(BIN_DIR)/$(SH_FILE) $(OBJ_DIR)/*.o