#compiler
CC=gcc   

CFLAGS=-ansi -pedantic-errors -Wall -Wextra -g -I$(INC_DIR)

RPATH=-Wl,-rpath,'$$ORIGIN/../../../lib/$(FOLDER)'
TARGET=search
FOLDER=debug

#directories
OUT_DIR=./out/$(FOLDER)
OBJ_DIR=./obj/$(FOLDER)
INC_DIR=./../include
LIB_DIR=./../lib/$(FOLDER)

$(OUT_DIR)/$(TARGET).out: $(OBJ_DIR)/$(TARGET)_test.o $(LIB_DIR)/lib$(TARGET).so | $(OUT_DIR) 
	$(CC) -o $@  $< -L$(LIB_DIR) -l$(TARGET) $(RPATH) -lm

$(LIB_DIR)/lib$(TARGET).so: $(OBJ_DIR)/$(TARGET).o
	$(CC) -shared -o $@ $<
	
$(OBJ_DIR)/$(TARGET).o: $(TARGET).c $(INC_DIR)/$(TARGET).h | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS) -fPIC

$(OBJ_DIR)/$(TARGET)_test.o: $(TARGET)_test.c $(INC_DIR)/$(TARGET).h | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR):
	-mkdir obj; mkdir $(OBJ_DIR);

$(OUT_DIR):
	-mkdir out; mkdir $(OUT_DIR);

.PHONY: clean  
clean: 
	rm -r obj out
