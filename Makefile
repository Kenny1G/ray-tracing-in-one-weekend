#Targets for makefile
APPLICATION = build/raytracer.bin

all: $(APPLICATION)

CC = g++
CXXFLAGS = -Iinclude -Wall -pedantic -Wextra -g


build/%.bin: build/%.o | build
	$(CC) $(CXXFLAGS) $< -o $@

build/%.o: %.cc | build
	$(CC) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

run: $(APPLICATION)
	$< > out.ppm

clean:
	rm -rf build

vpath %.cc src
vpath %.h include
vpath %.o build

%.bin: build/%.bin ;
%.o: build/%.o ;
