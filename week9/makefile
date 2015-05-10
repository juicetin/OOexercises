all: Vector* Euclidean*
	@g++ -Wall -g -c EuclideanVector.cpp
	@g++ -Wall -g -c main.cpp
	@g++ -Wall -g -c VectorArithmeticException.h
	@g++ -Wall -g -c VectorAssignmentException.h
	@g++ -Wall -g -c VectorIndexOutOfBoundsException.h
	@g++ -g  EuclideanVector.o main.o -lm -o main
