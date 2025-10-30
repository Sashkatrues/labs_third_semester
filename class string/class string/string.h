#define _CRT_SECURE_NO_WARNINGS
#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String
{
private:
	size_t length;
	char* string;
public:
	String();
	~String();
	String(char ch);
	String(const char* str);
	String(const String&);
	String(String&& other)noexcept;
	String& operator=(const String& rhs);
	String& operator=(const char* rhs);
	String& operator=(char ch);
	String& operator=(String&& other) noexcept;
	String operator+(const String&) const;
	String operator+=(const String&) const;
	friend String operator+(const char*, const String&);
	friend String operator+=(const char* lhs, const String& rhs);
	bool operator==(const String& rhs) const;
	bool operator>(const String& rhs) const;
	bool operator<(const String& rhs) const;
	bool operator<=(const String& rhs) const;
	bool operator>=(const String& rhs) const;
	bool operator!=(const String& rhs) const;
	char& operator[](size_t pos)const;
	friend std::ostream& operator << (std::ostream& cout, const String& a);

	String& copy(const String& rhs);
	char& front();
	char& back();
	size_t size() const;
	//size_t max_size() const;
	void reserve(size_t new_len);
	size_t capacity() const;
	bool empty() const;
	void clear();
	void pop_back();
	void swap(String& other);
	void resize(size_t n, char ch);
	void push_back(char ch);
	String& append(const char* str);
	String& append(const String&);
	size_t find(const String&)const;
	size_t find_first_of(const String&)const;
	size_t find_last_of(const String&)const;
	String substr(size_t, size_t)const;
	void reverse();
	String& erase(size_t pos);
	String& erase(size_t index, size_t count);
	int compare(const String& rhs) const;
	void insert(size_t pos, const String& str);
	void replace(size_t pos, size_t count, const String& tmp);
	const char* c_str();
	size_t count(char ch) const;
	char& at(size_t pos);
};
#endif
