CXX = g++
CXXFLAGS = -std=c++17 -pthread
SRC = application.cpp
BIN = cpp-on-rails
TEST_BIN = tests/run_tests
TEST_SRC = tests/test_home_view.cpp

all: clean $(BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)

.PHONY: all clean test
