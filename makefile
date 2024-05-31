.PHONY: all clean simulate
.SUFFIXES: .o .d .cpp .h

TARGET := tally
SRC := $(wildcard *.cpp)
OBJ := $(SRC:%.cpp=%.o)

CXX := c++
CXXFLAGS := -std=c++20 -I.
LDLIBS := 

all: $(TARGET)

$(TARGET): $(OBJ) include/BMDSwitcherAPIDispatch.cpp
	$(CXX) $(CXXFLAGS) -Wl,-rpath,/usr/local/opt/llvm/lib/c++ -framework CoreFoundation $^ $(LDLIBS) -o $@

# .cpp.d: makefile
# 	$(CXX) $(CXXFILES) -MM $*.cpp > $*.d

# %.d: %.cpp makefile
# 	$(CXX) $(CXXFLAGS) -MM $< > $@

%.o: %.cpp %.d makefile
	$(CXX) $(CXXFLAGS) -std=c++20 -c $< -o $@

clean:
	@-rm -rv $(TARGET) *.o *.d

simulate:
	(cd /Users/sbn/src/github.com/jonknoll/pyAtemSim/ && python3 ./atem_server.py)

CFString.o: CFString.cpp CFString.h
Discovery.o: Discovery.cpp Discovery.h include/BMDSwitcherAPI.h \
  include/com_ptr.h CFString.h Switcher.h
Listener.o: Listener.cpp Listener.h
Switcher.o: Switcher.cpp Switcher.h include/BMDSwitcherAPI.h \
  include/com_ptr.h SwitcherInput.h Listener.h SwitcherInputIterator.h \
  SwitcherMixEffectBlock.h SwitcherMixEffectBlockIterator.h CFString.h
SwitcherInput.o: SwitcherInput.cpp SwitcherInput.h \
  include/BMDSwitcherAPI.h include/com_ptr.h Listener.h CFString.h
SwitcherInputIterator.o: SwitcherInputIterator.cpp \
  include/BMDSwitcherAPI.h include/com_ptr.h SwitcherInput.h Listener.h \
  SwitcherInputIterator.h
SwitcherMixEffectBlock.o: SwitcherMixEffectBlock.cpp CFString.h \
  SwitcherMixEffectBlock.h include/BMDSwitcherAPI.h include/com_ptr.h \
  Listener.h
SwitcherMixEffectBlockIterator.o: SwitcherMixEffectBlockIterator.cpp \
  include/BMDSwitcherAPI.h include/com_ptr.h SwitcherMixEffectBlock.h \
  Listener.h SwitcherMixEffectBlockIterator.h
main.o: main.cpp include/BMDSwitcherAPI.h include/com_ptr.h Discovery.h \
  CFString.h Switcher.h SwitcherInput.h Listener.h \
  SwitcherMixEffectBlock.h
