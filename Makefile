vpath ./src ./include ./build
SRC_DIR := ./src
BUILD_DIR := ./build
DEP_DIR := $(BUILD_DIR)/dependencies
OBJ_DIR := $(BUILD_DIR)/objects
CC := gcc
CFLAGS := -g -Wall -std=c99 -MMD -MP
TARGET := $(BUILD_DIR)/my_cat
SRCS := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*.cpp $(SRC_DIR)/*.s)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(filter $(SRC_DIR)/%.c, $(SRCS)))
DEPS := $(patsubst $(OBJ_DIR)/%.o, $(DEP_DIR)/*.d, $(OBJS))

-include $(DEPS)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DEP_DIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -MF $(DEP_DIR)/$*.d -o $@ $<

$(DEP_DIR):
	mkdir -p $(DEP_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)/my_cat $(OBJ_DIR)/*.o $(DEP_DIR)/*.d