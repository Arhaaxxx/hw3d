#include "MException.h"
#include <sstream>

MException::MException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* MException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* MException::GetType() const noexcept
{
	return "M Exception";
}

int MException::GetLine() const noexcept
{
	return line;
}

const std::string& MException::GetFile() const noexcept
{
	return file;
}

std::string MException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}