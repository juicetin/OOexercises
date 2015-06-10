#include "BluRayDrive.h"

BluRayDrive::BluRayDrive()
    : DiscDrive()
{

}

BluRayDrive::BluRayDrive(const std::string &name, int readSpeed)
    : DiscDrive(name, readSpeed)
    , Part(name)
{

}

BluRayDrive::BluRayDrive(const BluRayDrive &discDrive)
    : DiscDrive(discDrive.m_name, discDrive.m_readSpeed)
    , Part(discDrive.m_name)
{

}

BluRayDrive::~BluRayDrive()
{

}

std::string BluRayDrive::getPartInformation() const
{
    std::string partInformation = this->DiscDrive::getPartInformation();
    partInformation.replace(0, 12, "Blu-ray Drive: ");
    return partInformation;
}
