.DEFAULT_GOAL := run


maxtrix_multiplication.o: matrix_multiplication.cpp
	g++ -o maxtrix_multiplication.o -c matrix_multiplication.cpp

maxtrix_multiplication: maxtrix_multiplication.o
	g++ -o maxtrix_multiplication maxtrix_multiplication.o

run: maxtrix_multiplication
	./maxtrix_multiplication

clean:
	rm -f *.o 
	rm -f maxtrix_multiplication