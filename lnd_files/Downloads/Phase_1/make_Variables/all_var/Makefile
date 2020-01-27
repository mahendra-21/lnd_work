
simple:= first									#simple expanded variable

#immediate set
IMMEDIATE := $(simple) Immediate				

#lazy set
recursive = $(simple) recursive						#recursively expanded variable


simple := second

#Set if 
IFSET = defined
IFSET ?= not defined earlier, so defined now

 
IFNSET ?= defined justnow						#shorthand variable

#Append set
APPEND = First									#Variable to append more text
APPEND += plus		
APPEND += second


ref := a.o b.o c.o								#substitution reference
sub := $(ref:.o=.c) 


all :
	@echo "simple : "$(simple)
	@echo "Immediate : "$(IMMEDIATE)
	@echo "recursive : "$(recursive)
	@echo "IFSET : "$(IFSET)
	@echo "IFNSET : "$(IFNSET)
	@echo "APPEND : "$(APPEND)
	@echo "SUBSTITUTION : "$(sub)

