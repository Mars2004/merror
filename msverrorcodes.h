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


#ifndef MARSTECH_ERROR_CODES_H
#define MARSTECH_ERROR_CODES_H


#include "MsvError.h"


/********************************************************************************************************************************
*															Success error codes
********************************************************************************************************************************/


/**************************************************************************************************//**
* @brief			Success errorcode.
* @details		Main success errorcode without any added information.
* @see			MsvErrorCode
******************************************************************************************************/
MsvErrorCode const MSV_SUCCESS							= 0x00000000;


/********************************************************************************************************************************
*															Info error codes
********************************************************************************************************************************/


MsvErrorCode const MSV_ALREADY_INITIALIZED_INFO		= 0x40000000;
MsvErrorCode const MSV_NOT_INITIALIZED_INFO			= 0x40000001;
MsvErrorCode const MSV_ALREADY_RUNNING_INFO			= 0x40000002;
MsvErrorCode const MSV_NOT_RUNNING_INFO				= 0x40000003;
MsvErrorCode const MSV_ALREADY_REQUESTED_INFO		= 0x40000004;
MsvErrorCode const MSV_ALREADY_REGISTERED_INFO		= 0x40000005;
MsvErrorCode const MSV_NOT_REGISTERED_INFO			= 0xC0000006;
MsvErrorCode const MSV_ALREADY_SET_INFO				= 0xC0000007;
MsvErrorCode const MSV_NOT_SET_INFO						= 0xC0000008;


/********************************************************************************************************************************
*															Warning error codes
********************************************************************************************************************************/


MsvErrorCode const MSV_STILL_RUNNING_WARN				= 0x80000000;


/********************************************************************************************************************************
*															Error error codes
********************************************************************************************************************************/


MsvErrorCode const MSV_ALLOCATION_ERROR				= 0xC0000000;
MsvErrorCode const MSV_NOT_INITIALIZED_ERROR			= 0xC0000001;
MsvErrorCode const MSV_NOT_REQUESTED_ERROR			= 0xC0000002;


#endif // !MARSTECH_ERROR_CODES_H

/** @} */	//End of group MPLS.
