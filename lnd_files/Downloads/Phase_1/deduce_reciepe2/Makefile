

objects = main.o display.o hello.o wolrd.o

app: $(objects)
	gcc -o $@ $(objects)

main.o : header.h
display.o : header.h
hello.o : header.h
wolrd.o : header.h

clean:
	rm $(objects)
	rm app
