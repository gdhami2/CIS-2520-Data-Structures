#Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99

#inlcude files directory
INCLUDES = -Iinclude

#Directories with source code, object files and binary
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/

SOURCE = $(SRCDIR)main.c $(SRCDIR)testmain.c
OBJS = $(OBJDIR)HashTableAPI.o

PROGNAME = $(BINDIR)main
PROGTEST = $(BINDIR)testmain

all: program test

program: $(OBJS) $(OBJDIR)main.o
	$(CC) $(OBJS) $(OBJDIR)main.o -o $(PROGNAME)

test: $(OBJS) $(OBJDIR)testmain.o
	$(CC) $(OBJS) $(OBJDIR)testmain.o -o $(PROGTEST)


$(OBJDIR)HashTableAPI.o : $(SRCDIR)HashTableAPI.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)testmain.o: $(SRCDIR)testmain.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)testmain.c -o $(OBJDIR)testmain.o

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)main.c -o $(OBJDIR)main.o

clean:
	@rm $(OBJDIR)*.o $(PROGNAME) $(PROGTEST)
