#include "userinterface.h"

#include <iostream>
using namespace std;

// Add implementation code here
UserInterface::UserInterface(int height, int width)
{
	m_height = height;
	m_width = width;
}

int UserInterface::getInterfaceHeight()
{
	return m_height;
}

int UserInterface::getInterfaceWidth() 
{
	return m_width;
}

Singleton *UserInterface::getInstance(int height, int width)
{
	if (!s_initialised)
	{
		s_singletonInstance = new UserInterface(height, width);
		s_initialised = true;
	}
	return Singleton::getInstance();
}
