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
    [shy] = "[pwatcurl] All gud! I coud talk to da website! ^_^"};

void mood_print_success() { printf("%s\n", success_messages[current_mood]); }

const char *failure_messages[MOOD_COUNT] = {
    [goth] = "[pwatcurl][error] As expected, the void has consumed us",
    [bubbly] = "[pwatcurl][error] No party today... Maybe next time?",
    [shy] = "[pwatcurl][error] Nyooo!! I am so sowry abowt this >.<"};

void mood_print_failure() { printf("%s\n", failure_messages[current_mood]); }

const char *fatal_messages[MOOD_COUNT] = {
    [goth] = "[pwatcurl][fatal] The void has collapsed reality.",
    [bubbly] = "[pwatcurl][fatal] Libcurl broke... This is so unfair!",
    [shy] = "[pwatcurl][fatal] Maywbe we awsked libcurl 2 muxh!? <_<"};

void mood_print_fatal() { printf("%s\n", fatal_messages[current_mood]); }

const char *nofilename_messages[MOOD_COUNT] = {
    [goth] = "[pwatcurl] Looked for filename in the URL but found "
             "desolation. The name 'pwatcurl_response.txt' was chosen as "
             "default... Just like I default to darkness.",
    [bubbly] = "[pwatcurl] Saved output in the 'pwatcurl_response.txt' name,"
               "as that is the default if no name is present in the URL. You "
               "are welcome!",
    [shy] = "[pwatcurl] Nyo failenyame in da YOU-RL. Mabey they forgor"
            "it? Using da nyame 'pwatcurl_response.txt. Hope it okie!"};

void mood_print_nofilename() {
  printf("%s\n", nofilename_messages[current_mood]);
}

const char *easteregg_messages[MOOD_COUNT] = {
    [goth] = "The frantic race took them to the great hall, where the creature "
             "grabbed the columns with its tentacles, tearing the wood and "
             "stones like paper. Appendages, multiplying endlessly, sprouted "
             "from the gelatinous mass that his body had become, caressing the "
             "walls to destroy them. Unintelligible murmurs escaped him, a "
             "mixture of accusations, pain and despair.",
    [bubbly] = "Error: Your device has been infected by a virus. "
               "U6=$JJ:HQ/[3EZ _ ~q_T6 @ðßđsdkfjhgdfkjhgi2564710.5ffs |N?&kjhkn"
               "K:Rti28}wc9bML%6qpr`hPJz@E*!V&&{J}X|?'",
    [shy] =
        "Later that night, Jeff's mother woke to a sound coming from the "
        "bathroom. It sounded as if someone was crying. She slowly walked over "
        "to see what it was. When she looked into the bathroom she saw a "
        "horrendous sight. Jeff had taken a knife and carved a smile into his "
        "cheeks.\n\n'Jeff, what are you doing?' asked his mother.\n\nJeff "
        "looked "
        "over to his mother. 'I couldn't keep smiling mommy. It hurt after "
        "awhile. Now, I can smile forever.' Jeff's mother noticed his eyes, "
        "ringed in black.\n\n'Jeff, your eyes!' His eyes were seemingly never "
        "closing.\n\n'I couldn't see my face. I got tired and my eyes started "
        "to close. I burned out the eyelids so I could forever see myself; my "
        "new face.' Jeff' s mother slowly started to back away, seeing that "
        "her son was going insane.'What' s wrong mommy? Aren't I "
        "beautiful?'\n"};

void mood_print_easteregg() {
  printf("%s\n", easteregg_messages[current_mood]);
};
