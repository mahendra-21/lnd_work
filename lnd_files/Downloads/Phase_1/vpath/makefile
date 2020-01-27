vpath %.c src
OBJ = obj/
EXE = exe/

exe:main.o add.o sub.o
	gcc -o $(EXE)exec $(OBJ)main.o $(OBJ)add.o $(OBJ)sub.o

main.o:main.c
	gcc -c $< -o $(OBJ)$@   
        	
add.o:add.c
	gcc -c $< -o $(OBJ)$@

sub.o:sub.c
	gcc -c $< -o $(OBJ)$@

.PHONY:clean
clean:
	rm $(OBJ)*.o
	rm $(EXE)exec

run:
	$(EXE)exec




