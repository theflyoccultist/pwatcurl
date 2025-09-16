# Pwatcurl
A troll version of curl, with a configurable mood.

## Features:
- Configurable moods: edit the `pwatcurl.conf` file to change pwatcurl's behavior!

- `conf_file_parser.c` and `conf_file_parser.h`:
My own C library to parse .conf files, inspired by [Config-Parser-C](https://github.com/welljsjs/Config-Parser-C)

- Install the libcurl Development Package

Needed dependencies:

```bash
sudo apt install libcurl4-openssl-dev
```

Once it's done, you can use the makefile to build the program with `make`.
