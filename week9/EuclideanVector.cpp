#include "EuclideanVector.h"
#include "VectorAssignmentException.h"
#include "VectorArithmeticException.h"
#include "VectorIndexOutOfBoundsException.h"

#include <cmath>
#include <exception>
#include <iostream>

/**
 * @brief EuclideanVector constructor which allocates the number of dimensions of the Euclidean vector
 * @param size number of dimensions
 */
Week9::EuclideanVector::EuclideanVector(unsigned int size)
{
	m_vector = new double[size];
	m_size = size;
}

/**
 * @brief EuclideanVector constructor which allocates the number of dimensions of the vector
 * along with a values for each dimensions of the Euclidean vector
 * @param vector
 */
Week9::EuclideanVector::EuclideanVector(const std::vector<double> &vector)
{
	m_vector = new double[vector.size()];
	m_size = vector.size();
	int i = 0;
	for (std::vector<double>::const_iterator it = vector.begin(); it != vector.end(); ++it)
	{
		m_vector[i++] = *it;
	}
}

/**
 * @brief EuclideanVector copy constructor of the vector which creates a new vector with the
 * same values as those stored in a previously created Euclidean vector
 * @param vector an existing euclidean vector
 */
Week9::EuclideanVector::EuclideanVector(const EuclideanVector &vector)
{
	m_vector = new double[vector.size()];
	m_size = vector.size();
	for (int i = 0; i < (int)vector.size(); ++i)
	{
		m_vector[i] = vector[i];
	}
}

Week9::EuclideanVector::~EuclideanVector()
{
	delete[] m_vector;
}

/**
 * @brief operator = assignment operator
 * @param vector the vector which will be assigned from
 * @throws if the current vector and the assignment vector are not equal throws a
 * VectorAssignmentException with the message Incompatible Vector Sizes and the state
 * should not change
 * @return a reference to the newly assigned vector
 */
Week9::EuclideanVector& Week9::EuclideanVector::operator=(const EuclideanVector &vector)
{
	try
	{
		if (this->size() != vector.size())
		{
			throw Week9::VectorAssignmentException("Incompatible Vector Sizes");
		}

		for (int i = 0; i < (int)vector.size(); ++i)
		{
			m_vector[i] = vector[i];
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return *this;
}

/**
 * @brief size returns the number of dimensions of the vector
 * @return the number of dimensions of the vector
 */
unsigned int Week9::EuclideanVector::size() const
{
	return m_size;
}

/**
 * @brief operator == equality operator
 * @param vector the vector to compare with
 * @return if item v1[i] == v2[i] for all i where equality is defined as
 * values which are with 0.01 of one another than return true otherwise false
 *
 */
bool Week9::EuclideanVector::operator==(const EuclideanVector &vector) const
{
	if (m_size != (int)vector.size())
	{
		return false;
	}

	for (int i = 0; i < m_size; ++i)
	{
		if (fabs(m_vector[i] -  vector[i]) > 0.01)
		{
			return false;
		}
	}
	return true;
}

/**
 * @brief operator == inequality operator
 * @param vector the vector to compare with
 * @return if item v1[i] == v2[i] for all i where equality is defined as
 * values which are with 0.01 of one another than return false otherwise true
 *
 */
bool Week9::EuclideanVector::operator!=(const EuclideanVector &vector) const
{
	if (m_size != (int)vector.size())
	{
		return true;
	}

	for (int i = 0; i < (int)vector.size(); ++i)
	{
		if (fabs(m_vector[i] - vector[i]) > 0.01)
		{
			return true;
		}
	}

	return false;
}

/**
 * @brief length calculates the length of a vector
 * @return the length of the vector
 */
double Week9::EuclideanVector::length() const
{
	double sum = 0;
	for (int i = 0; i < m_size; ++i)
	{
		sum += (m_vector[i] * m_vector[i]);
	}
	return sqrt(sum);
}

/**
 * @brief dotProduct calculates the dot product of the vector compared to another vector
 * @param vector a comparison vector
 * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
 * with the message "Vectors are not the same size"
 * @return the dot producot of this vector and another vector
 */
double Week9::EuclideanVector::dotProduct(const EuclideanVector &vector) const
{
	try
	{
		if (m_size != (int)vector.size())
		{
			throw Week9::VectorArithmeticException("Vectors are not the same size");
		}

		double ret = 0;
		for (int i = 0; i < m_size; ++i)
		{
			ret += m_vector[i] * vector[i];		
		}
		return ret;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

/**
 * @brief unitVector calculates the unit vector
 * @return the unitVector
 */
Week9::EuclideanVector Week9::EuclideanVector::unitVector() const
{
	std::vector<double> tmp;
	double length = this->length();
	for (int i = 0; i < m_size; ++i)
	{
		tmp.push_back(m_vector[i] / length);
	}
	return Week9::EuclideanVector(tmp);
}

/**
 * @brief operator + adds two vectors together
 * @param vector the second vector to add to the current vector
 * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
 * with the message "Vectors are not the same size"
 * @return the vector which is the result of adding this vector with the second vector
 */
Week9::EuclideanVector Week9::EuclideanVector::operator+(const EuclideanVector &vector) const
{
	try
	{
		if (m_size != (int)vector.size())
		{
			throw Week9::VectorArithmeticException("Vectors are not the same size");
		}

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Week9::EuclideanVector tmp(*this);
	for (int i = 0; i < m_size; ++i)
	{
		tmp[i] += vector[i];
	}
	return tmp;
}

/**
 * @brief operator - subtract two vectors away from one another
 * @param vector the second vector to subtract away from the current vector
 * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
 * with the message "Vectors are not the same size"
 * @return the vector which is the result of subtracting this vector away from the second vector
 */
Week9::EuclideanVector Week9::EuclideanVector::operator-(const EuclideanVector &vector) const
{
	try
	{
		if (m_size != (int)vector.size())
		{
			throw Week9::VectorArithmeticException("Vectors are not the same size");
		}

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Week9::EuclideanVector tmp(*this);
	for (int i = 0; i < m_size; ++i)
	{
		tmp[i] -= vector[i];
	}
	return tmp;
}

/**
 * @brief operator += add a second vector to this vector
 * @param vector the second vector to add to the current vector
 * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
 * with the message "Vectors are not the same size"
 * @return a reference to the current vector
 */
Week9::EuclideanVector& Week9::EuclideanVector::operator+=(const EuclideanVector &vector) 
{
	try
	{
		if (m_size != (int)vector.size())
		{
			throw Week9::VectorArithmeticException("Vectors are not the same size");
		}

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	for (int i = 0; i < m_size; ++i)
	{
		m_vector[i] += vector[i];
	}
	return *this;
}

/**
 * @brief operator -= subtract a second vector away from this vector
 * @param vector the second vector to subtract away from the current vector
 * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
 * with the message "Vectors are not the same size"
 * @return a reference to the current vector
 */
Week9::EuclideanVector& Week9::EuclideanVector::operator-=(const EuclideanVector &vector)
{

	try
	{
		if (m_size != (int)vector.size())
		{
			throw Week9::VectorArithmeticException("Vectors are not the same size");
		}

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	for (int i = 0; i < m_size; ++i)
	{
		m_vector[i] -= vector[i];
	}
	return *this;
}

/**
 * @brief operator *= scaling operator
 * @param scalingValue value to scale of values in the vector by
 * @return a vector where each value has been multiplied by the scaling value
 */
Week9::EuclideanVector& Week9::EuclideanVector::operator*=(double scalingValue)
{
	for (int i = 0; i < m_size; ++i)
	{
		m_vector[i] *= scalingValue;
	}
	return *this;
}

/**
 * @brief operator /= scaling operator
 * @param scalingValue value to scale of values in the vector by
 * @return a vector where each value has been divided by the scaling value
 */
Week9::EuclideanVector& Week9::EuclideanVector::operator/=(double scalingValue)
{
	for (int i = 0; i < m_size; ++i)
	{
		m_vector[i] /= scalingValue;	
	}

	return *this;
}

/**
 * @brief operator [] access operator
 * @param index of the value to access
 * @throws if the index is outside the range of the vector than throw
 * VectorIndexOutOfBoundsException with the message
 * "Index is greater than or equal to the allocated size"
 * @return the value at index
 */
double& Week9::EuclideanVector::operator[](unsigned int index)
{
	try
	{
		if (index > m_size - 1 || index < 0)
		{
			throw Week9::VectorIndexOutOfBoundsException("Index is greater than or equal to the allocated size");
		}
		else
		{
			return m_vector[index];
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}

/**
 * @brief operator [] access operator
 * @param index of the value to access
 * @throws if the index is outside the range of the vector than throw
 * VectorIndexOutOfBoundsException with the message
 * "Index is greater than or equal to the allocated size"
 * @return the value at index
 */
const double& Week9::EuclideanVector::operator[](unsigned int index) const
{
	try
	{
		if (index > m_size - 1 || index < 0)
		{
			throw Week9::VectorIndexOutOfBoundsException("Index is greater than or equal to the allocated size");
		}
		else
		{
			return m_vector[index];
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}
