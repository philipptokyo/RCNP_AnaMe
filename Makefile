CXX       = /usr/bin/g++
CXXFLAGS  = -fPIC -Wall -Wextra -Wno-unused-result -Weffc++ -isystem$(shell root-config --incdir) -std=c++11 -march=native
LDFLAGS   = $(shell root-config --libs) -L./
SOFLAGS   = -fPIC -shared

.PHONY: all
all: aname

aname: main.o
	@echo "Buildung 'analyzer aname'..."
	@$(CXX) -o $@ $^ $(LDFLAGS) -lz -O3

.PHONY: clean
clean: 
	@rm -f *.o aname

%.o: %.cxx Makefile
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

%.o: %.h %.cxx Makefile
	@$(CXX) -c -o $@ $< $(CXXFLAGS)
