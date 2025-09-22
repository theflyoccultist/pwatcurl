#include "request.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <stdio.h>
#include <string.h>

const char *get_remote_filename(const char *url) {
  const char *slash = strrchr(url, '/');
  if (slash && *(slash + 1) != '\0') {
    return slash + 1;
  }
  return NULL;
}

void perform_get_request(const char *url, request_opts_t *opts) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);

    if (opts->headers_only) {
      curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    } else {
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
    }

    if (opts->follow_redirects)
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    if (opts->verbose)
      curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    FILE *fp = NULL;
    if (opts->output_file) {
      fp = fopen(opts->output_file, "w");
      if (!fp) {
        fprintf(stderr, "[pwatcurl][error] Could not open file '%s'\n",
                opts->output_file);
        curl_easy_cleanup(curl);
        return;
      }
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    }

    if (opts->save_remote_name) {
      const char *fname = get_remote_filename(url);
      if (fname) {
        fp = fopen(fname, "w");
      } else {
        fp = fopen("pwatcurl_response.txt", "w");
        fprintf(stderr, "[pwatcurl][snark] No filename in URL. "
                        "Saving as 'pwatcurl_response.txt. You're welcome!\n");
      }
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    }

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "[pwatcurl][error] '%s'\n", curl_easy_strerror(res));
      mood_print_failure();
    } else {
      mood_print_success();
    }

    if (fp)
      fclose(fp);
    curl_easy_cleanup(curl);

  } else {
    mood_print_fatal();
  }
}
