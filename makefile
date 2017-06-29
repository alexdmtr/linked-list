run: build
	./build

build: main.cpp linked_list.hpp
	g++ -Wall -std=c++11 main.cpp -o build

clean:
	rm ./build