#include "mood_handler.h"
#include <stdio.h>
#include <strings.h>

moods parse_mood(const char *value) {
  if (strcasecmp(value, "goth") == 0)
    return goth;
  if (strcasecmp(value, "bubbly") == 0)
    return bubbly;
  if (strcasecmp(value, "shy") == 0)
    return shy;

  fprintf(stderr, "'%s' is not a mood I wanna be in. Using goth instead.\n",
          value);
  return goth;
}

char *change_mood(moods m) {
  switch (m) {
  case goth:
    return "goth";
  case bubbly:
    return "bubbly";
  case shy:
    return "shy";
  default:
    return "goth";
  }
}
