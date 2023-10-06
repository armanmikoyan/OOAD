# Compiler and flags
CC = g++
CFLAGS = -Wall -Iincludes -std=c++20

# Source files
SOURCES = $(wildcard src/*.cpp)

# Executable name
TARGET = prog

# Targets and rules
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -rf $(TARGET)
