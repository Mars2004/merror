/**************************************************************************************************//**
* @defgroup		MSVERROR MarsTech Error Handling
* @brief			MarsTech Error
* @details		Contains implementation and all definitions of MarsTech Error.
* @copyright	GNU General Public License (GPLv3).
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @file
* @brief			MarsTech Error
* @details		Contains implementation and all definitions of MarsTech Error.
* @author		Martin Svoboda
* @date			25.09.2018
* @copyright	GNU General Public License (GPLv3).
******************************************************************************************************/


/*
This file is part of MarsTech Error.

MarsTech Error is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MarsTech Promise Like Syntax is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar. If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef MARSTECH_ERROR_H
#define MARSTECH_ERROR_H


#include "mheaders/MsvCompiler.h"
MSV_DISABLE_ALL_WARNINGS

#include <cstdint>

MSV_ENABLE_WARNINGS


/**************************************************************************************************//**
* @brief			MarsTech ErrorCode type.
* @details		Typedef from int32_t. It is 4-byte type (DWORD) and its two highest bits is severity.
* @see			MsvSuccessMask
* @see			MsvInfoMask
* @see			MsvWarnMask
* @see			MsvErrorMask
******************************************************************************************************/
typedef int32_t MsvErrorCode;


/**************************************************************************************************//**
* @brief			Success errorcode mask.
* @details		All errorcodes with this mask (MsvErrorCode & MsvSuccessMask) are success.
* @see			MsvErrorCode
******************************************************************************************************/
MsvErrorCode const MsvSuccessMask = 0x00000000;

/**************************************************************************************************//**
* @brief			Info errorcode mask.
* @details		All errorcodes with this mask (MsvErrorCode & MsvInfoMask) are info.
* @see			MsvErrorCode
******************************************************************************************************/
MsvErrorCode const MsvInfoMask = 0x40000000;

/**************************************************************************************************//**
* @brief			Warning errorcode mask.
* @details		All errorcodes with this mask (MsvErrorCode & MsvWarnMask) are warning.
* @see			MsvErrorCode
******************************************************************************************************/
MsvErrorCode const MsvWarnMask = 0x80000000;

/**************************************************************************************************//**
* @brief			Error errorcode mask.
* @details		All errorcodes with this mask (MsvErrorCode & MsvErrorMask) are error.
* @see			MsvErrorCode
******************************************************************************************************/
MsvErrorCode const MsvErrorMask = 0xC0000000;


/**************************************************************************************************//**
* @def			MSV_IS_SUCCESS(checkErrorCode)
* @brief			Check success errorcode.
* @details		Checks if checkErrorCode is success and returns bool result.
* @param[in]	checkErrorCode		The errorcode to check.
* @retval		true					If checkErrorCode is success.
* @retval		false					If checkErrorCode is info, warning or error.
* @see			MsvErrorCode
* @see			MsvSuccessMask
******************************************************************************************************/
#define MSV_IS_SUCCESS(checkErrorCode) (((checkErrorCode) & 0xC0000000) == MsvSuccessMask)

/**************************************************************************************************//**
* @def			MSV_IS_INFO(checkErrorCode)
* @brief			Check info errorcode.
* @details		Checks if checkErrorCode is info and returns bool result.
* @param[in]	checkErrorCode		The errorcode to check.
* @retval		true					If checkErrorCode is info.
* @retval		false					If checkErrorCode is success, warning or error.
* @see			MsvErrorCode
* @see			MsvInfoMask
******************************************************************************************************/
#define MSV_IS_INFO(checkErrorCode) (((checkErrorCode) & 0xC0000000) == MsvInfoMask)

/**************************************************************************************************//**
* @def			MSV_IS_WARN(checkErrorCode)
* @brief			Check warning errorcode.
* @details		Checks if checkErrorCode is warning and returns bool result.
* @param[in]	checkErrorCode		The errorcode to check.
* @retval		true					If checkErrorCode is warning.
* @retval		false					If checkErrorCode is success, info or error.
* @see			MsvErrorCode
* @see			MsvWarnMask
******************************************************************************************************/
#define MSV_IS_WARN(checkErrorCode) (((checkErrorCode) & 0xC0000000) == MsvWarnMask)

/**************************************************************************************************//**
* @def			MSV_IS_WARN(checkErrorCode)
* @brief			Check error errorcode.
* @details		Checks if checkErrorCode is error and returns bool result.
* @param[in]	checkErrorCode		The errorcode to check.
* @retval		true					If checkErrorCode is error.
* @retval		false					If checkErrorCode is success, info or warning.
* @see			MsvErrorCode
* @see			MsvErrorMask
******************************************************************************************************/
#define MSV_IS_ERROR(checkErrorCode) (((checkErrorCode) & 0xC0000000) == MsvErrorMask)


/**************************************************************************************************//**
* @def			MSV_FAILED(checkErrorCode)
* @brief			Check failed.
* @details		Checks if checkErrorCode is error or warning and returns bool result.
* @param[in]	checkErrorCode		The errorcode to check.
* @retval		true					If checkErrorCode is error or warning.
* @retval		false					If checkErrorCode is success or info.
* @see			MsvErrorCode
* @see			MSV_SUCCEEDED
******************************************************************************************************/
#define MSV_FAILED(checkErrorCode) ((checkErrorCode) < 0)

/**************************************************************************************************//**
* @def			MSV_SUCCEEDED(checkErrorCode)
* @brief			Check succeeded.
* @details		Checks if checkErrorCode is success or info and returns bool result.
* @param[in]	checkErrorCode		The errorcode to check.
* @retval		true					If checkErrorCode is success or info.
* @retval		false					If checkErrorCode is warning or error.
* @see			MsvErrorCode
* @see			MSV_SUCCEEDED
******************************************************************************************************/
#define MSV_SUCCEEDED(checkErrorCode) ((checkErrorCode) >= 0)

/**************************************************************************************************//**
* @def			MSV_RETURN_FAILED(checkErrorCode)
* @brief			Check and return failed.
* @details		Checks if checkErrorCode is error or warning. Returns (calls return of current function/method)
*					recieved errorcode if failed errorcode is received.
* @param[in]	checkErrorCode		The errorcode to check.
* @see			MsvErrorCode
* @see			MSV_FAILED
* @warning		Ends current function/method if failed errorcode is received.
******************************************************************************************************/
#define MSV_RETURN_FAILED(checkErrorCode) \
{ \
	MsvErrorCode msvErrRF = (checkErrorCode); \
	if (MSV_FAILED(msvErrRF)) { return msvErrRF; } \
}

/**************************************************************************************************//**
* @def			MSV_BREAK_FAILED(checkErrorCode)
* @brief			Check and break failed.
* @details		Checks if checkErrorCode is error or warning. Breaks current loop if failed errorcode is received.
* @param[in]	checkErrorCode		The errorcode to check.
* @see			MsvErrorCode
* @see			MSV_FAILED
* @warning		Ends current loop if failed errorcode is received.
******************************************************************************************************/
#define MSV_BREAK_FAILED(checkErrorCode) if (MSV_FAILED(checkErrorCode)) { break; }

/**************************************************************************************************//**
* @def			MSV_CONTINUE_FAILED(checkErrorCode)
* @brief			Check and continue failed.
* @details		Checks if checkErrorCode is error or warning. Invokes continue of current loop if failed
*					errorcode is received.
* @param[in]	checkErrorCode		The errorcode to check.
* @see			MsvErrorCode
* @see			MSV_FAILED
* @warning		Invokes continue of current loop if failed errorcode is received.
******************************************************************************************************/
#define MSV_CONTINUE_FAILED(checkErrorCode) if (MSV_FAILED(checkErrorCode)) { continue; }


#endif // !MARSTECH_ERROR_H

/** @} */	//End of group MPLS.
