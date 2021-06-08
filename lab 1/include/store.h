typedef struct store{
    void *data;
    void(*printPtr)(void *data);
}store;

/**
 * @param  void *datas for either book struct or boardgame struct
 * @param  function pointer that points to the output function
 * @return  The dynamically created store struct
 */
store *createStore(void *datas, void(*prPtr)(void* info));
/**
 * Displays item in store
 */
void displayStore( store* s );