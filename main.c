#include "list.c"

int main () { 

    struct song_node *table[26];
    int i;
    for (i = 0; i < 26; i++) {
        table[i] = 0;
    }
    insert_order(table,"Hello","Adele");
    print_eList(table);
    printf("is this working");
    
    return 0;
    
}