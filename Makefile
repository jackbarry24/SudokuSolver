PP := g++

FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -m64 -std=c++11 $(FLAGS)

SRC := src
INC := include
OBJ := objects
EXE := exe

# Initialize the folders for the objects and executables
initialize:
	mkdir $(OBJ) $(EXE)

# Create the singly linked list object
$(OBJ)/include.o: $(SRC)/include.cpp
	$(PP) $(CFLAGS) -c $(SRC)/include.cpp -o $@
	
$(OBJ)/sudoku.o: $(SRC)/sudoku.cpp
	$(PP) $(CFLAGS) -c $(SRC)/sudoku.cpp -o $@
	
# singly linked list objects
sudoku_objs := $(OBJ)/include.o $(OBJ)/sudoku.o

# singly linked list executable and run
sudoku: $(sudoku_objs)
	$(PP) $(CFLAGS) -o $(EXE)/sudoku $(sudoku_objs)
	
# make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
