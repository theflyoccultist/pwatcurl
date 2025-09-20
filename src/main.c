#include "cli_args.h"
#include "config_handler.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  config_handler();
  if (argc < 2) {
    fprintf(stderr, "[pwatcurl] You forgot an argument, sweetie. \n");
    return 1;
  }

  cli_args(argc, argv);

  return 0;
}
