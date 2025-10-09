#ifndef MOOD_HANDLER_H
#define MOOD_HANDLER_H

typedef enum { goth, bubbly, shy, MOOD_COUNT } moods;

moods parse_mood(const char *value);
char *set_mood(moods m);
void change_mood(moods m);

void mood_print_success();
void mood_print_failure();
void mood_print_fatal();
void mood_print_nofilename();

#endif // !MOOD_HANDLER_H
