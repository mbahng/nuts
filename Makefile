
all: 
	g++ -std=c++20 main.cpp card.cpp rankings.cpp -o main
test: 
	g++ -std=c++20 test.cpp card.cpp rankings.cpp -o main
