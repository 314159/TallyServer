.PHONY: all clean simulate
.SUFFIXES: .o .d .cpp .h

TARGET := tally
SRC := $(wildcard *.cpp)
OBJ := $(SRC:%.cpp=%.o)

CXX := c++
CPPFLAGS := -I.
CXXFLAGS := -std=c++20 -I .
LDLIBS := 

all: $(TARGET)

$(TARGET): $(OBJ) include/BMDSwitcherAPIDispatch.cpp
	$(CXX) $(CXXFLAGS) -Wl,-rpath,/usr/local/opt/llvm/lib/c++ -framework CoreFoundation $^ $(LDLIBS) -o $@

%.d: %.cpp makefile
	$(CXX) $(CXXFLAGS) -MM $< > $@

%.o: %.cpp %.d makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -rv $(TARGET) *.o *.d

simulate:
	(cd /Users/sbn/src/github.com/jonknoll/pyAtemSim/ && python3 ./atem_server.py)

include $(OBJ:.o=.d)