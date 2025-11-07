SRC_DIR = src
INC_DIR = include
BIN_DIR = bin
OBJ_DIR = obj
LIB_DIR = lib

CC = gcc
CFLAGS = -I$(INC_DIR)
LIB = $(LIB_DIR)/libmybasic.a
APP = $(BIN_DIR)/myapp

.PHONY: all basic clean

all: $(APP)

basic: $(LIB)

$(APP): $(OBJ_DIR)/myapp.o $(LIB)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -L$(LIB_DIR) -lmybasic -o $@
	@echo "$(APP)"

$(LIB): $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^
	@echo "$(LIB)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/myapp $(LIB_DIR)/libmybasic.a
