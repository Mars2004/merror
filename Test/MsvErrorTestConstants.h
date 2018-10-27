

#ifndef MARSTECH_ERROR_TEST_CONSTANTS_H
#define MARSTECH_ERROR_TEST_CONSTANTS_H


#include "../msverrorcodes.h"


MsvErrorCode const MSV_SUCCESS_MIN = 0x00000000;
MsvErrorCode const MSV_SUCCESS_MIDDLE = 0x0000FFFF;
MsvErrorCode const MSV_SUCCESS_MAX = 0x0FFFFFFF;

MsvErrorCode const MSV_INFO_MIN = 0x40000000;
MsvErrorCode const MSV_INFO_MIDDLE = 0x4000FFFF;
MsvErrorCode const MSV_INFO_MAX = 0x4FFFFFFF;

MsvErrorCode const MSV_WARN_MIN = 0x80000000;
MsvErrorCode const MSV_WARN_MIDDLE = 0x8000FFFF;
MsvErrorCode const MSV_WARN_MAX = 0x8FFFFFFF;

MsvErrorCode const MSV_ERROR_MIN = 0xC0000000;
MsvErrorCode const MSV_ERROR_MIDDLE = 0xC000FFFF;
MsvErrorCode const MSV_ERROR_MAX = 0xCFFFFFFF;


#endif // !MARSTECH_ERROR_TEST_CONSTANTS_H
