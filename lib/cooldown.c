#include "./cooldown.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define CACHE_FILE "../.pwatcurl_launch_time"

bool cooldown_active() {
  const int COOLDOWN_SEC = 10;
  // change to 600 if it works

  time_t now = time(NULL);
  time_t last = 0;

  FILE *fp = fopen(CACHE_FILE, "r");
  if (fp) {
    fscanf(fp, "%ld", &last);
    fclose(fp);
  } else {
    perror("fopen failed");
  }

  if (!last || difftime(now, last) > COOLDOWN_SEC) {
    // printf("First launch or 10+ minutes passed.\n");
    fp = fopen(CACHE_FILE, "w");
    fprintf(fp, "%ld", now);
    fclose(fp);
    return true;
  } else {
    // printf("Less than 10 minutes since last run.\n");
    return false;
  }
}
