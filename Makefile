CXXFLAGS = -g -Wall -Wextra

.PHONY: all
all: Testfile

HList.o: HList.cpp HList.h
	$(CXX) $(CXXFLAGS) -c HList.cpp -o HList.o

Testfile: HList.o Testfile.cpp
	$(CXX) $(CXXFLAGS) Testfile.cpp HList.o -o Testfile