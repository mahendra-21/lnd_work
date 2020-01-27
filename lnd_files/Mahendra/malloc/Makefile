HDIR = ./Header
SDIR = Source
ODIR = Object
LDIR = ./Library
EDIR = Exec

lib = liballoc.a
HDR  = alloc.h

CC = gcc
CFLAGS = -g -I$(HDIR)

HEAD = $(patsubst %, $(HDIR)/%, $(HDR))

OBJ = $(patsubst $(SDIR)/%.c, %.c, $(wildcard $(SDIR)/*.c))
_OBJ = $(patsubst %.c, $(ODIR)/%.o, $(OBJ))

OUT = $(patsubst Test/%.c, $(EDIR)/%.out, $(wildcard Test/*.c))

all : $(LDIR)/$(lib) $(OUT) 

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(LDIR)/$(lib) : $(_OBJ)
	ar -rcs $@ $^

Exec/tcase_1.out: Test/tcase_1.c
	$(CC) -static -o $@ $(CFLAGS) $< -L$(LDIR) -lalloc

Exec/tcase_2.out: Test/tcase_2.c
	$(CC) -static -o $@ $(CFLAGS) $< -L$(LDIR) -lalloc

Exec/tcase_3.out: Test/tcase_3.c
	$(CC) -static -o $@ $(CFLAGS) $< -L$(LDIR) -lalloc

.PHONY : clean  

clean:
	rm -rf $(ODIR)/*.o $(EDIR)/* $(LDIR)/*
