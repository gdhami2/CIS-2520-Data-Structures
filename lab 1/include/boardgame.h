typedef struct boardgame{
    char *name;
    float price;
    char *brandName;
}boardgame;

/**
 * @param  bg boardgame
 * @return  name of boardgame
 */
char *getbgName(boardgame*bg);
/**
 * @param  bg boardgame
 * @return  price of boardgame
 */
float getbgPrice(boardgame*bg);
/**
 * @param  bg boardgame
 * @return  brand of boardgame
 */
char *getbgBrand(boardgame*bg);
/**
 * @param  Name char
 * @param  price float
 * @param  brand char
 * @return  boargame* Name and price and brand
 */
boardgame *create(char *Name, float price, char *brand);
/**
 * Display a boardgame's name and price and brand
 * @param bg [boardgame]
 */
void printBg(void *bg);