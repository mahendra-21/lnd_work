SRC=src 

OBJ=obj

FILES=$(wildcard src/*.c)

INPUT=$(patsubst src/%.c, obj/%.o, $(FILES))

CFLAGS= -c -I ./hdr 

GCC=gcc

OUTPUT=app

$(OUTPUT):$(INPUT) 
	$(GCC) -o $@ $^
VPATH = ./hdr
obj/%.o:src/%.c 
	$(GCC) $(CFLAGS) -o $@ $< 

.PHONY:clean

clean:
	rm -f $(OBJ)/*.o $(OUTPUT)
