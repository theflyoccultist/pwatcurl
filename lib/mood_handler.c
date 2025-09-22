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

char *set_mood(moods m) {
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

moods current_mood = goth;

void change_mood(moods m) { current_mood = m; }

const char *success_messages[MOOD_COUNT] = {
    [goth] = "[pwatcurl] The abyss has delivered your payload.",
    [bubbly] = "[pwatcurl] Yay! Request complete! Party time!",
    [shy] = "[pwatcurl] I think.. I was able to talk to the website..."};

void mood_print_success() { printf("%s\n", success_messages[current_mood]); }

const char *failure_messages[MOOD_COUNT] = {
    [goth] = "[pwatcurl] [error] As expected, the void has consumed us",
    [bubbly] = "[pwatcurl] [error] Oh no... Better luck next time",
    [shy] = "[pwatcurl] [error] I am... so sorry to dissapoint you"};

void mood_print_failure() { printf("%s\n", failure_messages[current_mood]); }

const char *fatal_messages[MOOD_COUNT] = {
    [goth] = "[pwatcurl] [fatal] I was not expecting more",
    [bubbly] = "[pwatcurl] [fatal] this is so unfair!",
    [shy] = "[pwatcurl] [fatal] I am... so sorry to dissapoint you"};

void mood_print_fatal() { printf("%s\n", fatal_messages[current_mood]); }
