#compiler
CC=gcc   

CFLAGS=-ansi -pedantic-errors -Wall -Wextra -g -I$(INC_DIR)

RPATH=-Wl,-rpath,'$$ORIGIN/../../../lib/$(FOLDER)'
LPATH=-Wl,-rpath,'$$ORIGIN'
TARGET=scheduler
FOLDER=debug
DEP=task priorityq
HDEP=$(patsubst %,$(INC_DIR)/%.h,$(DEP))
LDEP=$(patsubst %,$(LIB_DIR)/lib%.so,$(DEP))
LLIB=$(patsubst %,-l%,$(DEP))

#directories
OUT_DIR=./out/$(FOLDER)
OBJ_DIR=./obj/$(FOLDER)
INC_DIR=./../include
LIB_DIR=./../lib/$(FOLDER)

$(OUT_DIR)/$(TARGET).out: $(OBJ_DIR)/$(TARGET)_test.o $(LIB_DIR)/lib$(TARGET).so | $(OUT_DIR) 
	$(CC) -o $@  $< -L$(LIB_DIR) -l$(TARGET) $(RPATH)

$(LIB_DIR)/lib$(TARGET).so: $(OBJ_DIR)/$(TARGET).o | $(LDEP)
	$(CC) -shared -o $@ $< -L$(LIB_DIR) $(LLIB) $(LPATH)
	
$(OBJ_DIR)/$(TARGET).o: $(TARGET).c $(INC_DIR)/$(TARGET).h $(HDEP)| $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS) -fPIC

$(OBJ_DIR)/$(TARGET)_test.o: $(TARGET)_test.c $(INC_DIR)/$(TARGET).h | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB_DIR)/libtask.so:
	cd ./../ && make $(FOLDER)_task;

$(LIB_DIR)/libpriorityq.so:
	cd ./../ && make $(FOLDER)_priorityq;

$(OBJ_DIR):
	-mkdir obj; mkdir $(OBJ_DIR);

$(OUT_DIR):
	-mkdir out; mkdir $(OUT_DIR);

.PHONY: clean echo
clean: 
	rm -r obj out

echo:
	@echo $(DEP)
	@echo $(HDEP)
	@echo $(LDEP)
	@echo $(LLIB)
