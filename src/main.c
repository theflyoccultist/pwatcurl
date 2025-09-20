#include "config_handler.h"
#include "request.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  config_handler();
  if (argc < 2) {
    fprintf(stderr, "[pwatcurl] You forgot an argument, sweetie. \n");
    return 1;
  }

  perform_get_request(argv[1]);
  return 0;
}
