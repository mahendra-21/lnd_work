
obj = main.o hello.o display.o 

app : $(obj)
	cc -o app $(obj)
main.o : header.h

hello.o : header.h

display.o : header.h

#.PHONY: clean

clean :
	rm *.o
	rm app
