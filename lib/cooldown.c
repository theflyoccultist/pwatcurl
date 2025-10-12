#include "./cooldown.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define CACHE_FILE "../.pwatcurl_launch_time"

bool cooldown_active() {
  const int COOLDOWN_SEC = 600;

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
    // First launch or 10+ minutes passed
    fp = fopen(CACHE_FILE, "w");
    fprintf(fp, "%ld", now);
    fclose(fp);
    return true;
  } else {
    // Less than 10 minutes since last run
    return false;
  }
}
