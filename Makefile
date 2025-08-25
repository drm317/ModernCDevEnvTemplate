CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
SRCDIR = src
INCDIR = include
BUILDDIR = build
TESTDIR = test
TARGET = $(BUILDDIR)/main

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

# Test configuration
TEST_SOURCES = $(wildcard $(TESTDIR)/*.c)
TEST_UNITY_SOURCES = $(wildcard $(TESTDIR)/unity/*.c)
LIB_SOURCES = $(filter-out $(SRCDIR)/main.c, $(SOURCES))
LIB_OBJECTS = $(LIB_SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)
TEST_TARGET = $(BUILDDIR)/test_runner

.PHONY: all clean format tidy test

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BUILDDIR)
	$(CC) $(OBJECTS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)

run: $(TARGET)
	./$(TARGET)

format:
	clang-format -i $(SOURCES) $(wildcard $(INCDIR)/*.h)

tidy:
	clang-tidy $(SOURCES) -- -I$(INCDIR)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(LIB_OBJECTS) $(TEST_SOURCES) $(TEST_UNITY_SOURCES) | $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(TESTDIR) $(LIB_OBJECTS) $(TEST_SOURCES) $(TEST_UNITY_SOURCES) -o $@