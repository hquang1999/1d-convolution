# Use the C++ compiler to link
LINK.o = $(LINK.cc)
# Flags to compile for the debugger
CXXFLAGS =-Wall -ggdb3

all: runtests

runtests: runtests.o

clean:
	rm -f runtests *.o
