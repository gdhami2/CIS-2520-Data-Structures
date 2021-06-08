#include <stdio.h>
#include <stdlib.h>

typedef struct book {
    double price;
    char *name;
} Book;

/**
 * Create book title and price
 * @param  title char
 * @param  price double
 * @return Book* title and price
 */
Book* createBook( char * title, double price );
/**
 * Get price of book
 * @param  b Book
 * @return   Double price
 */
double getPrice( Book * b );
/**
 * Return a books name
 * @param  b Book
 * @return   char* string of name
 */
char* getName( Book *b );
/**
 * Display a book's name and price.
 * @param b [Book]
 */
void printBook( void * b );