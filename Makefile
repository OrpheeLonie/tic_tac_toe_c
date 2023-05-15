CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++2a

OBJ = main.o

BIN = main

all: $(BIN)

$(BIN): $(OBJ)
	$(LINK.cc) $^ $(LDLIBS) -o $@

clean:
	$(RM) $(OBJ) $(BIN)

.PHONY: all clean
