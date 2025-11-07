.PHONY: all basic_ops advanced_ops clean

SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
INC_DIR=include
LIB_DIR=lib

STATIC_LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a

CC=gcc
CFLAGS=-I$(INC_DIR) -lm
LDFLAGS=-L$(LIB_DIR) -lmybasic -lmyadvanced

all: basic_ops advanced_ops $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(STATIC_LIBS)
	mkdir -p $(BIN_DIR)
	$(CC) $< -o $@ $(LDFLAGS) $(CFLAGS)

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops

clean:
	if [ -d $(BIN_DIR) ]; then rm -rf $(BIN_DIR)/*; fi
	if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR)/*; fi
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean
