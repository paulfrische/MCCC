CC = clang
OUT = build
CFLAGS = -Wall -Wextra -g
SRCS = $(wildcard src/*.c src/**/*.c)
DEFINES = -DLEVEL=5

all:
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(DEFINES) $(SRCS) -o $(OUT)/out

test: all
	echo $(shell pwd)
	./build/out

.PHONY: clean
clean:
	rm -rdf build
	rm -rdf *.o
