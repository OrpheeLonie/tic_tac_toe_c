CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++2a
CPPFLAGS = -Isrc/

OBJ = main.o \
	  src/tic_tac_toe.o

BIN = main

all: $(BIN)

$(BIN): $(OBJ)
	$(LINK.cc) $^ $(LDLIBS) -o $@

clean:
	$(RM) $(OBJ) $(BIN)

.PHONY: all clean
