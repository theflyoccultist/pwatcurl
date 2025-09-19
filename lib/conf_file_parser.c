#include "conf_file_parser.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// trim all whitespace
void trim(char *s) {
  char *d = s;
  do {
    while (*d == ' ') {
      ++d;
    }
  } while ((*s++ = *d++));
}

// convert to lowercase
void to_lowercase(char *s) {
  for (int i = 0; s[i]; i++) {
    s[i] = tolower(s[i]);
  }
}

// ignore inline comments
void strip_inline_comments(char *s, const char *comment) {
  char *pos = strstr(s, comment);
  if (pos)
    *pos = '\0';
}

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

    trim(line);
    to_lowercase(line);
    strip_inline_comments(line, "#");

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
