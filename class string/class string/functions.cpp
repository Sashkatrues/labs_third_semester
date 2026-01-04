#include "string.h"

String::String() : length(0), capaci(1) {
	string = new char[capaci];
	string[0] = '\0';
}

String::~String()
{
	delete[] string;
}

String::String(char ch) : length(1), capaci(2) {
	string = new char[capaci];
	string[0] = ch;
	string[1] = '\0';
}

String::String(const char* str) {
	length = std::strlen(str);
	capaci = length + 1;
	string = new char[capaci];
	std::strcpy(string, str);
}

String::String(const String& rhs) {
	length = rhs.length;
	capaci = rhs.capaci;
	string = new char[capaci];
	std::strcpy(string, rhs.string);
}

String::String(String&& other) noexcept {
	string = other.string;
	length = other.length;
	capaci = other.capaci;
	other.string = NULL;
	other.length = 0;
	other.capaci = 0;
}

String& String::operator=(const char* rhs)
{
	if (rhs == NULL)
	{
		clear();
		capaci = 1;
		return *this;
	}
	delete[] string;
	length = strlen(rhs);
	capaci = length + 1;
	string = new char[capaci];
	strcpy(string, rhs);
	return *this;
}

String& String::operator=(const String& rhs)
{
	if (this != &rhs)
	{
		delete[] string;
		length = rhs.length;
		capaci = rhs.capaci;
		string = new char[capaci];
		std::strcpy(string, rhs.string);
	}
	return *this;
}

String& String::operator=(char ch)
{
	delete[] string;
	length = 1;
	capaci = 2;
	string = new char[capaci];
	string[0] = ch;
	string[1] = '\0';
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		delete[] string;
		string = other.string;
		length = other.length;
		capaci = other.capaci;
		other.string = nullptr;
		other.length = 0;
		other.capaci = 0;
	}
	return *this;
}
String String::operator+(const String& rhs) const
{
	size_t newLength = length + rhs.length;
	size_t newCapaci = newLength + 1;
	char* newStr = new char[newCapaci];
	std::strcpy(newStr, string);
	std::strcat(newStr, rhs.string);
	String result(newStr);
	delete[] newStr;
	return result;
}

String operator+(const char* lhs, const String& rhs)
{
	String str(lhs);
	return str + rhs;
}

String& String::operator+=(const String& rhs)
{
	if (length + rhs.length + 1 > capaci)
	{
		reserve(length + rhs.length + 1);
	}
	std::strcat(string, rhs.string);
	length += rhs.length;
	return *this;
}

String operator+=(const char* lhs, const String& rhs)
{
	String str(lhs);
	str += rhs;
	return str;
}

bool String::operator==(const String& rhs) const
{
	return std::strcmp(string, rhs.string) == 0;
}


bool String::operator<(const String& rhs) const
{
	return std::strcmp(string, rhs.string) < 0;
}

bool String::operator!=(const String& rhs) const
{
	return !(*this == rhs);
}

bool String::operator>(const String& rhs) const
{
	return rhs < *this;
}

bool String::operator<=(const String& rhs) const
{
	return !(rhs < *this);
}

bool String::operator>=(const String& rhs) const
{
	return !(*this < rhs);
}

char& String::operator[](size_t index) const
{
	if (index >= length)
	{
		throw std::out_of_range("can't find your symbol");
	}
	return string[index];
}

std::istream& operator>>(std::istream& fin, String& s)
{
	s.clear();
	char buffer[1024];
	fin >> buffer;
	s = buffer;
	return fin;
}

std::ostream& operator << (std::ostream& fout, const String& a)
{
	if (a.string == NULL)
	{
		throw std::out_of_range("<<: no string");
	}
	fout << a.string;
	return fout;
}

String& String::copy(const String& rhs)
{
	*this = rhs;
	return *this;
}

char& String::front()
{
	return string[0];
}

char& String::back()
{
	if (empty()) {
		throw std::out_of_range("back: empty string");
	}
	return string[length];
}


bool String::empty() const
{
	return length == 0;
}

void String::clear()
{
	length = 0;
	if (string)
	{
		string[0] = '\0';
	}
}

size_t String::size()const
{
	return length;
}

void String::reserve(size_t new_cap)
{
	if (new_cap <= capaci) return;
	char* new_string = new char[new_cap];
	if (string)
	{
		std::strcpy(new_string, string);
		delete[] string;
	}
	else
	{
		new_string[0] = '\0';
	}
	string = new_string;
	capaci = new_cap;
}

size_t String::capacity() const
{
	return capaci;
}

size_t String::find(const String& rhs) const
{
	if (!rhs.string || rhs.length == 0)
	{
		return 0;
	}
	const char* pos = std::strstr(string, rhs.string);
	if (!pos)
	{
		return static_cast<size_t>(-1);
	}
	return static_cast<size_t>(pos - string);
}

size_t String::find_first_of(const String& rhs) const
{
	if (!rhs.string || rhs.length == 0) {
		return static_cast<size_t>(-1);
	}
	const char* pos = std::strpbrk(string, rhs.string);
	if (!pos) {
		return static_cast<size_t>(-1);
	}
	return static_cast<size_t>(pos - string);
}

size_t String::find_last_of(const String& rhs) const
{
	if (!rhs.string || rhs.length == 0) {
		return static_cast<size_t>(-1);
	}
	size_t last = static_cast<size_t>(-1);
	for (size_t i = 0; i < length; ++i) {
		if (std::strchr(rhs.string, string[i])) {
			last = i;
		}
	}
	return last;
}

String String::substr(size_t pos, size_t count)const
{
	if (pos >= length)
	{
		throw std::out_of_range("substr position is too big");
	}
	else if (pos + count > length)
	{
		count = length - pos;
	}
	char* copy = new char[count + 1];
	std::strncpy(copy, (string) + pos, count);
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
	if (pos > length) {
		throw std::out_of_range("insert position out of range");
	}

	size_t newLength = length + rhs.length;
	if (newLength + 1 > capaci) {
		reserve(newLength + 1);
	}

	char* result = new char[newLength + 1];

	std::strncpy(result, string, pos);
	result[pos] = '\0';

	std::strcat(result, rhs.string);

	std::strcat(result, string + pos);

	delete[] string;
	string = result;
	length = newLength;
	capaci = newLength + 1;
}

void String::replace(size_t pos, size_t count, const String& rhs)
{
	if (pos > length) {
		throw std::out_of_range("replace pos is too big");
	}
	if (pos + count > length) {
		count = length - pos;
	}

	size_t newLength = length - count + rhs.length;
	if (newLength + 1 > capaci) {
		reserve(newLength + 1);
	}

	char* buffer = new char[newLength + 1];

	std::strncpy(buffer, string, pos);
	buffer[pos] = '\0';

	std::strcat(buffer, rhs.string);

	std::strcat(buffer, string + pos + count);

	delete[] string;
	string = buffer;
	length = newLength;
	capaci = newLength + 1;
}

String& String::erase(size_t pos)
{
	if (pos >= length) {
		throw std::out_of_range("Erase position is too big");
	}

	string[pos] = '\0';
	length = pos;
	return *this;
}

String& String::erase(size_t index, size_t count)
{
	if (index > length) {
		throw std::out_of_range("Erase index is too big");
	}

	if (count >= length - index) {
		length = index;
		string[length] = '\0';
	}
	else {
		std::strcpy(string + index, string + index + count);
		length -= count;
	}

	return *this;
}

void String::push_back(char ch)
{
	if (length + 1 >= capaci) {
		reserve(capaci * 2);
	}
	string[length++] = ch;
	string[length] = '\0';
}

void String::pop_back()
{
	if (empty()) {
		throw std::out_of_range("pop_back: empty string");
	}
	--length;
	string[length] = '\0';
}

void String::swap(String& other)
{
	std::swap(string, other.string);
	std::swap(length, other.length);
	std::swap(capaci, other.capaci);
}

void String::resize(size_t count, char ch)
{
	if (count > length) {
		if (count + 1 > capaci) {
			reserve(count + 1);
		}
		for (size_t i = length; i < count; ++i) {
			string[i] = ch;
		}
	}
	length = count;
	string[length] = '\0';
}

String& String::append(const char* str)
{
	size_t strLen = std::strlen(str);
	if (strLen == 0) {
		return *this;
	}

	if (length + strLen + 1 > capaci) {
		reserve(length + strLen + 1);
	}

	std::strcpy(string + length, str);
	length += strLen;

	return *this;
}

String& String::append(const String& str) {
	append(str.string);
	return *this;
}

const char* String::c_str() const
{
	return string;
}

size_t String::count(char ch) const
{
	size_t counter = 0;
	for (size_t i = 0; i < length; ++i) {
		if (string[i] == ch) {
			++counter;
		}
	}
	return counter;
}

char& String::at(size_t pos)
{
	if (pos >= length) {
		throw std::out_of_range("at: index is out of range");
	}
	return string[pos];
}

const char& String::at(size_t pos) const
{
	if (pos >= length) {
		throw std::out_of_range("at: index is out of range");
	}
	return string[pos];
}
