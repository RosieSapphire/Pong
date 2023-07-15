CC=gcc
CFLAGS=-Ofast -Wall -Wextra
SRC=$(wildcard src/*.c)
INC=-Iinclude
LIB=-lglfw
BIN=pong

default:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN) $(INC) $(LIB)

clean:
	rm -f $(BIN)
