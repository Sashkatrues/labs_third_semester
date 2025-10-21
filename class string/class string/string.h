#define _CRT_SECURE_NO_WARNINGS
#ifndef STRING_H
#define STRING_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
class String
{
private:
	size_t length;
	char* string;
public:
	String();
	String(const char* str, size_t len);
	//String(const char* str);
	String(const String&);
	~String();
	String& operator=(const String& rhs);
	String& operator=(const char* rhs);

	String operator+(const String&) const;
	bool operator==(const String& rhs) const;
	bool operator>(const String& rhs) const;
	bool operator<(const String& rhs) const;
	bool operator!=(const String& rhs) const;
	char& operator[](size_t pos)const;
	friend std::ostream& operator << (std::ostream& cout, const String& a);

	size_t size()const;
	bool empty() const;
	void clear();
	void pop_back();
	void resize(size_t n, char ch);
	void push_back(char ch);
	String& append(size_t n, char ch);
	String& append(const String&);
	size_t find(const String&)const;
	size_t find_first_of(const String&)const;
	size_t find_last_of(const String&)const;
	String substr(size_t, size_t)const;
	void reverse();
	String& erase(size_t pos);
	int compare(const String& rhs) const;
	void insert(size_t pos, const String& str);
	void replace(size_t pos, size_t count, const String& tmp);
	char* c_str();
	size_t count(char ch) const;
};
#endif