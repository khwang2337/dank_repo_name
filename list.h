typedef struct song_node {
    char artist[256];
    char name[256];
    struct song_node *next;
}song_node;

void print_list(song_node * list);

void print_eList(song_node * list[]);
//print the entire list

song_node * insert_front(song_node * list, char name[], char artist[]);
//insert nodes at the front

song_node * insert_order(song_node * list, char name[], char artist[]);
//insert nodes in order

song_node * find_song (song_node * list , char songname[]);
//find and return a pointer to an individual song based on song name

song_node * find_artist(song_node * list , char artname[]);
//find and return a pointer to the first song of an artist based on artist name

//song_node * find_random(song_node * list, int lim);
//Return a pointer to random element in the list 
//This function was turned into a helper function called shuffle

song_node * remove_by_name (char songname[256],song_node * list);
//void remove_point(song_node * list, song_node * target);
//remove a single node from the list

song_node * free_list(song_node * list);
//free the entire list
