#include "CubeReader.h"

CubeReader::CubeReader(const char *mapName)
{
}

char* CubeReader::getCube()
{
    return cube;
}

int CubeReader::getTimeOut() 
{
    return timeOut;
}

int CubeReader::getThreashold()
{
    return threshold;
}
