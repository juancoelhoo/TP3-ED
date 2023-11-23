CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/SegTree.o
HDRS = $(INC)/SegTree.hpp
CFLAGS = -Wall -std=c++11 -c -g -I$(INC)

EXE = $(BIN)/tp3.out

run:  $(EXE)

all: $(BIN)/tp3.out

$(BIN)/tp3.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp3.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/SegTree.o: $(HDRS) $(SRC)/SegTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/SegTree.o $(SRC)/SegTree.cpp  

clean:
	rm -f $(EXE) $(OBJS) gmon.out