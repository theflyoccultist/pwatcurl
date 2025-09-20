#ifndef REQUEST_H
#define REQUEST_H

typedef struct {
  int verbose;
  int follow_redirects;
  const char *output_file;
  int save_remote_name;
  int headers_only;
} request_opts_t;

void perform_get_request(const char *url, request_opts_t *opts);

#endif // !REQUEST_H
