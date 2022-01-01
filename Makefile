exec		:= bin/sciphox
sources		:= $(wildcard src/*.c)
platform	:= $(shell uname -s)

objects		:= $(patsubst src/%, object/%, $(sources:.c=.o))
shared_o	:= $(patsubst src/%, shared/%, $(sources:.c=.o))
shared_so	:= $(patsubst src/%, shared/lib%, $(sources:.c=.so))
static		:= $(patsubst src/%, static/lib%, $(sources:.c=.a))

flags = -g

all: $(objects) $(shared_o) $(shared_so) $(static) $(exec)

$(exec): $(objects)
	-gcc $(objects) $(flags) -o $(exec)

object/%.o: src/%.c
	-gcc $(flags) -I .include/ -c $< -o $@

shared/%.o: src/%.c
	-gcc $(flags) -I .include/ -fPIC -c $< -o $@

shared/lib%.so: shared/%.o
	-gcc -shared -o $@ $<
	-rm shared/*.o

static/lib%.a: object/%.o
	-ar rcs $@ $<

setup:
	-mkdir bin
	-mkdir bin/x64
	-mkdir bin/window
	-mkdir bin/macos
	
	-mkdir object
	-mkdir object/x64
	-mkdir object/window
	-mkdir object/macos
	
	-mkdir shared
	-mkdir shared/x64
	-mkdir shared/window
	-mkdir shared/macos
	
	-mkdir static
	-mkdir static/x64
	-mkdir static/window
	-mkdir static/macos

clean:
	-rm -r bin/*
	-rm -r object/*
	-rm -r shared/*
	-rm -r static/*