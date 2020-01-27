.PHONY : clean

OBJECT = main.o display.o message.o

output : $(OBJECT)
	gcc -o $@ $(OBJECT)

main.o : main.c
display.o message.o : header.h

.PHONY :
clean :
	rm $(OBJECT)
	rm output

