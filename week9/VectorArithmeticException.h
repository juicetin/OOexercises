#ifndef VECTORARITHMETICEXCEPTION_H
#define VECTORARITHMETICEXCEPTION_H
#include "VectorRuntimeException.h"
namespace Week9
{
	class VectorArithmeticException : public VectorRuntimeException
	{
		public:
			VectorArithmeticException(const char *message) 
				: VectorRuntimeException(message)
			{

			}	

			virtual ~VectorArithmeticException()
			{

			}
	};
}
#endif // VECTORARITHMETICEXCEPTION_H
