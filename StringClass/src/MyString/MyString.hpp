#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
#include <cstring>

class MyString
{
private:
	char* line;
	size_t lineLength;
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	~MyString();

	MyString& operator=(const char*);
	MyString& operator=(const MyString&);
	MyString operator+(const MyString&);
	friend std::ostream& operator<<(std::ostream&, const MyString&);
	friend std::istream& operator>>(std::istream&, MyString&);

	bool operator==(const MyString&);
	bool operator!=(const MyString&);
	bool operator>(const MyString&);
	bool operator<(const MyString& right);
	bool operator<=(const MyString&);
	bool operator>=(const MyString&);

	size_t length();
	size_t size();
	void* get_allocator();
	void clear();
	bool empty();
	size_t find(char);
	char* c_str();
	MyString& reverse();
};
#endif
