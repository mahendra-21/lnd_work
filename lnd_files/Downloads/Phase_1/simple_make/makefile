

app: main.o display.o message.o 
	gcc -o app main.o display.o message.o

main.o: main.c header.h
	gcc -c main.c

diaplay.o: display.c header.h
	gcc -c display.c

message.o:  message.c header.h
	gcc -c message.c

clean:
	rm *.o
	rm app
