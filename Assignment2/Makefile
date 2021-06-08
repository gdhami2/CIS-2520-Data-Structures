#Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99

#inlcude files directory
INCLUDES = -Iinclude

#Directories with source code, object files and binary
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/

SOURCE = $(SRCDIR)queue.c $(SRCDIR)patient.c $(SRCDIR)testMain.c
OBJS = $(OBJDIR)queue.o $(OBJDIR)linkedListAPI.o $(OBJDIR)patient.o

PROGNAME = $(BINDIR)main
PROGTEST = $(BINDIR)testmain

program: $(OBJS) $(OBJDIR)main.o
	$(CC) $(OBJS) $(OBJDIR)main.o -o $(PROGNAME)

test: $(OBJS) $(OBJDIR)testmain.o
	$(CC) $(OBJS) $(OBJDIR)testmain.o -o $(PROGTEST)

$(OBJDIR)queue.o: $(SRCDIR)queue.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)queue.c -o $(OBJDIR)queue.o

$(OBJDIR)linkedListAPI.o : $(SRCDIR)linkedListAPI.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)patient.o: $(SRCDIR)patient.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)patient.c -o $(OBJDIR)patient.o

$(OBJDIR)testmain.o: $(SRCDIR)testmain.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)testmain.c -o $(OBJDIR)testmain.o

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)main.c -o $(OBJDIR)main.o

clean:
	@rm $(OBJDIR)*.o $(PROGNAME)
