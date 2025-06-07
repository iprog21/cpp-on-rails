CXX = g++
CXXFLAGS = -std=c++17 -pthread
SRC = application.cpp
BIN = cpp-on-rails
PROD_BIN = cpp-on-rails-prod
TEST_BIN = tests/run_tests
TEST_SRC = tests/test_home_view.cpp

all: clean $(BIN) $(PROD_BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(PROD_BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -DPRODUCTION $(SRC) -o $(PROD_BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -DOPEN_BROWSER $(SRC) -o $(BIN)

clean:
	rm -f $(BIN) $(PROD_BIN) $(TEST_BIN)

.PHONY: all clean test
