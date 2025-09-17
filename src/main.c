#include "../lib/conf_file_parser.h"
// #include "request.h"
#include <stdio.h>

// int main(int argc, char *argv[]) {
//   if (argc < 2) {
//     fprintf(stderr, "[pwatcurl] You forgot an argument, sweetie. \n");
//     return 1;
//   }
//
//   perform_get_request(argv[1]);
//   return 0;
// }

// TODO: Unknown keys: print a warning, but don't crash.

// TODO: default values, for example if ascii_art is missing
int apply_config(config_option_t co) {
  if (!co) {
    fprintf(stderr, "Config parser returned NULL\n");
    return -1;
  }

  for (config_option_t it = co; it != NULL; it = it->prev) {
    printf("Key: %s\nValue: %s\n", it->key, it->value);
  }
  return 0;
}

int main() {
  config_option_t co = read_config_file("./pwatcurl.conf");
  apply_config(co);
  destroy_config_file(co);
  return 0;
}
