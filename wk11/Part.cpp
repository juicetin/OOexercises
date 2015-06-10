#include "Part.h"

#include <iostream>
using namespace std;
Part::Part() : m_name(std::string())
{
//    cout << "fuck you default" << endl;
}

Part::Part(const std::string &name) : m_name(name)
{
//    cout << "yes pls" << endl;
}

Part::Part(const Part &part) : m_name(part.m_name)
{

}

Part::~Part()
{

}

const std::string& Part::getPartName() const
{
    return m_name;
}

void Part::itoa(int m_num, char *num, int base) const
{
    std::stringstream ss;
    ss << m_num;
    std::string s = ss.str();
    strcpy(num, s.c_str());
}
