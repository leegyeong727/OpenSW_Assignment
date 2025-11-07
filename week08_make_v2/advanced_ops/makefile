SRC_DIR=src
OBJ_DIR=obj
INC_DIR=../include
LIB_DIR=../lib
LIB_NAME=$(LIB_DIR)/libmyadvanced.a

CC=gcc
CFLAGS=-I$(INC_DIR) -lm

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o
	mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	if [ -d $(OBJ_DIR) ]; then rm -f $(OBJ_DIR)/*.o; fi
	if [ -f $(LIB_NAME) ]; then rm -f $(LIB_NAME); fi
