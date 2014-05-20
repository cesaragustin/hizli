CC=gcc
CFLAGS=-g -O5 -freorder-blocks -Wall -Wextra -Isrc -DNDEBUG
LDFLAGS=-lm

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

all: tests

dev: CFLAGS=-g -O5 -freorder-blocks -Wall -Wextra -Isrc
dev: all

build:
	@mkdir -p bin

.PHONY: tests
tests: $(TESTS)
#	sh ./tests/runtests.sh	

$(TESTS): $(OBJECTS)

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	rm -f *~ bin/*~ src/*~ tests/*~

BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true

