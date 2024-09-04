# CSE30 Makefile
# 
# EXE - objects we want to build
# OBJ - ojects we want to compile (from c)
# 
# We provide a phony target clean to rm all the .o files
# 
# Run make to run with warnings
# Run make WARN= to run without warnings
# Run make DEBUG= to run without debug
# Run make DEBUG= WARN= to run without debug and warnings
# Run make clean to clean objects

EXE = lookup 
all: $(EXE)
HEAD     = node.h Version.h
OBJ      = lookup.o Cnode_lookup.o Cinsert_node.o load_table.o \
           print_info.o delete_table.o Chash.o hash.o node_lookup.o \
           insert_node.o 
ASM      = hash.S

# special libraries
LIB	     = libpa3.a
LIBFLAGS =-L ./ $(LIB)

CC       = gcc
DEBUG    = -g
WARN     = -Wall -Wextra -Wformat-security
CFLAGS   = -I. -std=gnu11 $(DEBUG) $(WARN) -O0
AR       = ar
ARFLAGS  = -rvs

.PHONY: clean

# some flags to use with assembler tools
ASLIST  = -Wa,-adhln
ASFLAGS =

$(OBJ): $(HEAD)


# specify how to assemble a .S file
%.o : %.S
	$(CC) $(CFLAGS) $(ASFLAGS) -c -o $@ $<

$(EXE):	$(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFLAGS)

clean:
	rm -f $(EXE) $(OBJ)
