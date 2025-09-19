#ifndef MOOD_HANDLER_H
#define MOOD_HANDLER_H

typedef enum { goth, bubbly, shy } moods;

moods parse_mood(const char *value);

char *change_mood(moods m);

#endif // !MOOD_HANDLER_H
