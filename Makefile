CC = clang
OUT = build
CFLAGS = -Wall -Wextra -g -std=c11
LDFLAGS = lib/glfw/src/libglfw3.a -lm
INCLUDE = -I./lib/glfw/include
SRCS = $(wildcard src/*.c src/**/*.c)
OBJ = $(SRCS:.c=.o)
DEFINES = -DLEVEL=5

libs:
	cd lib/glfw && cmake . && make

all: program

test: program
	./build/out

program: $(OBJ)
	mkdir -p $(OUT)
	$(CC) -o $(OUT)/out $^ $(LDFLAGS) $(DEFINES)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(DEFINES)

.PHONY: clean
clean:
	rm -rdf build $(OBJ)
