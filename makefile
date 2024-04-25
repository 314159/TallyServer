SRC_DIR := src
OBJ_DIR := obj
TARGET := tally
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

CXX := c++
CPPFLAGS := -I. -MMD -MP
CXXFLAGS := -std=c++20 -I .
LDLIBS := 

all: $(TARGET)
.PHONY: all clean simulate

$(TARGET): $(OBJ) include/BMDSwitcherAPIDispatch.cpp
	$(CXX) $(CXXFLAGS) -Wl,-rpath,/usr/local/opt/llvm/lib/c++ -framework CoreFoundation $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MM $< > $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)/%.d | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	mkdir -p $@

clean:
	-rm -rv $(TARGET) $(OBJ_DIR)

simulate:
	(cd /Users/sbn/src/github.com/jonknoll/pyAtemSim/ && python3 ./atem_server.py)

-include $(OBJ:.o=.d)