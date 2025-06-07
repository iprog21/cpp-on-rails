CXX = g++
CXXFLAGS = -std=c++17 -pthread
SRC = application.cpp
DEV_BIN = cpp-on-rails-dev
PROD_BIN = cpp-on-rails-prod
TEST_BIN = tests/run_tests
TEST_SRC = tests/test_home_view.cpp

all: clean $(DEV_BIN) $(PROD_BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(DEV_BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -DDEVELOPMENT $(SRC) -o $(DEV_BIN)

$(PROD_BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -DPRODUCTION $(SRC) -o $(PROD_BIN)

clean:
	rm -f $(DEV_BIN) $(PROD_BIN) $(TEST_BIN)

.PHONY: all clean test
