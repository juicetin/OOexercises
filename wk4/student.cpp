#include "student.h"

using namespace Week4;

Student::Student(const std::string &givenName, const std::string &surname,
		const Date &date, const std::string &degree) :
	Person(givenName, surname, date),
	m_degree(new std::string(degree))
{

}

Student::~Student()
{
	delete m_degree;
}

std::string Student::getRecord() const
{
	std::string record = "Name: ";
	record.append(getFirstName()).append(" ").append(getSurname()).append("\n");

	record.append("Date Of Birth: ").append(m_dateOfBirth.dateAsString()).append("\n");

	record.append(*m_degree).append("\n");

	return record;
}
