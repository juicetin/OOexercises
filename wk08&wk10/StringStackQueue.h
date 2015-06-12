#ifndef STRINGSTACKQUEUE_H
#define STRINGSTACKQUEUE_H

#include <string>
#include <deque>

#include "StringQueue.h"
#include "StringStack.h"

class StringStackQueue : public StringStack, public StringQueue
{
public:
	StringStackQueue();
	~StringStackQueue();

	bool empty() const;
	size_t size() const;
	const std::string& front() const;
	void enqueue(const std::string &string);
	std::string dequeue();
	StringStackQueue& operator=(const StringQueue &queue);
	const std::string& peek() const;
	void push(const std::string &string);
	std::string pop();
	StringStackQueue& operator=(const StringStack &stack);

private:
    std::deque<std::string> _deque;
};

#endif // STRINGSTACKQUEUE_H


