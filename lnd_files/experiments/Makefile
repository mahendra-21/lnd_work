IDIR = header
EDIR = calculator

CC = gcc
CFLAGS = -I$(IDIR) -Wall -Werror

ODIR = object

HE_AD = calculator.h

HEAD = $(patsubst %, $(IDIR)/%, $(HE_AD))

OBJ_ = main.o add.o sub.o mul.o div.o my_atoi.o validation.o
#OBJ_ = *.o
OBJ = $(patsubst %,$(ODIR)/%,$(OBJ_))

$(ODIR)/%.o : source/%.c $(HEAD)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EDIR) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY : clean

clean:
	rm -f $(ODIR)/*.o*
