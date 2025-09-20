#include "ascii_art_handler.h"
#include <stdio.h>
#include <string.h>

bool ascii_art_activated(const char *value) {
  return (strcmp(value, "yes") == 0);
}

typedef struct {
  const char *mood;
  const char *path;
} mood_file_t;

mood_file_t ascii_table[] = {{"bubbly", "./assets/bubbly_ascii.txt"},
                             {"goth", "./assets/goth_ascii.txt"},
                             {"shy", "./assets/shy_ascii.txt"},
                             {NULL, NULL}};

const char *get_ascii_path(const char *mood) {
  for (int i = 0; ascii_table[i].mood; i++) {
    if (strcmp(ascii_table[i].mood, mood) == 0) {
      return ascii_table[i].path;
    }
  }
  return NULL;
}

int display_ascii(const char *mood) {
  const char *path = get_ascii_path(mood);
  if (path) {
    FILE *f = fopen(path, "r");

    if (f == NULL) {
      fprintf(stderr, "Could not load ascii art\n");
      return 1;
    }

    char ch;
    while ((ch = fgetc(f)) != EOF) {
      putchar(ch);
    }

    fclose(f);
  } else {
    fprintf(stderr, "pwatcurl doesn't vibe with '%s'.\n", mood);
    return 1;
  }
  return 0;
}
