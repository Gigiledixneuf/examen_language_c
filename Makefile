CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS = -lm

SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

APP = $(BIN_DIR)/calculator
TEST_BASIC_OPERATIONS = $(BIN_DIR)/test_basic_operations
TEST_ADVANCED_OPERATIONS = $(BIN_DIR)/test_advanced_operations

SRC = $(wildcard $(SRC_DIR)/*.c)


.PHONY: all clean rebuild run test test-operations


all: $(APP)


$(APP): $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)


$(TEST_BASIC_OPERATIONS): $(SRC_DIR)/basic_operations.c $(TEST_DIR)/basic_operations.test.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(TEST_ADVANCED_OPERATIONS): $(SRC_DIR)/advanced_operations.c $(TEST_DIR)/advanced_operations.test.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)


test-basic-operations: $(TEST_BASIC_OPERATIONS)
	./$(TEST_BASIC_OPERATIONS)

test-advanced-operations: $(TEST_ADVANCED_OPERATIONS)
	./$(TEST_ADVANCED_OPERATIONS)


test: test-basic-operations test-advanced-operations


run: $(APP)
	./$(APP)


rebuild: clean all


clean:
	rm -f $(BIN_DIR)/*