run: build
	./build

build: main.cpp linked_list.hpp
	g++ -g -Wall -Wfatal-errors -std=c++11 main.cpp -o build

clean:
	rm ./build