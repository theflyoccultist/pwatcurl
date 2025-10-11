#include "../lib/ascii_art_handler.h"
#include "../lib/conf_file_parser.h"
#include "../lib/cooldown.h"
#include "../lib/mood_handler.h"
#include "../lib/text_color.h"
#include <stdio.h>
#include <string.h>

static char msg[128];

const char *handle_color(const char *value) {
  text_color c = parse_color(value);
  char *ansi = change_text_color(c);

  if (strcmp(ansi, "\x1b[0m") == 0) {
    snprintf(msg, sizeof(msg), "%stext color set to default: white", ansi);
    return msg;
  } else {
    snprintf(msg, sizeof(msg), "%stext color: %s", ansi, value);
    printf("%s", ansi);
    return msg;
  }
}

static int ascii_art_enabled = 0;

const char *handle_ascii_art(const char *value) {
  if (ascii_art_activated(value)) {
    ascii_art_enabled = 1;

    return "ascii_art: active";
  } else {
    ascii_art_enabled = 0;
    return "ascii_art: inactive";
  }
}

const char *handle_mood(const char *value) {
  moods m = parse_mood(value);
  char *chosen_mood = set_mood(m);
  change_mood(m);

  if (ascii_art_enabled) {
    display_ascii(chosen_mood);
  }

  snprintf(msg, sizeof(msg), "mood chosen: %s", chosen_mood);
  return msg;
}

void handle_unknown(const char *key, const char *value) {
  printf("No idea what you wrote here: %s=%s\n", key, value);
}

typedef struct {
  const char *key;
  const char *default_value;
  const char *(*handler)(const char *value);
} option_handler_t;

option_handler_t handlers[] = {{"color", "white", handle_color},
                               {"ascii_art", "no", handle_ascii_art},
                               {"mood", "goth", handle_mood},
                               {NULL, NULL, NULL}};

void apply_defaults() {
  printf(".conf file not found. Applying defaults...\n");
  for (option_handler_t *h = handlers; h->key; h++) {
    fprintf(stderr, "Default setting for %s: %s\n", h->key, h->default_value);
    h->handler(h->default_value);
  }
  printf("___________________\n\n");
}

const char *apply_config(config_option_t co) {
  if (!co) {
    return "Error: Config parser returned NULL\n";
  }

  printf(".conf file found. Applying settings...\n");

  static char messages[512] = {0};
  messages[0] = '\0';

  for (config_option_t it = co; it != NULL; it = it->prev) {
    int handled = 0;
    for (option_handler_t *h = handlers; h->key; h++) {
      if (strcmp(it->key, h->key) == 0) {
        handled = 1;
        const char *message = h->handler(it->value);
        if (message) {
          strncat(messages, message, sizeof(messages) - strlen(messages) - 2);
          strncat(messages, "\n", sizeof(messages) - strlen(messages) - 1);
        }
        break;
      }
    }
    if (!handled) {
      handle_unknown(it->key, it->value);
    }
  }
  return messages;
}

void maybe_display_config(const char *messages) {
  if (cooldown_active()) {
    printf("%s", messages);
  } else {
    printf("Using previously set configs\n");
  }
}

void config_handler() {
  config_option_t co = read_config_file("./pwatcurl.conf");
  co ? maybe_display_config(apply_config(co)) : apply_defaults();

  printf("%s", ANSI_COLOR_RESET);
  destroy_config_file(co);
}
