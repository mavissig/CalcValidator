.PHONY: test
CC=g++ -std=c++17
TEST_FLAGS=-lgtest -lgtest_main -pthread

TEST_DIR=./test/
OUT_TEST_DIR=./build/

TESTFILE=$(TEST_DIR)test.cpp
OUT_TEST=$(OUT_TEST_DIR)sc_test

all: test run

test:
	@$(CC) $(TESTFILE) $(TEST_FLAGS) -L /usr/local/lib -o $(OUT_TEST)

clean:
	@rm -f $(OUT_TEST)

run:
	@./$(OUT_TEST) --gtest_repeat=1