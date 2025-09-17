#include "../lib/conf_file_parser.h"
#include "../lib/text_color.h"
#include <stdio.h>
#include <string.h>

void handle_color(const char *value) {
  text_color c = parse_color(value);
  char *ansi = change_text_color(c);
  printf("%stext color: %s%s\n", ansi, value, ANSI_COLOR_RESET);
}

void handle_ascii_art(const char *value) {
  printf("ascii_art mode: %s\n", value);
}

void handle_mood(const char *value) { printf("mood chosen: %s\n", value); }

void handle_unknown(const char *key, const char *value) {
  printf("Unknown key and value: %s=%s\n", key, value);
}

typedef struct {
  const char *key;
  void (*handler)(const char *value);
} option_handler_t;

option_handler_t handlers[] = {{"color", handle_color},
                               {"ascii_art", handle_ascii_art},
                               {"mood", handle_mood},
                               {NULL, NULL}};

int apply_config(config_option_t co) {
  if (!co) {
    fprintf(stderr, "Config parser returned NULL\n");
    return -1;
  }

  for (config_option_t it = co; it != NULL; it = it->prev) {
    int handled = 0;
    for (option_handler_t *h = handlers; h->key; h++) {
      if (strcmp(it->key, h->key) == 0) {
        h->handler(it->value);
        handled = 1;
        break;
      }
    }
    if (!handled) {
      handle_unknown(it->key, it->value);
    }
  }
  return 0;
}

void config_handler() {
  config_option_t co = read_config_file("./pwatcurl.conf");
  apply_config(co);
  destroy_config_file(co);
}
