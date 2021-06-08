CC = gcc
	
CFLAGS = -Wall -std=c99 -pedantic
	
	
#inlcude files directory
	
INCLUDES = -Iinclude
	
	
#Directories with source code, object files and binary
	
SRCDIR = src/
	
BINDIR = bin/
	
OBJDIR = obj/
	
	 
	
	
	
PROGNAME = $(BINDIR)main.out
	
	
	
program: $(OBJS) $(OBJDIR)main.o
	
	$(CC) $(OBJDIR)main.o -o $(PROGNAME)
	
	
	
	
$(OBJDIR)main.o: $(SRCDIR)main.c
	
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)main.c -o $(OBJDIR)main.o
	
	
clean:
	
	@rm $(OBJDIR)*.o $(PROGNAME)
