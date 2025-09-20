#include "request.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <stdbool.h>
#include <stdio.h>

void verbose_mode(CURL *curl) { curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); }

void perform_get_request(const char *url, request_opts_t *opts) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    if (opts->verbose)
      verbose_mode(curl);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "[pwatcurl][error] '%s'\n", curl_easy_strerror(res));
    } else {
      printf("[pwatcurl] GET request succeded. Mood: tolerable.\n");
    }

    curl_easy_cleanup(curl);
  } else {
    fprintf(
        stderr,
        "[pwatcurl][fatal] Could not initialize curl. Feeling: dramatic.\n");
  }
}
