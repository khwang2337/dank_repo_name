typedef struct song_node {
    char artist[256];
    char name[256];
    struct song_node *next;
}song_node;

void print_list(struct song_node * list);

void print_eList(struct song_node * list[]);
//print the entire list

struct song_node * insert_front(struct song_node * list, char name[], char artist[]);
//insert nodes at the front

struct song_node * insert_order(struct song_node * list, char name[], char artist[]);
//insert nodes in order

struct song_node * find_song (struct song_node * list , char songname[]);
//find and return a pointer to an individual song based on song name

struct song_node * find_artist(struct song_node * list , char artname[]);
//find and return a pointer to the first song of an artist based on artist name

struct song_node * find_random(struct song_node * list, int lim);
//Return a pointer to random element in the list.

void remove_point(struct song_node * target);
//remove a single node from the list

struct song_node * free_all(struct song_node * list);
//free the entire list

/*
Then create your array of linked lists for the full program and have the following functions:
Add songs.
Search for a song.
Search for an artist.
Print out all the entries under a certain letter.
Print out all the songs of a certain artist
Print out the entire library.
Shuffle - print out a series of randomly chosen songs.
Delete a song
Delete all the nodes.
*/