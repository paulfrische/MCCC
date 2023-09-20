CC = clang
OUT = build

DEFINES = -DLEVEL=5

CFLAGS = -Wall -Wextra -g -std=c11
LDFLAGS = lib/glfw/src/libglfw3.a -lm
INCLUDE = -Ilib/glfw/include

SRCS = $(wildcard src/*.c src/**/*.c)
OBJ = $(SRCS:.c=.o)

libs:
	cd lib/glfw && cmake . && make

test: all
	./build/out

all: libs program

program: $(OBJ)
	mkdir -p $(OUT)
	$(CC) -o $(OUT)/out $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(DEFINES)

.PHONY: clean
clean:
	rm -rdf build $(OBJ)
