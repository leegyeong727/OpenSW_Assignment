CC = gcc
CFLAGS = -I$(INC_DIR) -fPIC -Wall
LDFLAGS = -L$(LIB_DIR) -lmyops -lm

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include
LIB_DIR = lib

SRCS = $(wildcard $(SRC_DIR)/my*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB_NAME = libmyops.so.1.0
LIB_SO_LINK = libmyops.so
LIB_PATH = $(LIB_DIR)/$(LIB_NAME)
TARGET = $(BIN_DIR)/myapp

all: $(LIB_PATH) link $(TARGET)

$(LIB_PATH): $(filter-out $(OBJ_DIR)/myapp.o, $(OBJS))
	@mkdir -p $(LIB_DIR)
	$(CC) -shared -o $@ $^

link:
	@ln -sf $(LIB_NAME) $(LIB_DIR)/$(LIB_SO_LINK)

$(TARGET): $(OBJ_DIR)/myapp.o $(LIB_PATH)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $< $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/* $(LIB_DIR)/*.so*

run: all
	@export LD_LIBRARY_PATH=$(PWD)/$(LIB_DIR):$$LD_LIBRARY_PATH && ./$(TARGET)

.PHONY: all clean run link
