# MarsTech Error Handling
 - [Installation](#installation)
	 - [Configuration](#configuration)
 - [MsvErrorCode](#msverrorcode)
	 - [Error Code Severities](#error-code-severities)
	 - [Succeded vs Failed](#succeded-vs-failed)
	 - [Other Macros](#other-macros)
	 - [MarsTech Error Codes](#marstech-error-codes)
 - [MsvException](#msvexception)
 - [Usage Example](#usage-example)
 - [Source Code Documentation](#source-code-documentation)
 - [License](#license)

MarsTech Error Handling (MERROR) is a C++ project to make error handling easier. It defines [errorcode type and a set of macros](#msverrorcode) to handle errors. Of course there is [MsvException class](#msvexception).

## Installation
MERROR is header only project/library - there is no static or dynamic library. You can download repository and include header file msverror.h (or one of msverrorcodes.h and msvexception.h) to your project.

### Configuration
No configuration is needed - just include MERROR header files to your project.

## Usage Example
There is also an [usage example](https://github.com/Mars2004/msys/Example) which uses the most of [MarsTech](https://github.com/Mars2004) projects and libraries.
Its source codes and readme can be found at:
 - [https://github.com/Mars2004/msys/Example](https://github.com/Mars2004/msys/Example)

## MsvErrorCode
It is typedef which defines errorcode type. It is `int32_t` which is always 32 bit signed integer value.
~~~cpp
typedef int32_t MsvErrorCode;
~~~

### Error Code Severities
There are four error codes types and severities (success, info, warning and error). Each severity has its own macro to check.
The highest nibble (four bits) of [MsvErrorCode](#msverrorcode) is reserved for error code severity:

~~~cpp
//success severity mask definition
MsvErrorCode const MsvSuccessMask = 0x00000000;

//info severity mask definition
MsvErrorCode const MsvInfoMask = 0x40000000;

//warning severity mask definition
MsvErrorCode const MsvWarnMask = 0x80000000;

//error severity mask definition
MsvErrorCode const MsvErrorMask = 0xC0000000;
~~~
There is also check for each severity:
~~~cpp
#include <msverrorcodes.h>

MsvErrorCode errorCode = MsvSuccess;

//check success
if (MSV_IS_SUCCESS(errorCode))
{
	//it is success
}

//check info
if (MSV_IS_INFO(checkErrorCode))
{
	//it is info
}

//check warning
if (MSV_IS_WARN(checkErrorCode))
{
	//it is warning
}

//check error
if (MSV_IS_ERROR(checkErrorCode))
{
	//it is error
}
~~~

### Succeded vs Failed
There are also two macros to check result (error code):

 - `MSV_FAILED(checkErrorCode)` (true for warning and error)
 - `MSV_SUCCEEDED(checkErrorCode)` (true for success and info)

It means MERROR interprets success and info severity as SUCCESS and interprets warning and error severity as FAILED.
**Example:**
~~~cpp
#include <msverrorcodes.h>

MsvErrorCode errorCode = MsvSuccess;

//check succeeded
if (MSV_SUCCEEDED(errorCode))
{
	//succeeded
}

//check failed
if (MSV_FAILED(checkErrorCode))
{
	//failed
}
~~~

### Other Macros
There also some other selfexplained macros:

 - `MSV_RETURN_FAILED(checkErrorCode)` (returns checkErrorCode if failed)
 - `MSV_BREAK_FAILED(checkErrorCode)` (breaks if failed)
 - `MSV_CONTINUE_FAILED(checkErrorCode)` (continues if failed)

For more info about these macros, please check [Source Code Documentation](#source-code-documentation).

### MarsTech Error Codes
All MarsTech error codes are defined in msverrorcodes.h header file. New error codes will be added when needed.
There will be defined all error codes used by MarsTech libraries. You can use it or define your own set of error codes.

## MsvException
It is MarsTech implementation of `std::exception` (it inherits from it). It contains information about filename and line number where the exception has been thrown. Of course, it contains MarsTech error code and message what happened.
You can use [MsvException](#msvexception) directly or use of these macros which makes usage of [MsvException](#msvexception) easier:

 - `MSV_THROW(msvErrorCode, msvMessage)` (throws [MsvException](#msvexception))
 - `MSV_RETHROW(msvException, msvErrorCode, msvMessage)` (rethrows msvException and sets new error code and message)
 - `MSV_THROW_FAILED(msvErrorCode, msvMessage)` (checks msvErrorCode and throws [MsvException](#msvexception) if failed)
**Example:**
~~~cpp
#include <msvexception.h>
#include <msverrorcodes.h>

MsvErrorCode FailedFunction() { return MsvTestError; }

try
{
	MSV_THROW_FAILED(FailedFunction(), "FailedFunction failed.");
	MSV_THROW(MsvTestError, "Throw exception with MsvTestError error code.");
}
catch (MsvException& caughtException)
{
	MSV_RETHROW(caughtException, MsvTestError_2, "Exception caught - rethrowing.")
}
catch (...)
{
	//some other exception has been caught
}
~~~

## Usage Example
There is also an [usage example](https://github.com/Mars2004/msys/tree/master/Example) which uses the most of [MarsTech](https://github.com/Mars2004) projects and libraries.
Its source codes and readme can be found at:
 - [https://github.com/Mars2004/msys/tree/master/Example](https://github.com/Mars2004/msys/tree/master/Example)

## Source Code Documentation
You can find generated source code documentation at [https://www.marstech.cz/projects/merror/1.0.1/doc](https://www.marstech.cz/projects/merror/1.0.1/doc).

## License
This project is released under GNU General Public License version 3. If you can not or do not want to accept GNU GPLv3 license and you would like to use this project under another license, please contact me on [info@marstech.cz](mailto:info@marstech.cz) or visit [www.marstech.cz](https://www.marstech.cz/en).
