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

all : assign4

$(ODIR)/%.o : $(SDIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c -o $@ $<

assign4 : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -pthread


clean :
	rm -f assign4 $(ODIR)/*.o
