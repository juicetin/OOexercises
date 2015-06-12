#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include "GenericQueue.h"
#include "GenericStack.h"

#include "StringQueue.h"
#include "StringStack.h"

#include <deque>

namespace Week10
{
	template<class T>
	class StackQueue : public Week10::Stack<T>, public Week10::Queue<T>
	{
	public:
		StackQueue(){}
		~StackQueue(){}

		bool empty() const
		{
			return _deque.empty();
		}

		size_t size() const
		{
			return _deque.size();
		}

		const T& front() const
		{
			return _deque.front();
		}

		void enqueue(const T &t)
		{
			_deque.push_back(t);
		}

		T dequeue()
		{
			T front;
			if (!_deque.empty())
			{
				front = _deque.front();
				_deque.pop_front();
			}
			return front;
		}

		StackQueue<T>& operator=(const Week10::Queue<T> &queue)
		{
			this->_deque = static_cast<const Week10::StackQueue<T>&>(queue)._deque;
			return *this;	
		}

		const T& peek() const
		{
			return _deque.front();
		}

		void push(const T &t)
		{
			_deque.push_front(t);
		}

		T pop()
		{
			T front;
			if (!_deque.empty())
			{
				front = _deque.front();
				_deque.pop_front();
			}
			return front;
		}

		StackQueue<T>& operator=(const Week10::Stack<T> &stack)
		{
			this->_deque = static_cast<const Week10::StackQueue<T>&>(stack)._deque;
			return *this;
		}

	private:
		std::deque<T> _deque;
	};
}
#endif // STACKQUEUE_H
