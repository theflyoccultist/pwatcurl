#ifndef CONF_FILE_PARSER_H
#define CONF_FILE_PARSER_H

#define CONFIG_ARG_MAX_BYTES 128

typedef struct config_option config_option;
typedef config_option *config_option_t;

struct config_option {
  config_option_t prev;
  char key[CONFIG_ARG_MAX_BYTES];
  char value[CONFIG_ARG_MAX_BYTES];
};

config_option_t read_config_file(char *path);
void destroy_config_file(config_option_t co);

#endif // !CONF_FILE_PARSER_H
