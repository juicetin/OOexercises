#include "date.h"

using namespace Week4;
#include <sstream>

Date::Date(int day, int month, int year) :
	m_day(day),
	m_month(month),
	m_year(year) {}

Date::~Date()
{
	
}

int Date::getYear() const
{
	return m_year;
}

int Date::getMonth() const
{
	return m_month;
}

int Date::getDay() const
{
	return m_day;
}

std::string Date::dateAsString() const
{
	std::stringstream ss;	
	std::string dateString = "";

	if (m_day < 10) dateString += '0';
	ss << m_day;
	dateString.append(ss.str()).append("/");
	ss.str("");

	if (m_month < 10) dateString += '0';
	ss << m_month;
	dateString.append(ss.str()).append("/");
	ss.str("");

	ss << m_year;
	dateString.append(ss.str());

	return dateString;
}
