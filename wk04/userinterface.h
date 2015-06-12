#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "singleton.h"

class UserInterface : Singleton
{
	public:
		// Add public methods here
		int getInterfaceHeight();
		int getInterfaceWidth();
		static Singleton* getInstance(int height, int width);

	private:
		// Add private methods and member variables here
		UserInterface(int height, int width);
		int m_height;
		int m_width;
};

#endif // USERINTERFACE_H

