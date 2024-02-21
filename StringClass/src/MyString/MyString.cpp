#include "MyString.hpp"

MyString::MyString()
{
	line = new char[SHRT_MAX];
	lineLength = 0;
}

MyString::MyString(const char* line)
{
	strcpy(this->line,line);
	this->lineLength = strlen(line);
}

MyString::MyString(const MyString& right)
{
	line = new char[right.lineLength + 1];
	strcpy(line, right.line);
	lineLength = right.lineLength;
}

MyString::~MyString()
{
	delete[] line;
}

MyString& MyString::operator=(const char* line)
{
	this->clear();
	strcpy(this->line,line);
	this->lineLength = strlen(line);
	return *this;
}

MyString& MyString::operator=(const MyString& right)
{
	this->clear();
	line = new char[right.lineLength + 1];
	strcpy(line, right.line);
	lineLength = right.lineLength;
	return *this;
}

MyString MyString::operator+(const MyString& right)
{
	MyString sum;

	size_t iter = 0;
	for (size_t i = 0; i < this->lineLength; ++i) {
		sum.line[iter] = this->line[i];
		++iter;
	}
	for (size_t i = 0; i < right.lineLength; ++i) {
		sum.line[iter] = right.line[i];
		++iter;
	}

	sum.lineLength = iter;

	return sum;
}

std::ostream& operator<<(std::ostream& out, const MyString& right)
{
	for (size_t i = 0; i < right.lineLength; ++i) {
		out << right.line[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, MyString& right)
{
	right.clear();
	char* line = new char[SHRT_MAX];
	in.getline(line, SHRT_MAX);
	strcpy(right.line, line);
	right.lineLength = strlen(right.line);
	return in;
}

bool MyString::operator==(const MyString& right)
{
	if (strcmp(this->line, right.line)) {
		return true;
	}
	return false;
}

bool MyString::operator!=(const MyString& right)
{
	return !(*this == right);
}

bool MyString::operator>(const MyString& right)
{
	if (strcmp(this->line, right.line) > 0) {
		return true;
	}
	return false;
}

bool MyString::operator<(const MyString& right)
{
	if (strcmp(this->line, right.line) < 0) {
		return true;
	}
	return false;
}

bool MyString::operator<=(const MyString& right)
{
	return !(*this > right);
}

bool MyString::operator>=(const MyString& right)
{
	return !(*this < right);
}

size_t MyString::length()
{
	return this->lineLength;
}

size_t MyString::size()
{
	return this->lineLength;
}

void* MyString::get_allocator()
{
	return (void*)line;
}

void MyString::clear()
{
	line = new char[SHRT_MAX];
	lineLength = 0;
}

bool MyString::empty()
{
	return !lineLength;
}

size_t MyString::find(char symbol)
{
	for (size_t i = 0; i < lineLength; ++i) {
		if (line[i] == symbol) {
			return i;
		}
	}
	return -1;
}

char* MyString::c_str()
{
	char* linecpy = new char[lineLength];
	strcpy(linecpy, line);
	return linecpy;
}

MyString& MyString::reverse()
{
	char* reversedLine = new char[lineLength];
	for (size_t i = 0; i < lineLength; ++i) {
		reversedLine[i] = line[lineLength - i - 1];
	}
	strcpy(line, reversedLine);
	return *this;
}
