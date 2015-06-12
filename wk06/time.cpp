#include "time.h"

#include <sstream>

Time::Time(int hours, int minutes, int seconds)
	: m_seconds(hours*3600+minutes*60+seconds) {}

Time::~Time() {}

Time::Time(const Time &time)
	: m_seconds(time.m_seconds) 
{}

//Operators
Time& Time::operator=(const Time &time) 
{
	m_seconds = time.m_seconds;
	return *this;
}

Time Time::operator+(const Time &time) const
{
	Time tmp = *this;
	tmp.m_seconds += time.m_seconds;
	return tmp;
}

Time Time::operator-(const Time &time) const
{
	Time tmp = *this;
	tmp.m_seconds -= time.m_seconds;
	return tmp;
}


// Comparators
bool Time::operator==(const Time &time) const
{
	return m_seconds == time.m_seconds;
}

bool Time::operator!=(const Time &time) const
{
	return m_seconds != time.m_seconds;
}

bool Time::operator<(const Time &time) const
{
	return m_seconds < time.m_seconds;
}

bool Time::operator>(const Time &time) const
{
	return m_seconds > time.m_seconds;
}

bool Time::operator<=(const Time &time) const
{
	return m_seconds <= time.m_seconds;
}

bool Time::operator>=(const Time &time) const
{
	return m_seconds >= time.m_seconds;
}

// Getters
double Time::numberOfHours() const
{
	return m_seconds/3600.0;
}

double Time::numberOfMinutes() const
{
	return m_seconds/60.0;
}

int Time::numberOfSeconds() const
{
	return m_seconds;
}

std::string Time::getTimeAsString() const
{
	std::string timeStr = "";
	std::stringstream ss;

	// Hours
	if (numberOfHours() < 10) timeStr += '0';
	ss << (int)numberOfHours();
	timeStr.append(ss.str()).append(":");
	ss.str("");

	// Minutes
	if (m_seconds % 3600 / 60 < 10) timeStr += '0';
	ss << m_seconds % 3600 / 60;
	timeStr.append(ss.str()).append(":");
	ss.str("");

	// Seconds
	if (m_seconds % 60 < 10) timeStr += '0';
	ss << m_seconds % 60;
	timeStr.append(ss.str());

	return timeStr;
}

Time operator+(const Time& lhs, int numberOfSeconds) 
{
	Time tmp = lhs;
	tmp.m_seconds += numberOfSeconds;
	return tmp;
}
