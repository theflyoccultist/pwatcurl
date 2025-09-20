#ifndef REQUEST_H
#define REQUEST_H

typedef struct {
  int verbose;
  const char *output_file;
} request_opts_t;

void perform_get_request(const char *url, request_opts_t *opts);

#endif // !REQUEST_H
