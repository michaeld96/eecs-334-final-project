build:
	g++ -std=c++1z -g3 -Wall src/main.cpp -o main
clean:
	rm -f *.exe *.o main
	rm -rf *.dSYM