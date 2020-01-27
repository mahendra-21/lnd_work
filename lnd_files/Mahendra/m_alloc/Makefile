IDIR = ./include
LDIR = ./library
ODIR = ./object
EDIR = ./executables
TDIR = ./testfiles

lib = liballoc.a
inc  = alloc.h

CC = gcc
CFLAGS = -g -Wall -I$(IDIR)
MAC = -DDEF=0

OBJ = $(patsubst $(LDIR)/%.c, %.c, $(wildcard $(LDIR)/*.c))
_OBJ = $(patsubst %.c, $(ODIR)/%.o, $(OBJ))

OUT = $(patsubst $(TDIR)/%.c, $(EDIR)/%.out, $(wildcard $(TDIR)/*.c))

all: $(ODIR)/$(lib) $(OUT) 

$(ODIR)/%.o: $(LDIR)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< 

$(ODIR)/$(lib): $(_OBJ)
	ar -rcs $@ $^

$(EDIR)/tcase_01.out: $(TDIR)/tcase_01.c
	$(CC) -static -o $@ $(MAC) $(CFLAGS) $< -L$(ODIR) -lalloc

$(EDIR)/tcase_02.out: $(TDIR)/tcase_02.c
	$(CC) -static -o $@ $(MAC) $(CFLAGS) $< -L$(ODIR) -lalloc

$(EDIR)/tcase_03.out: $(TDIR)/tcase_03.c
	$(CC) -static -o $@ $(CFLAGS) $< -L$(ODIR) -lalloc

$(EDIR)/tcase_04.out: $(TDIR)/tcase_04.c
	$(CC) -static -o $@ $(MAC) $(CFLAGS) $< -L$(ODIR) -lalloc

.PHONY : clean  

clean:
	rm -rf $(ODIR)/* $(EDIR)/*.out 
