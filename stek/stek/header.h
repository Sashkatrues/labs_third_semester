#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

class Stack
{
private:
	int32_t top;
	const int32_t size;
	int32_t* arr;

public:
	Stack(const int32_t & = 100);
	~Stack();
	Stack(const Stack&);
	Stack(Stack&&);
	Stack& operator=(const Stack&);
	Stack& operator=(const Stack&&);
	void push(int32_t);
	void pop();
	int32_t peek();
	bool isEmpty();
	bool isFull();
	std::string sortTrain(const std::string& str);
};
bool isBracketRight(const std::string& str);
#endif
