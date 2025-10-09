CC = gcc
CFLAGS = -O0 -Wall -Wextra -Iinclude
LDFLAGS = -lcurl

SRCS = 	src/main.c \
				src/cli_args.c \
				src/config_handler.c \
				src/request.c \
				lib/conf_file_parser.c \
				lib/text_color.c \
				lib/mood_handler.c \
				lib/ascii_art_handler.c \
				lib/cooldown.c

OBJ = $(SRCS:.c=.o)
BIN = pwatcurl

$(BIN): $(OBJ)
	@echo "Scheming with evil thoughts..."
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@echo "Cleaning up your digital crimes..."
	rm -f $(OBJ) $(BIN)

PREFIX ?= /usr/local/
CONF_DIR ?= $(HOME)/.pwatcurl

install:
	@echo "Making myself home at your place..."
	mkdir -p $(CONF_DIR)
	cp pwatcurl $(PREFIX)/bin/pwatcurl
	cp pwatcurl.conf $(CONF_DIR)/pwatcurl.conf
	chmod +x $(PREFIX)/bin/pwatcurl

uninstall:
	@echo "Goodbye."
	rm -f $(PREFIX)/bin/pwatcurl
	rm -f $(CONF_DIR)/pwatcurl.conf
