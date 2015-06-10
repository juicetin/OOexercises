#include "DVDDrive.h"

DVDDrive::DVDDrive()
    : DiscDrive()
{

}

DVDDrive::DVDDrive(const std::string &name, int readSpeed)
    : DiscDrive(name, readSpeed)
    , Part(name)
{

}

DVDDrive::DVDDrive(const DVDDrive &discDrive)
    : DiscDrive(discDrive.m_name, discDrive.m_readSpeed)
    , Part(discDrive.m_name)
{

}

DVDDrive::~DVDDrive()
{

}

std::string DVDDrive::getPartInformation() const
{
    std::string partInformation = this->DiscDrive::getPartInformation();
    partInformation.replace(0, 12, "DVD Drive: ");
    return partInformation;
}
