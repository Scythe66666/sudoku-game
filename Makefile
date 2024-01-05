CCFLAGS = -Wall -Werror -g
LDFLAGS = -lm

a.out : main.c read_data.o sudoku.o
	gcc $(CCFLAGS)  main.c read_data.c sudoku.c $(LDFLAGS) 

sudoku.o: sudoku.c sudoku.h
	gcc -c $(CCFLAGS) sudoku.c $(LDFLAGS)

read_data.o: read_data.c 
	gcc -c $(CCFLAGS) read_data.c


