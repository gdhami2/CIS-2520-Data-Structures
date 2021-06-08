#Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99

#inlcude files directory
INCLUDES = -Iinclude

#Directories with source code, object files and binary
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/

SOURCE = $(SRCDIR)stack.c
OBJS = $(OBJDIR)stack.o $(OBJDIR)linkedListAPI.o

PROGNAME = $(BINDIR)main


program: $(OBJS) $(OBJDIR)main.o
	$(CC) $(OBJS) $(OBJDIR)main.o -o $(PROGNAME)


$(OBJDIR)stack.o: $(SRCDIR)stack.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)stack.c -o $(OBJDIR)stack.o

$(OBJDIR)linkedListAPI.o : $(SRCDIR)linkedListAPI.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@


$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)main.c -o $(OBJDIR)main.o

clean:
	@rm $(OBJDIR)*.o $(PROGNAME)
