CC?=gcc
DBG?=gdb

CSRC:=$(wildcard tests/*.c)
CSRC+=munit/munit.c

CFLAGS:=-Og -g -Wall -Werror -Wextra -MMD -Imunit/ -Iinclude/
LFLAGS:=

BIN:=build/test

$(BIN): $(CSRC)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LFLAGS) $(CSRC) -o $@

.PHONY: test clean bear

all: $(BIN)

clean:
	rm -rf build/

bear:
	./util/bear.sh

-include build/*.c.d
