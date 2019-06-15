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
* @see			MsvSuccessMask
* @see			MSV_IS_SUCCESS
******************************************************************************************************/
MsvErrorCode const MSV_SUCCESS							= 0x00000000;


/********************************************************************************************************************************
*															Info error codes
********************************************************************************************************************************/


/**************************************************************************************************//**
* @brief			Already initialized.
* @details		When something has been already initialized and trying to initialized it again.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_ALREADY_INITIALIZED_INFO		= 0x40000000;

/**************************************************************************************************//**
* @brief			Not initialized.
* @details		When something is not initialized and trying to uninitialize it.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_NOT_INITIALIZED_INFO			= 0x40000001;

/**************************************************************************************************//**
* @brief			Already running.
* @details		When something is running and trying to start it again.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_ALREADY_RUNNING_INFO			= 0x40000002;

/**************************************************************************************************//**
* @brief			Not running.
* @details		When something is not running and trying to stop it.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_NOT_RUNNING_INFO				= 0x40000003;

/**************************************************************************************************//**
* @brief			Already requested.
* @details		When some action has been already requested.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_ALREADY_REQUESTED_INFO		= 0x40000004;

/**************************************************************************************************//**
* @brief			Already registered.
* @details		When something (usually callback) has been already registered.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_ALREADY_REGISTERED_INFO		= 0x40000005;

/**************************************************************************************************//**
* @brief			Not registered.
* @details		When something (usually callback) is not registered.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_NOT_REGISTERED_INFO			= 0x40000006;

/**************************************************************************************************//**
* @brief			Already set.
* @details		When something has been already set.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_ALREADY_SET_INFO				= 0x40000007;

/**************************************************************************************************//**
* @brief			Not set.
* @details		When something is not set.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_NOT_SET_INFO						= 0x40000008;

/**************************************************************************************************//**
* @brief			Expired
* @details		When something is expired.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_EXPIRED_INFO						= 0x40000009;

/**************************************************************************************************//**
* @brief			Not found.
* @details		When something has not been found.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_NOT_FOUND_INFO					= 0x4000000A;

/**************************************************************************************************//**
* @brief			Already exists.
* @details		When something already exists.
* @see			MsvInfoMask
* @see			MSV_IS_INFO
******************************************************************************************************/
MsvErrorCode const MSV_ALREADY_EXISTS_INFO			= 0x4000000B;


/********************************************************************************************************************************
*															Warning error codes
********************************************************************************************************************************/


/**************************************************************************************************//**
* @brief			Still running warning.
* @details		When something is still running, but it shouldn't.
* @see			MsvWarnMask
* @see			MSV_IS_WARN
******************************************************************************************************/
MsvErrorCode const MSV_STILL_RUNNING_WARN				= 0x80000000;


/********************************************************************************************************************************
*															Error error codes
********************************************************************************************************************************/


/**************************************************************************************************//**
* @brief			Allocation error.
* @details		When create (allocate) some memory/object failed.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_ALLOCATION_ERROR				= 0xC0000000;

/**************************************************************************************************//**
* @brief			Not initialized error.
* @details		When trying to do some action on object which must be initialized before doing this action.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_NOT_INITIALIZED_ERROR			= 0xC0000001;

/**************************************************************************************************//**
* @brief			Not requested error.
* @details		Some action has not been requested, but it should be.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_NOT_REQUESTED_ERROR			= 0xC0000002;

/**************************************************************************************************//**
* @brief			Not found error.
* @details		Some action has not been requested, but it should be.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_NOT_FOUND_ERROR					= 0xC0000003;

/**************************************************************************************************//**
* @brief			Not exists error.
* @details		Something does not exists, but it should be.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_DOES_NOT_EXIST_ERROR			= 0xC0000004;

/**************************************************************************************************//**
* @brief			Already exists error.
* @details		Something already exists, but it shouldn't.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_ALREADY_EXISTS_ERROR			= 0xC0000005;

/**************************************************************************************************//**
* @brief			Parse error.
* @details		Parsing data failed.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_PARSE_ERROR						= 0xC0000006;

/**************************************************************************************************//**
* @brief			Unknown error.
* @details		Something is unknown - some object, ID etc.
* @warning		Do not use it general error. It is ment as unknown object, ID etc.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_UNKNOWN_ERROR					= 0xC0000007;

/**************************************************************************************************//**
* @brief			Invalid data error.
* @details		Some data are invalid. It might parameters, received data, file, etc.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_INVALID_DATA_ERROR				= 0xC0000008;

/**************************************************************************************************//**
* @brief			Open error.
* @details		Failed to open anything (file, socket, database, etc.).
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_OPEN_ERROR						= 0xC0000009;

/**************************************************************************************************//**
* @brief			Close error.
* @details		Failed to close anything (file, socket, database, etc.).
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_CLOSE_ERROR						= 0xC000000A;

/**************************************************************************************************//**
* @brief			Execute error.
* @details		Failed to execute something (action, SQL command, etc.).
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_EXECUTE_ERROR					= 0xC000000B;

/**************************************************************************************************//**
* @brief			Busy error.
* @details		Something is busy and can not perform action or anything else.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_BUSY_ERROR						= 0xC000000C;

/**************************************************************************************************//**
* @brief			Not allowed error.
* @details		When trying to execute or do some action which is not allowed.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_NOT_ALLOWED_ERROR				= 0xC000000D;

/**************************************************************************************************//**
* @brief			Still running error.
* @details		When something is still running, but it shouldn't.
* @see			MsvErrorMask
* @see			MSV_IS_ERROR
******************************************************************************************************/
MsvErrorCode const MSV_STILL_RUNNING_ERROR			= 0xC000000E;


#endif // !MARSTECH_ERROR_CODES_H

/** @} */	//End of group MPLS.
