#include "cli_args.h"
#include "request.h"
#include <getopt.h>
#include <stdio.h>
#include <unistd.h>

void print_help() {
  printf("Usage: pwatcurl [options] <url>\n\n"
         "Options:\n"
         "  -o <file>            Write output to <file>\n"
         "  -O                   Save file with remote name\n"
         "  -L                   Follow redirects\n"
         "  -I                   Headers only (HEAD request)\n"
         "  -v                   Verbose mode\n"
         "  -s                   Silent mode (no progress)\n"
         "  -S                   Show errors (use with -s)\n"
         "  -w \"%%{http_code}\" Print status code or metrics\n"
         "  -h                   Show this help message\n"
         "  Coming soon...\n"
         "  -X, --request <method>    Specify HTTP method (GET, POST, etc.)\n"
         "  -d, --data <data>         Send POST data\n"
         "  -H, --header <header>     Pass custom header to server\n"
         "  -i, --show-headers        Include headers in output\n");
}

int cli_args(int argc, char *argv[]) {
  int c;

  request_opts_t opts = {.verbose = 0,
                         .follow_redirects = 0,
                         .output_file = NULL,
                         .save_remote_name = 0,
                         .headers_only = 0,
                         .silent = 0,
                         .show_error = 0};

  while ((c = getopt(argc, argv, "o:OILvX:d:H:sSiw:h")) != -1) {
    switch (c) {
    // S tier features
    case 'o':
      printf("Write to file: %s\n", optarg);
      opts.output_file = optarg;
      break;
    case 'O':
      printf("Save with remote filename\n");
      opts.save_remote_name = 1;
      break;
    case 'L':
      printf("Follow redirects\n");
      opts.follow_redirects = 1;
      break;
    case 'I':
      printf("Headers only\n");
      opts.verbose = 1;
      opts.headers_only = 1;
      break;
    case 'v':
      printf("Verbose mode\n");
      opts.verbose = 1;
      break;
    // A tier features
    case 'X':
      printf("HTTP method: %s\n", optarg);
      break;
    case 'd':
      printf("POST data: %s\n", optarg);
      break;
    case 'H':
      printf("Custom header: %s.\n", optarg);
      break;
    case 's':
      printf("Silent mode\n");
      opts.silent = 1;
      break;
    case 'S':
      printf("Show errors\n");
      opts.show_error = 1;
      break;
    case 'i':
      printf("Include headers in output\n");
      break;
    case 'w':
      printf("Output format: %s\n", optarg);
      opts.write_out_format = optarg;
      break;
    case 'h':
      print_help();
      return 0;
    case '?':
      fprintf(stderr, "Unknown option character `%c'.\n", optopt);
      printf("try 'pwatcurl -h' for more information\n");
      return 1;
    }
  }

  if (optind < argc) {
    for (int i = optind; i < argc; i++) {
      const char *url = argv[i];
      printf("GET request to: %s\n", url);
      perform_get_request(url, &opts);
    }
  } else {
    printf("No URL provided!\n");
  }

  return 0;
}
