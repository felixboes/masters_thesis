LANG = en_US.UTF-8

CPP = g++
CPPFLAGS =-std=c++11 -O3
LIBS = -lgmpxx -lgmp
GCC_LT_4_7 := $(shell expr `$(CPP) -dumpversion | sed -e 's/\.\([0-9][0-9]\)/\1/g' -e 's/\.\([0-9]\)/0\1/g'` \< 407)

ifeq "$(GCC_LT_4_7)" "1"
	CPPFLAGS :=-std=c++0x -O3
endif

.PHONY: clean all
all:
	$(CPP) $(CPPFLAGS) -o number_of_cells.out main.c $(LIBS)

clean:
	rm -f number_of_cells.out
