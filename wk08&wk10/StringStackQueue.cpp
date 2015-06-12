#include "StringStackQueue.h"
StringStackQueue::StringStackQueue() : StringStack(), StringQueue()
{
	
}

StringStackQueue::~StringStackQueue()
{

}

bool StringStackQueue::empty() const 
{
    return _deque.empty();	
}

size_t StringStackQueue::size() const 
{
    return _deque.size();
}

const std::string& StringStackQueue::front() const 
{
    return _deque.front();
}

//Queue(FIFO)
void StringStackQueue::enqueue(const std::string &string) 
{
    _deque.push_back(string);
}

//Queue(FIFO)
std::string StringStackQueue::dequeue() 
{
    std::string front;
    if (!_deque.empty())
    {
        front = _deque.front();
        _deque.pop_front();
    }
    return front;
}

StringStackQueue& StringStackQueue::operator=(const StringQueue &queue) 
{
    //*this = static_cast<StringStackQueue*>(queue);
    this->_deque = static_cast<const StringStackQueue&>(queue)._deque; 
    return *this;
}

//Stack(FILO)
const std::string& StringStackQueue::peek() const 
{
    return _deque.front();	
}

//Stack(FILO)
void StringStackQueue::push(const std::string &string) 
{
    _deque.push_front(string);
}

//Stack(FILO)
std::string StringStackQueue::pop() 
{
    std::string front;
    if (!_deque.empty())
    {
        front = _deque.front();
        _deque.pop_front();
    }
    return front;
}

StringStackQueue& StringStackQueue::operator=(const StringStack &stack) 
{
    this->_deque = static_cast<const StringStackQueue&>(stack)._deque;
    return *this;
}
