CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o  $(OBJ)/segTree.o $(OBJ)/matrix.o
HDRS = $(INC)/matrix.hpp $(INC)/segTree.hpp
CFLAGS = -Wall -std=c++11 -c -g -I$(INC)


EXE = $(BIN)/tp3.out

run:$(EXE)
		./$(EXE) 

all:$(EXE)

$(BIN)/tp3.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp3.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/segTree.o: $(HDRS) $(SRC)/segTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/segTree.o $(SRC)/segTree.cpp 

$(OBJ)/matrix.o: $(HDRS) $(SRC)/matrix.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matrix.o $(SRC)/matrix.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out