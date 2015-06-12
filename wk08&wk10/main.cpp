#include <iostream>
#include "StackQueue.h"
#include <string>

using namespace Week10;
using namespace std;

class SimpleClass
{
public:
    SimpleClass()
    : m_i(0)
    {

    }

    SimpleClass(int i)
    : m_i(i)
    {

    }

    SimpleClass& operator=(const SimpleClass& simpleClass)
    {
        m_i = simpleClass.m_i;
        return *this;
    }

    int get() const
    {
        return m_i;
    }

private:
    int m_i;
};

using namespace Week10;

bool constructionTest()
{
    StackQueue<int> s;
    return s.empty() && 0 == s.size();
}

bool addAsIfStackTest()
{
    StackQueue<std::string> s;
    s.push("World");
    s.push("Hello");
    return !s.empty() && 2 == s.size();
}

bool peekTest()
{
    StackQueue<std::string> s;
    s.push("World");
    s.push("Hello");

    return "Hello" == s.peek() && 2 == s.size();
}

bool popTest()
{
    StackQueue<std::string> s;
    s.push("World");
    s.push("Hello");

    std::string first = s.pop();
    std::string second = s.pop();

    // cout << first << " " << second << endl;

    return "Hello" == first && "World" == second;
}

bool popAllTest()
{
    StackQueue<std::string> s;
    s.push("World");
    s.push("Hello");

    std::string first = s.pop();
    std::string second = s.pop();
    std::string third =  s.pop();

    return "Hello" == first && "World" == second && third.empty();
}

bool popAllTest2()
{
    StackQueue<SimpleClass> s;
    s.push(SimpleClass(2));
    s.push(SimpleClass(1));

    SimpleClass first = s.pop();
    SimpleClass second = s.pop();
    SimpleClass third =  s.pop();

    return 1 == first.get() && 2 == second.get() && 0 == third.get();
}

bool addAsIfQueueTest()
{
    StackQueue<std::string> s;
    s.enqueue("Hello");
    s.enqueue("World");
    return !s.empty() && 2 == s.size();
}

bool frontTest()
{
    StackQueue<std::string> s;
    s.enqueue("Hello");
    s.enqueue("World");

    std::string first = s.front();

    return "Hello" == first && 2 == s.size();
}

bool dequeTest()
{
    StackQueue<std::string> s;
    s.enqueue("Hello");
    s.enqueue("World");

    std::string first = s.dequeue();
    std::string second = s.dequeue();

    return "Hello" == first && "World" == second;
}

bool dequeAllTest()
{
    StackQueue<std::string> s;
    s.enqueue("Hello");
    s.enqueue("World");

    std::string first = s.dequeue();
    std::string second = s.dequeue();
    std::string third = s.dequeue();

    return "Hello" == first && "World" == second && third.empty();
}

bool assignmentOperatorTest()
{
    Week10::Queue<std::string> *queue = new StackQueue<std::string>();
    queue->enqueue("Hello");
    queue->enqueue("World");

    Week10::Stack<std::string> *stack = new StackQueue<std::string>();
    stack->push("World");
    stack->push("Hello");

    StackQueue<std::string> both;
    both = *queue;

    if (2 == both.size() && "Hello" == both.dequeue() && "World" == both.dequeue() && both.empty())
    {
        both = *stack;
        if (2 == both.size() && "Hello" == both.pop() && "World" == both.pop() && both.empty())
        {
            return (2 == queue->size() && 2 == stack->size());
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main(int argc, char *argv[])
{
    int numberOfTestsFailed = 0;
    if (!constructionTest())
    {
        cout << "construction" << endl;
        numberOfTestsFailed++;
    }
    if (!addAsIfStackTest())
    {
        cout << "add as if stack" << endl;
        numberOfTestsFailed++;
    }
    if (!peekTest())
    {
        cout << "peek" << endl;
        numberOfTestsFailed++;
    }
    if (!popTest())
    {
        cout << "pop" << endl;
        numberOfTestsFailed++;
    }
    if (!popAllTest())
    {
        cout << "popAll" << endl;
        numberOfTestsFailed++;
    }
    if (!popAllTest2())
    {
        cout << "popAll2" << endl;
        numberOfTestsFailed++;
    }
    if (!addAsIfQueueTest())
    {
        cout << "add as if queue" << endl;
        numberOfTestsFailed++;
    }
    if (!frontTest())
    {
        cout << "front" << endl;
        numberOfTestsFailed++;
    }
    if (!dequeTest())
    {
        cout << "dequeue" << endl;
        numberOfTestsFailed++;
    }
    if (!dequeAllTest())
    {
        cout << "dequeueAll" << endl;
        numberOfTestsFailed++;
    }
    if (!assignmentOperatorTest())
    {
        cout << "assignment operator" << endl;
        numberOfTestsFailed++;
    }
    if (0 == numberOfTestsFailed)
    {
        std::cout << "All Tests Passed!" << std::endl;
    }
    else
    {
        std::cout << numberOfTestsFailed << " Tests Failed" << std::endl;
    }
}
