#ifndef LIST
#define LIST
#include "list.h"
#endif

void add_song (song_node *table[26], char name[256], char artist[256]);
//Add songs.

song_node * search_song (song_node *table[26], char name[256]);
//Search for a song.

song_node * search_artist (song_node *table[26], char artist[256]);
//Search for an artist.

void print_under_letter (song_node *table[26], char c);
//Print out all the entries under a certain letter.

void print_by_author (song_node *table[26], char artist[256]); 
//Print out all the songs of a certain artist

void print_entire_library (song_node *table[26]); 
//Print out the entire library.

song_node * shuffle (song_node *table[26], int lim); 
//helper function for shuffled_playlist

void shuffled_playlist(song_node *table[26], int num);
//Shuffle - print out a series of randomly chosen songs.

void delete_song (song_node *table[26], char name[256], char artist[256]); 
//Delete a song

void free_library (song_node *table[26]);
//Delete all the nodes.