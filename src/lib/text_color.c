#include "text_color.h"
#include <stdio.h>
#include <strings.h>

text_color parse_color(const char *value) {
  if (strcasecmp(value, "red") == 0)
    return red;
  if (strcasecmp(value, "green") == 0)
    return green;
  if (strcasecmp(value, "yellow") == 0)
    return yellow;
  if (strcasecmp(value, "blue") == 0)
    return blue;
  if (strcasecmp(value, "magenta") == 0)
    return magenta;
  if (strcasecmp(value, "cyan") == 0)
    return cyan;
  if (strcasecmp(value, "white") == 0)
    return white;

  fprintf(stderr, "I don't know about the color '%s'. Using white instead.\n",
          value);
  return white;
}

char *change_text_color(text_color c) {
  switch (c) {
  case red:
    return ANSI_COLOR_RED;
  case green:
    return ANSI_COLOR_GREEN;
  case yellow:
    return ANSI_COLOR_YELLOW;
  case blue:
    return ANSI_COLOR_BLUE;
  case magenta:
    return ANSI_COLOR_MAGENTA;
  case cyan:
    return ANSI_COLOR_CYAN;
  case white:
    return ANSI_COLOR_WHITE;
  default:
    return ANSI_COLOR_RESET;
  }
}
