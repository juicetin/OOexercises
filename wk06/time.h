#ifndef TIME_H
#define TIME_H

#include <string>

class Time
{
public:
	Time(int hours, int minutes, int seconds);
	Time(const Time &time);
	~Time();

	// Operators
	Time& operator=(const Time &time);
	Time operator+(const Time &time) const;
	Time operator-(const Time &time) const;


	// Comparators
	bool operator==(const Time &time) const;
	bool operator!=(const Time &time) const;
	bool operator<(const Time &time) const;
	bool operator>(const Time &time) const;
	bool operator<=(const Time &time) const;
	bool operator>=(const Time &time) const;

	// Getters
	double numberOfHours() const;
	double numberOfMinutes() const;
	int numberOfSeconds() const;

	std::string getTimeAsString() const;

	// Friends
	friend Time operator+(const Time &lhs, int numberOfSeoncds);

private:
	Time();
	int m_seconds;
};

Time operator+(const Time& lhs, int numberOfSeconds);
#endif
