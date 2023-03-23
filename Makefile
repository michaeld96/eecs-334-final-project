build:
	g++ -std=c++1z -g3 -Wall -O3 src/main.cpp -o main
clean:
	rm -f *.exe *.o main
	rm -rf *.dSYM