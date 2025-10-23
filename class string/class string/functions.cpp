#include "string.h"

String::String()
{
	length = 0;
	string = new char[length + 1] {'\0'};
}

String::~String()
{
	delete[] string;
}

String::String(char ch)
{
	length = 1;
	string = new char[length + 1];
	string[0] = ch;
	string[1] = '\0';
}

//String::String(const char* str, size_t len)
//{
//	length = len;
//	string = new char[length + 1];
//	std::strcpy(string, str);
//}

String::String(const char* str)
{
	length = std::strlen(str);
	string = new char[length + 1];
	std::strcpy(string, str);
}

String::String(const String& rhs)
{
	length = rhs.length;
	string = new char[length + 1];
	std::strcpy(string, rhs.string);
}

String& String::operator=(const char* rhs)
{
	if (rhs == NULL)
	{
		delete[] string;
		string = NULL;
		length = 0;
		return *this;
	}
	delete[] string;
	length = strlen(rhs);
	string = new char[length + 1];
	strcpy(string, rhs);
	return *this;
}

String& String::operator=(const String& rhs)
{
	if (this != &rhs)
	{
		delete[] string;
		if (rhs.string)
		{
			length = rhs.length;
			string = new char[length + 1];
			std::strcpy(string, rhs.string);
		}
		else
		{
			string = NULL;
		}
	}
	return *this;
}

String& String::operator=(char ch)
{
	if (length < 1) {
		delete[] string;
		length = 1;
		string = new char[length + 1];
	}
	length = 1;
	string[0] = ch;
	string[1] = '\0';
	return *this;
}

String String::operator+(const String& rhs) const
{
	size_t newLength = length + rhs.length;
	char* newStr = new char[newLength + 1];
	std::strcpy(newStr, string);
	std::strcat(newStr, rhs.string);
	String result(newStr);
	delete[] newStr;
	return result;
}

String operator+(const char* lhs, const String& rhs)
{
	String str = lhs;
	return str + rhs;
}

String String::operator+=(const String& rhs) const
{
	return *this + rhs;
}

String operator+=(const char* lhs, const String& rhs)
{
	return lhs + rhs;
}

bool String::operator==(const String& rhs) const
{
	return std::strcmp(string, rhs.string) == 0;
}


bool String::operator<(const String& rhs) const
{
	return std::strcmp(string, rhs.string) < 0;
}


bool String::operator>(const String& rhs) const
{
	return std::strcmp(string, rhs.string) > 0;
}

bool String::operator<=(const String& rhs) const
{
	return std::strcmp(string, rhs.string) <= 0;
}

bool String::operator>=(const String& rhs) const
{
	return std::strcmp(string, rhs.string) >= 0;
}

bool String::operator!=(const String& rhs) const
{
	return std::strcmp(string, rhs.string) != 0;
}

char& String::operator[](size_t index) const
{
	if (index >= length)
	{
		throw std::out_of_range("can't find your symbol");
	}
	return string[index];
}

std::ostream& operator << (std::ostream& cout, const String& a)
{
	cout << a.string;
	return cout;
}

bool String::empty() const
{
	return length == 0;
}

void String::clear()
{
	delete[] string;
	string = new char[1] {'\0'};
	length = 0;
}

size_t String::size()const
{
	return length;
}

size_t String::find(const String& rhs)const
{
	if (strstr(string, rhs.string) == NULL)
	{
		return 0;
	}
	else
	{
		return length - strlen(strstr(string, rhs.string));
	}
}

size_t String::find_first_of(const String& rhs)const
{
	if (strpbrk(string, rhs.string) == NULL)
	{
		return -1;
	}
	else
	{
		return length - strlen(strpbrk(string, rhs.string));
	}
}

size_t String::find_last_of(const String& rhs)const
{
	for (size_t i{}; i < rhs.length; ++i)
	{
		if (strrchr(string, rhs.string[i]))
		{
			return length - strlen(strrchr(string, rhs.string[i]));
		}
	}
	return -1;
}

String String::substr(size_t pos, size_t count)const
{
	if (pos >= length)
	{
		throw std::out_of_range("position is too big");
	}
	else if (length - pos < count)
	{
		count = length - pos;
	}
	char* copy = new char[count + 1];
	strncpy(copy, (string)+pos, count);
	copy[count] = '\0';
	String result(copy);
	delete[]copy;
	return result;
}

void String::reverse()
{
	size_t len{ length / 2 };
	for (size_t i{}; i < len; ++i)
	{
		std::swap(string[i], string[length - i - 1]);
	}
}

int String::compare(const String& rhs) const
{
	return std::strcmp(string, rhs.string);
}

void String::insert(size_t pos, const String& rhs)
{
	if (pos > length)
	{
		throw std::out_of_range("insert position out of range\n");
	}
	char* result = new char[length + rhs.length + 1];
	std::strncpy(result, string, pos);
	std::strcpy(result + pos, rhs.string);
	std::strcpy(result + pos + rhs.length, string + pos);
	string = result;
	length += rhs.length;
}

void String::replace(size_t pos, size_t count, const String& rhs)
{
	if (pos >= length)
	{
		throw std::out_of_range("Replace pos is too big");
	}
	else if (length - pos < count)
	{
		count = length - pos;
	}
	char* bufer = new char[length - pos + 1];
	strncpy(bufer, string, pos);
	strcpy(bufer + pos, rhs.string);
	strcat(bufer, string + pos + count);
	string = NULL;
	string = bufer;
	length -= count - rhs.length;
}

String& String::erase(size_t pos)
{
	if (pos >= length)
	{
		throw std::out_of_range("Erase position is too big");
	}
	(*this)[pos] = '\0';
	length = pos;
	return *this;
}

void String::push_back(char ch)
{
	(*this)[length++] = ch;
	(*this)[length] = '\0';
}

void String::pop_back()
{
	(*this)[--length] = '\0';
}

void String::resize(size_t n, char ch)
{
	length = n + 1;
	if (n >= length)
	{
		(*this).append(n - length, ch);
	}
	else
	{
		(*this).erase(n);
	}
}

String& String::append(size_t n, char ch)
{
	for (size_t i{}; i < n; ++i)
	{
		(*this).push_back(ch);
	}
	return *this;
}

String& String::append(const String& rhs)
{
	return (*this) = (*this) + rhs;
}

char* String::c_str()
{
	return string;
}

size_t String::count(char ch) const
{
	size_t counter{};
	for (size_t i{}; i < length; ++i)
	{
		if (string[i] == ch)
		{
			++counter;
		}
	}
	return counter;
}

char& String::at(size_t pos)
{
	if (pos >= length) {
		throw std::out_of_range("At index is too big");
	}
	return string[pos];
}
