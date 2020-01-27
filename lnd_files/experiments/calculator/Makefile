all : calculator

calculator : main.o add.o sub.o mul.o div.o my_atoi.o validation.o
	gcc ./object/*.o -o calculator
main.o : ./source/main.c
	gcc -I header -c ./source/main.c -o ./object/main.o
add.o : ./source/_add.c
	gcc -I header -c ./source/_add.c -o ./object/add.o
sub.o : ./source/_sub.c
	gcc -I header -c ./source/_sub.c -o ./object/sub.o  
mul.o : ./source/_mul.c
	gcc -I header  -c ./source/_mul.c -o ./object/mul.o
div.o : ./source/_div.c
	gcc -I header -c ./source/_div.c -o ./object/div.o
my_atoi.o : source/my_atoi.c
	gcc -I header -c ./source/my_atoi.c -o ./object/my_atoi.o
validation.o : ./source/validation.c
	gcc -I header -c ./source/validation.c -o ./object/validation.o
