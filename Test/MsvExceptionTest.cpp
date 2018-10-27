#include "pch.h"

#include "../msvexception.h"

#include "MsvErrorTestConstants.h"
#include <regex>


TEST(MsvExceptionTest, ItShouldCreateValidException)
{
	MsvException exception("fileName", 10, 20, "message");
	std::string(exception.what());
	EXPECT_TRUE(std::regex_match(exception.what(), std::regex("[0-9]{10} 0x00000020 fileName:10 message\n")));
	EXPECT_EQ(exception.GetErrorCode(), 20);
}

TEST(MsvExceptionTest, ItShouldCopyException)
{
	MsvException exception1("fileName", 10, 20, "message");
	MsvException exception2(exception1);

	EXPECT_EQ(std::string(exception1.what()), exception2.what());
	EXPECT_EQ(exception1.GetErrorCode(), exception2.GetErrorCode());
}

TEST(MsvExceptionTest, ItShouldAssignException)
{
	MsvException exception1("fileName", 10, 20, "message");
	MsvException exception2 = exception1;

	EXPECT_EQ(std::string(exception1.what()), exception2.what());
	EXPECT_EQ(exception1.GetErrorCode(), exception2.GetErrorCode());
}

TEST(MsvExceptionTest, ItShouldAddRetrowingDataToException)
{
	MsvException exception("fileName", 10, 20, "message");
	exception.Rethrowing("fileName2", 30, 40, "message 2");
	
	EXPECT_TRUE(std::regex_match(exception.what(), std::regex("[0-9]{10} 0x00000020 fileName:10 message\n[0-9]{10} 0x00000040 fileName2:30 message 2\n")));
	EXPECT_EQ(exception.GetErrorCode(), 40);
}

TEST(MsvExceptionTest, ItShouldThrowValidException)
{
	EXPECT_THROW(MSV_THROW(10, "message"), MsvException);
}

TEST(MsvExceptionTest, ItShouldRethrowValidException)
{
	MsvException exception("fileName", 10, 20, "message");
	
	EXPECT_THROW(MSV_RETHROW(exception, 40, "message 2"), MsvException);
}

TEST(MsvExceptionTest, ItShouldNotThrowExceptionForSuccess)
{
	MSV_THROW_FAILED(MSV_SUCCESS_MIN, "message");
	MSV_THROW_FAILED(MSV_SUCCESS_MIDDLE, "message");
	MSV_THROW_FAILED(MSV_SUCCESS_MAX, "message");
}

TEST(MsvExceptionTest, ItShouldNotThrowExceptionForInfos)
{
	MSV_THROW_FAILED(MSV_INFO_MIN, "message");
	MSV_THROW_FAILED(MSV_INFO_MIDDLE, "message");
	MSV_THROW_FAILED(MSV_INFO_MAX, "message");
}

TEST(MsvExceptionTest, ItShouldThrowValidExceptionForWarnings)
{
	EXPECT_THROW(MSV_THROW_FAILED(MSV_WARN_MIN, "message"), MsvException);
	EXPECT_THROW(MSV_THROW_FAILED(MSV_WARN_MIDDLE, "message"), MsvException);
	EXPECT_THROW(MSV_THROW_FAILED(MSV_WARN_MAX, "message"), MsvException);
}

TEST(MsvExceptionTest, ItShouldThrowValidExceptionForErrors)
{
	EXPECT_THROW(MSV_THROW_FAILED(MSV_ERROR_MIN, "message"), MsvException);
	EXPECT_THROW(MSV_THROW_FAILED(MSV_ERROR_MIDDLE, "message"), MsvException);
	EXPECT_THROW(MSV_THROW_FAILED(MSV_ERROR_MAX, "message"), MsvException);
}
