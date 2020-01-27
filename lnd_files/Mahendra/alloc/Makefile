exe = malloc
HDIR = header
SDIR = source
ODIR = object
EDIR = execs

CC = gcc
CFLAGS = -g -I $(HDIR)

HDR  = alloc.h
HEAD = $(patsubst %, $(HDIR)/%, $(HDR))

SOURCES := $(shell find $(SDIR) -name "*.c")
OBJECTS := $(patsubst $(SDIR)%.c, $(ODIR)%.o, $(SOURCES))

.PHONY: all clean

all : $(EDIR)/$(exe)

$(ODIR)/%.o : $(SDIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EDIR)/$(exe) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^


clean :
	rm -f $(exe) $(ODIR)/*.o
