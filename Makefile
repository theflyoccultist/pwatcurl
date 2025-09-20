CC				:= gcc
CFLAGS		:= -O0 -Wall -Wextra -Iinclude
LDFLAGS		:= -lcurl

SRCS			:= src/main.c \
						 src/cli_args.c \
						 src/config_handler.c \
						 src/request.c \
						 lib/conf_file_parser.c \
						 lib/text_color.c \
						 lib/mood_handler.c \
						 lib/ascii_art_handler.c

OBJ				:= $(SRCS:.c=.o)
BIN				:= pwatcurl

$(BIN): $(OBJ)
	@echo "Scheming with evil thoughts..."
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@echo "Cleaning up your digital crimes..."
	rm -f $(OBJ) $(BIN)
