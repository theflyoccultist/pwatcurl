# Pwatcurl
A troll version of curl, with a configurable mood.

## Features:
- Configurable moods: edit the `pwatcurl.conf` file in the root folder to change pwatcurl's behavior!
If you enable ASCII art without choosing a mood, pwatcurl refuses to commit to a vibe. No art will be shown.

- `lib/conf_file_parser.c` and `lib/conf_file_parser.h`:
My own C library to parse .conf files, inspired by [Config-Parser-C](https://github.com/welljsjs/Config-Parser-C).
It handles trailing spaces, is case insensitive and ignores inline comments.

- Install the libcurl Development Package

Needed dependencies:

```bash
sudo apt install libcurl4-openssl-dev
```

Once it's done, you can use the makefile to build the program with `make`.
