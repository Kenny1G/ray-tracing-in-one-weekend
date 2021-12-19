all:
	g++ -Wall -pedantic -Wextra -g src/main.cc -o build/rayt

clean:
	rm build/rayt
