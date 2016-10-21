#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PLAYLIST
#define PLAYLIST
#include "playlist.h"
#endif

#ifndef LIST
#define LIST
#include "list.h"
#endif

int main () {
	
    struct song_node *table[26];
    int i;
    for (i = 0; i < 26; i++) {
        table[i] = 0;
    }
    printf("TESTING BASIC LIST FUNCTIONS...\n");
    printf("Inserting Hello by Adele...\n");
    //add_song(table,"Hello","Adele");
    table[0] = insert_order(table[0],"Hello","Adele");
    printf("Inserting Megolovania by Toby Fox...\n");
    //add_song(table,"Megolovania","Toby Fox");
    table[19] = insert_front(table[19],"Megolovania","Toby Fox");
    printf("Checking to see if they have been inserted...\n");
    //print_list(table[0]); //prints Hello by Adele
    print_eList(table);
    
    printf("\nFinding Megolovania under Slot A...\n");
    if (find_song (table[0],"Megolovania") == NULL) { 
        printf ("Cannot find song with that name.\n"); 
    }//can't find
    printf("Finding Megolovania under Slot M...\n");
    find_song (table[19],"Megolovania"); //can find
    
    printf("\nFinding Adele under Slot A...\n");
    find_artist(table[0],"Adele"); 
    printf("Finding Adele under Slot M...\n");
    if (find_artist(table[19],"Adele") == NULL) { 
        printf ("Cannot find artist with that name.\n"); 
    } 
    
    printf("\nRemoving Megolovania from Slot M...And reprinting the entire table...\n");
    table[19] = remove_by_name("Megolovania",table[19]); 
    print_eList(table);
    printf("Freeing everything under Slot A...And then printing slot A again...\n\n");
    table[0]=free_list(table[0]);
    print_eList(table);
    
    printf("_____________________________________________________________________________\n"); 
    printf("TESTING PLAYLIST FUNCTIONS...\n"); 
    printf("Inserting Hello by Adele...\n");
    add_song(table,"Hello","Adele");
    printf("Inserting Rolling in the Deep by Adele...\n");
    add_song(table,"Rolling in the Deep","Adele");
    printf("Inserting Littleroot Theme by Emerald...\n");
    add_song(table,"Littleroot Theme","Emerald");
    printf("Inserting Cooler Than Me by Mike Posner\n");
    add_song(table,"Cooler Than Me","Mike Posner");
    printf("Inserting Megolovania by Toby Fox...\n");
    add_song(table,"Megolovania","Toby Fox");
    printf("Printing entire library:\n");
    print_entire_library(table);
    
    printf("\nLooking for all songs under the letter A...\n"); 
    print_under_letter(table,'a');
    printf("Looking for all songs by Adele...\n"); 
    print_by_author(table,"Adele");
    
    printf("\nLooking for Littleroot Theme...\n");
    search_song(table,"Littleroot Theme");
    printf("Looking for Bigroot Theme...\n");
    if (search_song(table,"Bigroot Theme") == NULL) { 
        printf ("Cannot find song with that name.\n"); 
    }
    printf("Looking for Mike Posner...\n"); 
    search_artist(table,"Mike Posner"); 
    printf("Looking for Pike Mosner...\n");
    if (search_artist(table,"Pike Mosner") == NULL) { 
        printf ("Cannot find artist with that name.\n\n"); 
    }
    
    printf("Removing Megolovania...\n"); 
    delete_song(table,"Megolovania","Toby Fox"); 
    printf("Printing entire library...\n");
    print_entire_library(table);
    printf("\nList shuffle!!\n"); 
    shuffled_playlist(table, 10);
    printf("\nFreeing entire library...And then printing the entire library again...\n\n");
    free_library(table);
    print_entire_library(table);
    
    return 0;
    
}