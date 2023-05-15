CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17

OBJ = main.o

BIN = main

all: $(BIN)

$(BIN): $(OBJ)
