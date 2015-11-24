CXXFLAGS=-std=c++11 -stdlib=libc++ -Wall -O3
LDFLAGS=-lm -larmadillo
OBJ=solver.o altproj.o

sudoku: main.cpp $(OBJ)
	$(CXX) main.cpp -o sudoku $(OBJ) $(CXXFLAGS) $(LDFLAGS)

debug: debug.cpp $(OBJ)
	$(CXX) debug.cpp -o debug $(OBJ) $(CXXFLAGS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

example: example9.csv sudoku
	./sudoku 9 example9.csv solved9.csv

.PHONY: clean example

clean:
	rm $(OBJ) debug sudoku solved9.csv

