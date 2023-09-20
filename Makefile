CC = clang
OUT = build

DEFINES = -DLEVEL=5

CFLAGS = -Wall -Wextra -g -std=c11
LDFLAGS = lib/glfw/src/libglfw3.a -lm lib/cglm/libcglm.a
INCLUDE = -Ilib/glfw/include -Ilib/glad/include -Ilib/cglm/include

SRCS = $(wildcard src/*.c src/**/*.c) lib/glad/src/gl.c
OBJ = $(SRCS:.c=.o)

libs:
	cd lib/glfw && cmake . && make
	cd lib/cglm && cmake . -DCGLM_STATIC=ON && make

test: all
	./build/out

all: libs program

program: $(OBJ)
	mkdir -p $(OUT)
	$(CC) -o $(OUT)/out $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(INCLUDE) $(CFLAGS) $(DEFINES)

.PHONY: clean
clean:
	rm -rdf build $(OBJ)
