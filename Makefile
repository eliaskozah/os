# Compiler and Compile options
CC=gcc
CFLAGS=-Wall -g

# Target executable and source file
TARGET=run
SRC=$(FILE)

# Default rule to make everything
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean up
clean:
	rm -f $(TARGET)

# Run the program
execute:
	./$(TARGET)
