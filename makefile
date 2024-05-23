.PHONY: all clean simulate
.SUFFIXES: .o .d .cpp .h

SRC_DIR := src
OBJ_DIR := obj
TARGET := tally
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX := c++
CPPFLAGS := -I.
CXXFLAGS := -std=c++20 -I .
LDLIBS := 

all: $(TARGET)

$(TARGET): $(OBJ) include/BMDSwitcherAPIDispatch.cpp
	$(CXX) $(CXXFLAGS) -Wl,-rpath,/usr/local/opt/llvm/lib/c++ -framework CoreFoundation $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp makefile | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MM $< > $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)/%.d makefile | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	-rm -rv $(TARGET) $(OBJ_DIR)

simulate:
	(cd /Users/sbn/src/github.com/jonknoll/pyAtemSim/ && python3 ./atem_server.py)

include $(OBJ:.o=.d)