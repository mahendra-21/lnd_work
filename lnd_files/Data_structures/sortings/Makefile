HDIR = header
SDIR = source
ODIR = object

CC = gcc
CFLAGS = -g -I $(HDIR) -Wall

HDR  = header.h
HEAD = $(patsubst %, $(HDIR)/%, $(HDR))

SOURCES := $(shell find $(SDIR) -name "*.c")
OBJECTS := $(patsubst $(SDIR)%.c, $(ODIR)%.o, $(SOURCES))

.PHONY: all clean

all : sort

$(ODIR)/%.o : $(SDIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c -o $@ $<

sort : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^


clean :
	rm -f sort $(ODIR)/*.o
