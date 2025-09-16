CC				:= gcc
CFLAGS		:= -O0 -Wall -Wextra -Iinclude
LDFLAGS		:= -lcurl

SRCS			:= src/main.c src/conf_file_parser.c
OBJ				:= $(SRCS:.c=.o)
BIN				:= pwatcurl

$(BIN): $(OBJ)
	@echo "Scheming with evil thoughts..."
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@echo "Cleaning up your digital crimes..."
	rm -f $(OBJ) $(BIN)
