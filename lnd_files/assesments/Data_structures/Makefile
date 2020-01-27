HDIR = header
SDIR = source
ODIR = object

CC = gcc
CFLAGS = -I $(HDIR) -Wall -Werror

HDR  = header.h
HEAD = $(patsubst %, $(HDIR)/%, $(HDR))

SOURCES := $(shell find $(SDIR) -name "*.c")
OBJECTS := $(patsubst $(SDIR)%.c, $(ODIR)%.o, $(SOURCES))

.PHONY: all clean

all : del_root 

$(ODIR)/%.o : $(SDIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c -o $@ $<

del_root : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^


clean :
	rm -f del_root $(ODIR)/*.o
