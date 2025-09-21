# Pwatcurl
A troll version of curl, with a configurable mood.

## Features:

### Configurable mood: edit the `pwatcurl.conf` file in the root folder to change pwatcurl's behavior!
- If you enable ASCII art without choosing a mood, pwatcurl refuses to commit to a vibe. No art will be shown.
- If the `pwatcurl.conf` file is missing, it will set itself to a default.

### CLI Flags:

- **Syntax : `pwatcurl [options] <url>`**
-`-h, --help` : Show this help message
-`-o <file>` : Write output to <file>
-`-O, --remote-name` : Save file with remote name. If no remote name is available, it will save output to a default file named `pwatcurl_response.txt`.
- `-L, --location` : Follow redirects
- `-I, --head` : This flag will not only show the HTTP header, but also the IP addresses that it attempted to connect to.
- `-v, --verbose` : Verbose mode

### Files:

- `lib/conf_file_parser.c` and `lib/conf_file_parser.h`:
My own C library to parse .conf files, inspired by [Config-Parser-C](https://github.com/welljsjs/Config-Parser-C).
It handles trailing spaces, is case insensitive and ignores inline and newline comments.

- `lib/text_color.c` and `lib/text_color.h`:
Handles text color display on the output.

## Setup

- Install the libcurl Development Package

```bash
sudo apt install libcurl4-openssl-dev
```

Then, you can build the program with those steps:

```bash
git clone https://github.com/theflyoccultist/pwatcurl.git
cd pwatcurl
make
```

