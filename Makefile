CC = gcc
CFLAGS = -O0 -Wall -Wextra -Iinclude
LDFLAGS = -lcurl

SRCS = $(wildcard src/*.c src/lib/*.c)
OBJ = $(SRCS:.c=.o)
BIN = pwatcurl

all: release

release: $(CFLAGS) += -O2
release: $(BIN)

debug: CC = clang
debug: CFLAGS += -g -O0 -fsanitize=address -fno-omit-frame-pointer
debug: LDFLAGS += -fsanitize=address -fsanitize=undefined

debug: $(BIN)
	@echo "We are in Spy Mode."

$(BIN): $(OBJ)
	@echo "Scheming with evil thoughts..."
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

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

.PHONY: release debug clean install uninstall
