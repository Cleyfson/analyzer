CC = g++
LIBS = -lm
SRC = src
OBJ = obj
OUT = saidas/*
INC = include
BIN = bin
OBJS = $(OBJ)/tp2.o $(OBJ)/celula.o $(OBJ)/lista.o $(OBJ)/palavra.o
HDRS = $(INC)/celula.hpp $(INC)/lista.hpp $(INC)/palavra.hpp 
CFLAGS = -pg -Wall -c -I$(INC)
# ANALISAMEM = ../analisamem/bin/analisamem

EXE = $(BIN)/tp2

# run: $(EXE)
# 	rm -rf output
# 	mkdir output
# 	$(EXE) -i input/1.tst.i -o output/saida1.txt -m 5 -s 5
# 	$(EXE) -i input/2.tst.i -o output/saida2.txt -m 5 -s 5
# 	$(EXE) -i input/3.tst.i -o output/saida3.txt -m 5 -s 5
# 	$(EXE) -i input/4.tst.i -o output/saida4.txt -m 5 -s 5
# 	$(EXE) -i input/5.tst.i -o output/saida5.txt -m 5 -s 5
# 	$(EXE) -i input/6.tst.i -o output/saida6.txt -m 5 -s 5
# 	$(EXE) -i input/7.tst.i -o output/saida7.txt -m 5 -s 5
# 	$(EXE) -i input/8.tst.i -o output/saida8.txt -m 5 -s 5
# 	$(EXE) -i input/9.tst.i -o output/saida9.txt -m 5 -s 5
# 	$(EXE) -i input/10.tst.i -o output/saida10.txt -m 5 -s 5
# 	$(EXE) -i input/11.tst.i -o output/saida11.txt -m 5 -s 5
# 	$(EXE) -i input/12.tst.i -o output/saida12.txt -m 5 -s 5

all:$(EXE)

$(BIN)/tp2: $(OBJS)
	$(CC) -pg -o $(BIN)/tp2 $(OBJS) $(LIBS)

$(OBJ)/tp2.o: $(HDRS) $(SRC)/tp2.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp2.o $(SRC)/tp2.cpp 	

$(OBJ)/palavra.o: $(HDRS) $(SRC)/palavra.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/palavra.o $(SRC)/palavra.cpp 

$(OBJ)/lista.o: $(HDRS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp 

$(OBJ)/celula.o: $(HDRS) $(SRC)/celula.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/celula.o $(SRC)/celula.cpp 
	
	
clean:
	rm -f  gmon.out $(BIN)/tp2 $(OBJS) $(OUT) 
	rm -rf output
