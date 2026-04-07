# Compiler
CC = gcc
CFLAG = -Wall -Wextra -Iinclude

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src

TARGET = $(BIN_DIR)/app
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/sqlite3.o
# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAG) -c $< -o $@ 

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/app

.PHONY: all clean

