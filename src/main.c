#include "conf_file_parser.h"
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

int main() {
  config_option_t co = read_config_file("./pwatcurl.conf");

  // TODO: move this part to a separate apply_config(co) function
  if (!co) {
    fprintf(stderr, "Config parser returned NULL\n");
    return -1;
  }

  for (config_option_t it = co; it != NULL; it = it->prev) {
    printf("Key: %s\nValue: %s\n", it->key, it->value);
  }

  destroy_config_file(co);
}
