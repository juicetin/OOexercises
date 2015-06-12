#include "person.h"

using namespace Week4;

Person::Person(std::string firstName, 
		std::string surname, 
		Date dateOfBirth) :
	m_firstName(firstName),
	m_surname(surname),
	m_dateOfBirth(dateOfBirth) {}

Person::~Person() {}

void Person::changeFirstName(std::string firstName)
{
	m_firstName = firstName;
}

std::string Person::getFirstName() const
{
	return m_firstName;
}

void Person::changeSurname(std::string surname)
{
	m_surname = surname;
}

std::string Person::getSurname() const
{
	return m_surname;
}

int Person::getYearOfBirth() const
{
	return m_dateOfBirth.getYear();
}

bool Person::isBornInLeapYear() const
{
	return getYearOfBirth() % 4 == 0;
}

int Person::getCurrentAge() const
{
	return 2015 - getYearOfBirth();
}
