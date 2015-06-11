#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include <string>

namespace Week4
{
	class Person
	{
	public:
		Person(std::string firstName, 
				std::string surname, 
				Date dateOfBirth);
		virtual ~Person();

		void changeFirstName(std::string firstName);
		std::string getFirstName() const;

		void changeSurname(std::string surname);
		std::string getSurname() const;

		int getYearOfBirth() const;
		bool isBornInLeapYear() const;

		int getCurrentAge() const;

		virtual std::string getRecord() const = 0;

	protected:
		std::string m_firstName;
		std::string m_surname;
		Date m_dateOfBirth;
	};
}
#endif

