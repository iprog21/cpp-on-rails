CXX = g++
CXXFLAGS = -std=c++17 -pthread
SRC = application.cpp
BIN = cpp-on-rails

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)

.PHONY: all clean
