.PHONY: test
CC=g++ -std=c++17
TEST_FLAGS=-lgtest -lgtest_main -pthread

TEST_DIR=./test/
OUT_TEST_DIR=./build/

TESTFILE=$(TEST_DIR)test.cpp
OUT_TEST=$(OUT_TEST_DIR)sc_test

all: clang test run

test:
	@$(CC) $(TESTFILE) $(TEST_FLAGS) -L /usr/local/lib -o $(OUT_TEST)

clean:
	@rm -f $(OUT_TEST)

clang:
	@clang-format -i $(TEST_FILE) ./controller/*.h ./model/*.h
run:
	@./$(OUT_TEST) --gtest_repeat=1