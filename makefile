tally: src/*.cpp src/*.h include/*
	c++  -framework CoreFoundation -std=c++20 -L/usr/local/opt/llvm/lib/c++ -Wl,-rpath,/usr/local/opt/llvm/lib/c++  -I . src/*.cpp include/BMDSwitcherAPIDispatch.cpp -o tally

PSEUDO: simulate
simulate:
	(cd /Users/sbn/src/github.com/jonknoll/pyAtemSim/ && python3 ./atem_server.py)