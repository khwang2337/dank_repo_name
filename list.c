#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

//These functions have yet to be tested

void print_list(struct song_node * list) {
  struct song_node * temp = list[n];
  while (temp.next) {
    printf("%s by %s", temp->name, temp->artist);
    temp = temp.next;
  }
} 

void print_eList(struct song_node * list[]) { 
  for(n = 0; n < 26; n++) {
    print_list(list[n]);
  }
}

struct song_node * insert_front(struct song_node * list, char name[], char artist[]) {
  struct song_node *newNode = (struct song_node *)malloc(sizeof(struct song_node));
  newNode->next = list;
  newNode->name = name;
  newNode->artist = artist;
  return newNode;
}

struct song_node * insert_order(struct song_node * list, char name[], char artist[]) {
  struct song_node *newNode = (struct song_node *)malloc(sizeof(struct song_node));
  newNode->name = name;
  newNode->artist = artist;
  while ((strcmp(list->next->artist, artist) == 0 && strcmp(list->next->name, name) > 0) || strcmp(list->next->artist, artist) > 0) {
    list = list->next;
  }
  struct song_node temp = list->next;
  list->next = newNode;
  if (temp) {
    newNode->next = temp;
  } 
}

struct song_node * find_random(struct song_node * list, int lim) {
  struct song_node * first = list;
  int ran = rand() % lim;
  while (ran > 0) {
    if (first->next) {
      first = first->next;
    }
    else {
      first = list;
    }
    ran--;
  }
  return first; 
}

/*
void remove_point(struct song_node * list, struct song_node * target) {
  struct song_node *temp = list->next;
  while (list) {
    if (list == target) {
      list->next = temp;
      free(target);
      return;
    }
    if (temp = target) {
      list->next = temp->next;
      free(target);
      return;
    }
    list = list->next;
    temp = list->next;
  }
}
*/
struct song_node * free_all(struct song_node * list) {
  while (list) {
    free(list);
    if (list->next ) {
      list = list->next;
    }
    else {
      break;
    }
  }
  return list;
}




/* //2berevised
struct node * insert_front( struct node *n, int  d ) {

  struct node *new = (struct node *)malloc(sizeof(struct node));

  new->next = n;
  new->data = d;

  return new;
}

struct node * free_list( struct node *n ) {

  struct node *f = n;
  while ( n ) {
    n = n->next;
    printf("freeing node: %d\n", f->data );
    free(f);
    f = n;    
  }
  return n;
}
*/

/* to be tested!
struct song_node * find_song (struct song_node * list , char songname[]) { 
    struct song_node *temp = list;
    //iterate through the linked list
    while(temp->next) { 
        if (strcmp (songname , temp -> name) == 0) {
          return temp;
        }
    }
    printf ("Cannot find song with that name"); 
    return null;
}
*/

/* to be tested
struct song_node * find_artist(struct song_node * list , char artname[]) { 
    struct song_node *temp = list;
    //iterate through the linked list
    while(temp->next) { 
        if (strcmp (artname , temp -> artist) == 0) {
          return temp;
        }
    }
    printf ("Cannot find song with that artist's name"); 
    return null;
}
*/

