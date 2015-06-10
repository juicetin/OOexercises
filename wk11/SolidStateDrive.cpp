#include "SolidStateDrive.h"

SolidStateDrive::SolidStateDrive()
    : HardDrive()
{

}

SolidStateDrive::SolidStateDrive(const std::string &name, int size)
    : HardDrive(name, size)
    , Part(name)
{

}

SolidStateDrive::SolidStateDrive(const SolidStateDrive &hardDrive)
    : HardDrive(hardDrive.m_name, hardDrive.m_size)
    , Part(hardDrive.m_name)
{

}

SolidStateDrive::~SolidStateDrive()
{

}
