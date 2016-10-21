#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LIST
#define LIST
#include "list.h"
#endif

void print_list(song_node * list) {
  song_node * temp = list;
  while (temp) {
    printf("%s by %s\n", temp->name, temp->artist);
    temp = temp->next;
  }
} 

void print_eList(song_node * list[]) { 
  int n;
  for(n = 0; n < 26; n++) {
    print_list(list[n]);
  }
}

song_node * insert_front(song_node * list, char name[], char artist[]) {
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  newNode->next = list;
  strcpy(newNode->name, name);
  strcpy(newNode->artist, artist);
  return newNode;
}

song_node * insert_order(song_node * list, char name[], char artist[]) {
  if ( (! list) || ( (strcmp(list->artist, artist) == 0 && strcmp(list->name, name) >= 0 ) || strcmp(list->artist, artist) > 0 ) ) {
    return insert_front(list,name,artist);
  }
  else {
    song_node * hold = list;
    song_node *temp = list->next;
    song_node *newNode = (song_node *)malloc(sizeof(song_node));
    strcpy(newNode->name, name);
    strcpy(newNode->artist, artist);
    while ( temp && ( (strcmp(temp->artist, artist) == 0 && strcmp(temp->name, name) <= 0) || strcmp(temp->artist, artist) < 0) ) {
      list = list->next;
      temp = list->next;
    }
    list->next = newNode;
    newNode->next = temp;
    return hold;
  }
}

/*
  Hello by Adele L
  Rolling in the Deep by Adele
  Littleroot Theme by Emerald
P  Cooler Than Me by Mike Posner
C  Megolovania by Toby Fox
*/

song_node * remove_by_name (char songname[256],song_node * list) { 
  song_node *curr = list;
  song_node *prev;
    while (curr) {
        if (strcmp(curr->name, songname) == 0) {
            if (curr == list) {
                list = curr->next;
            } 
            else {
                prev->next = curr->next;
                return list;
            }
            //printf("HIIIII\n");
            free(curr);
        } 
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return NULL;
}

song_node * free_list(song_node * list) {
  song_node *temp = 0; 
  for (song_node *i = list ; i != 0 ; i = temp) { 
    temp = i -> next;
    free (i); 
  }
}

song_node * find_song (song_node * list , char songname[]) { 
  song_node *i;
  for (i = list; i != 0; i = i->next){
    if (strcmp (songname , i -> name) == 0) {
      printf("Song has been found!\n");
      return i;
    }
  }
  return NULL;
}

song_node * find_artist(song_node * list , char artname[]) { 
  song_node *i;
  for (i = list; i != 0; i = i->next){
    if (strcmp (artname , i -> artist) == 0) {
      printf("Artist has been found!\n");
      return i;
    }
  }
  return NULL;
}
