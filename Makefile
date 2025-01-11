CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++14 -pedantic -ggdb

main: main.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp

run: main
	./main.exe
