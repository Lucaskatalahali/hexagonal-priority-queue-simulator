all: compile run

compile:
	g++ -I ./include -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include -o ./lib/Helper.o -c ./src/Helper.cpp
	g++ -I ./include -o ./lib/Hexagon.o -c ./src/Hexagon.cpp
	g++ -I ./include -o ./lib/HexagonList.o -c ./src/HexagonList.cpp
	g++ -I ./include -o ./lib/main.o -c ./src/main.cpp

	g++ ./lib/BST.o ./lib/Helper.o ./lib/Hexagon.o ./lib/HexagonList.o ./lib/main.o -o ./bin/main.exe

run:
	./bin/main.exe
