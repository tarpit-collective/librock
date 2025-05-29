CC?=gcc
DBG?=gdb

CSRC:=$(wildcard tests/*.c)
CSRC+=deps/munit/munit.c

CFLAGS:=-Og -g -Wall -Werror -Wextra -MMD -Ideps/munit/ -Iinclude/
LFLAGS:=

BIN:=build/test

$(BIN): $(CSRC)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LFLAGS) $(CSRC) -o $@

.PHONY: test clean bear

all: $(BIN)

clean:
	rm -rf build/

typst:
	typst watch doc/design.typ

bear:
	./scripts/bear.sh

-include build/*.c.d
