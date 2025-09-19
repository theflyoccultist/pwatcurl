#include "ascii_art_handler.h"
#include <stdio.h>
#include <strings.h>

bool ascii_art_activated(const char *value) {
  if (strcasecmp(value, "yes") == 0) {
    printf("ascii art activated\n");
    return true;
  }
  printf("ascii art is disabled\n");
  return false;
}
