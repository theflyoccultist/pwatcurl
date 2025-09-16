#include "conf_file_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO:  Make parsing more forgiving (ignore whitespace around "mood = goth",
// and case insensivity)

// TODO: Unknown keys: print a warning, but don't crash.

// TODO: ignore inline comments

// TODO: default values, for example if ascii_art is missing

config_option_t read_config_file(char *path) {
  FILE *fp = fopen(path, "r");
  if (!fp) {
    perror("fopen()");
    return NULL;
  }

  config_option_t last = NULL;

  char line[256];
  while (fgets(line, sizeof(line), fp)) {
    if (line[0] == '#' || line[0] == ';' || line[0] == '\n')
      continue;

    char key[128], value[128];
    if (sscanf(line, " %127[^=]=%127s", key, value) == 2) {
      config_option_t co = calloc(1, sizeof(*co));
      if (!co) {
        perror("calloc");
        break;
      }
      strncpy(co->key, key, sizeof(co->key) - 1);
      strncpy(co->value, value, sizeof(co->value) - 1);
      co->prev = last;
      last = co;
    } else {
      fprintf(stderr, "Invalid line in config: %s", line);
    }
  }
  fclose(fp);
  return last;
}

void destroy_config_file(config_option_t co) {
  while (co) {
    config_option_t prev = co->prev;
    free(co);
    co = prev;
  }
}
