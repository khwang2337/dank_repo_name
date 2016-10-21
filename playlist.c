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

void add_song (song_node *table[26], char name[256], char artist[256]) {
  int index = (artist[0]|' ') - 'a';
  table[index] = insert_order(table[index],name,artist);
}

song_node * search_song (song_node *table[26], char name[256]) {
  int n;
  song_node *song = 0;
  for(n = 0; n < 26; n++) {
    song = find_song(table[n],name);
    if (song) { 
        return song;
    }
  }
  return NULL;
}

song_node * search_artist (song_node *table[26], char artist[256]) {
  int n;
  song_node *song = 0;
  for(n = 0; n < 26; n++) {
    song = find_artist(table[n],artist);
    if (song) { 
        return song;
    }
  }
  return NULL;
}

void print_under_letter (song_node *table[26], char c) {
  int index = (c|' ') - 'a';
  print_list(table[index]);
}

void print_by_author (song_node *table[26], char artist[256]) {
  int index = (artist[0]|' ') - 'a';
  print_list(table[index]);
}

void print_entire_library (song_node *table[26]) {
  int n;
  for(n = 0; n < 26; n++) {
    print_list(table[n]);
  }
}

song_node * shuffle (song_node *table[26], int lim) {
  int random = rand() % lim;
  int dex = 0;
  song_node *ret = table[dex];
  int ctr;
  while (random) {
    if (ret && ret->next) {
      ret = ret->next;
    }
    else {
      (dex < 26) ? (dex++) : (dex = 0);
      ctr = 0;
      while (! table[dex]) {
        if (ctr == 26) {
          return NULL;
        }
        (dex < 26) ? (dex++) : (dex = 0);
        ctr++;
      }
      ret = table[dex];
    }
    random--;
  }
  return ret;
}

void shuffled_playlist(song_node *table[26], int num) {
  song_node *random;
  printf("\nRandomized Playlist of %d songs:\n",num);
  while (num) {
    random = shuffle(table,250);
    printf("%s by %s\n", random->name, random->artist);  
    num--;
  }
}

void delete_song (song_node *table[26], char name[256], char artist[256]) { 
  int index = (artist[0]|' ') - 'a';
  printf("Song has been removed.\n");
  table[index] = remove_by_name(name,table[index]);
}

void free_library (song_node *table[26]) {
  int n;
  for(n = 0; n < 26; n++) {
    table[n]=free_list(table[n]);
  }
}