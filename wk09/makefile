all: Vector* Euclidean*
	@g++ -g -c EuclideanVector.cpp
	@g++ -g -c main.cpp
	@g++ -g -c VectorArithmeticException.h
	@g++ -g -c VectorAssignmentException.h
	@g++ -g -c VectorIndexOutOfBoundsException.h
	@g++ -g  EuclideanVector.o main.o -lm -o main
