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

MarsTech Dependency Injection is free software: you can redistribute it and/or modify
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


#ifndef MARSTECH_EXCEPTION_H
#define MARSTECH_EXCEPTION_H


#include "MsvError.h"

MSV_DISABLE_ALL_WARNINGS

#include <exception>
#include <chrono>
#include <sstream>

MSV_ENABLE_WARNINGS


/**************************************************************************************************//**
* @brief		MarsTech exception.
* @details	Exception which stores @ref MsvErrorCode and message. It can be rethrown with new message
*				and new errorCode. Original message and errorCode will be stored too.
* @see		MsvErrorCode
* @see		MSV_THROW
* @see		MSV_RETHROW
* @see		MSV_THROW_FAILED
******************************************************************************************************/
class MsvException :
	public std::exception
{
public:
	/**************************************************************************************************//**
	* @brief			Constructor.
	* @details		The last stored errorcode. Can be accessed by @ref GetErrorCode method.
	* @param[in]	fileName		Filename where exception has been thrown.
	* @param[in]	line			Line number where exception has been thrown.
	* @param[in]	errorCode	The errorcode to set to the exception.
	* @param[in]	msg			Message to set to the exception.
	* @see			MSV_THROW
	* @see			MSV_THROW_FAILED
	******************************************************************************************************/
	MsvException(const char* fileName, int line, MsvErrorCode errorCode, const char* msg) :
		std::exception()
	{
		m_errorCode = errorCode;
		
		std::stringstream data;
		data << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << " 0x" << std::setfill('0') << std::setw(8) << errorCode << " " << fileName << ":" << line << " " << msg << std::endl;
		m_what = data.str();
	}

	/**************************************************************************************************//**
	* @brief			Copy constructor.
	* @param[in]	origin		Original @ref MsvException to be copied.
	******************************************************************************************************/
	MsvException(const MsvException& origin) :
		std::exception(origin),
		m_errorCode(origin.m_errorCode),
		m_what(origin.m_what)
	{
		
	}

	/**************************************************************************************************//**
	* @brief			Assign operator.
	* @param[in]	origin		Original @ref MsvException to be assigned.
	******************************************************************************************************/
	MsvException& operator= (const MsvException& origin)
	{
		std::exception::operator=(origin);
		m_errorCode = origin.m_errorCode;
		m_what = origin.m_what;
	}

	/**************************************************************************************************//**
	* @brief		Get errorcode.
	* @details	Returns the last set errorcode.
	* @returns	MsvErrorCode		The last errorcode set to the exception.
	******************************************************************************************************/
	MsvErrorCode GetErrorCode()
	{
		return m_errorCode;
	}

	/**************************************************************************************************//**
	* @brief			Rethrowing info.
	* @details		Stores new line to message and sets new errorcode. It is automatically called by @ref MSV_RETHROW.
	* @param[in]	fileName		Filename where exception has been thrown.
	* @param[in]	line			Line number where exception has been thrown.
	* @param[in]	errorCode	The errorcode to set to the exception.
	* @param[in]	msg			Message to set to the exception.
	* @see			MSV_RETHROW
	******************************************************************************************************/
	void Rethrowing(const char* fileName, int line, MsvErrorCode errorCode, const char* msg)
	{
		m_errorCode = errorCode;
		
		std::stringstream data;
		data << m_what << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << " 0x" << std::setfill('0') << std::setw(8) << errorCode << " " << fileName << ":" << line << " " << msg << std::endl;
		m_what = data.str();
	}

	/**************************************************************************************************//**
	* @brief		Get message.
	* @details	Returns formatted message what happened.
	* @returns	cont char*		Formatted message what happened.
	* @note		One line format: &lt;time&gt; &lt;hex_errorcode&gt; &lt;fileName&gt;:&lt;linenumber&gt; &lt;message&gt;
	* @see		m_what
	******************************************************************************************************/
	virtual const char* what() const noexcept override
	{
		return m_what.c_str();
	}

protected:
	/**************************************************************************************************//**
	* @brief		Stored errorcode.
	* @details	The last stored errorcode. Can be accessed by @ref GetErrorCode method.
	* @see		MsvErrorCode
	* @see		GetErrorCode
	******************************************************************************************************/
	MsvErrorCode m_errorCode;

	/**************************************************************************************************//**
	* @brief		Stored message/messages.
	* @details	Holds all errorcodes and messages in formatted line by line string.
	* @note		One line format: &lt;time&gt; &lt;hex_errorcode&gt; &lt;fileName&gt;:&lt;linenumber&gt; &lt;message&gt;
	******************************************************************************************************/
	std::string m_what;
};


/**************************************************************************************************//**
* @def			MSV_THROW(msvErrorCode, msg)
* @brief			Throw @ref MsvException.
* @details		Throws @ref MsvException with stored errorcode and message.
* @param[in]	msvErrorCode		The errorcode to set to the exception.
* @param[in]	msvMessage			The message to set to the exception.
* @see			MsvErrorCode
* @see			MsvException
******************************************************************************************************/
#define MSV_THROW(msvErrorCode, msvMessage) throw MsvException(__FILE__, __LINE__, msvErrorCode, msvMessage);

/**************************************************************************************************//**
* @def			MSV_RETHROW(msvException, msvErrorCode, msvMessage)
* @brief			Rehrow @ref MsvException.
* @details		Sets new message and errorcode (original message and errorcode is stored too) and rehrows @ref MsvException.
* @param[in]	msvException		The exception to rethrow.
* @param[in]	msvErrorCode		The errorcode to set to the exception.
* @param[in]	msvMessage			The message to set to the exception.
* @see			MsvErrorCode
* @see			MsvException
* @see			MSV_THROW
******************************************************************************************************/
#define MSV_RETHROW(msvException, msvErrorCode, msvMessage) \
msvException.Rethrowing(__FILE__, __LINE__, msvErrorCode, msvMessage); \
throw msvException;
//std::rethrow_exception(std::make_exception_ptr(msvException));

/**************************************************************************************************//**
* @def			MSV_THROW_FAILED(MsvErrorCodeIn)
* @brief			Check and throw failed.
* @details		Checks if MsvErrorCode is error or warning. Throws @ref MsvException if failed
*					errorcode is received.
* @param[in]	msvErrorCode		The errorcode to check.
* @param[in]	msvMessage			The message to set to the exception.
* @see			MsvErrorCode
* @see			MSV_FAILED
* @see			MSV_THROW
* @warning		Throws @ref MsvException if failed errorcode is received.
******************************************************************************************************/
#define MSV_THROW_FAILED(msvErrorCode, msvMessage) \
{ \
	MsvErrorCode msvErrTF = (msvErrorCode); \
	if (MSV_FAILED(msvErrTF)) { MSV_THROW(msvErrTF, msvMessage); } \
}


#endif // !MARSTECH_EXCEPTION_H

/** @} */	//End of group MPLS.
