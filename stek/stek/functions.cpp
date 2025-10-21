#include "header.h"

Stack::Stack(const int32_t& size) : size(size), top(0)
{
	if (size < 1)
	{
		throw std::invalid_argument("bad size\n");
	}
	arr = new int32_t[size];
}

Stack::~Stack()
{
	if(arr != NULL)
	{
		delete[] arr;
		arr = NULL;
	}
}

Stack::Stack(const Stack& other) : size(other.size), top(other.top)
{
	arr = new int32_t[size];
	for (int32_t i{}; i < top; ++i)
	{
		arr[i] = other.arr[i];
	}
}

Stack::Stack(Stack&& other) : size(other.size), top(other.top)
{
	const_cast<int&>(other.size) = 0;
	other.top = 0;
	arr = other.arr;
	other.arr = NULL;
	/*arr = new int32_t[size];
	for (int32_t i{}; i < top; ++i)
	{
		arr[i] = other.arr[i];
	}*/
}

void Stack::push(int32_t num)
{
	if (isFull())
	{
		throw std::out_of_range("stack is full\n");
	}
	arr[top++] = num;
}

void Stack::pop()
{
	if (isEmpty())
	{
		throw std::exception("stack is empty\n");
	}
	--top;
}

int32_t Stack::peek()
{
	if (isEmpty())
	{
		throw std::exception("stack is empty\n");
	}
	return arr[top - 1];
}

bool Stack::isEmpty()
{
	return top == 0;
}

bool Stack::isFull()
{
	return top == size;
}

bool isBracketRight(const std::string& str)
{
	Stack stack(str.size());

	for (char ch : str) {
		switch (ch) {
		case '(':
		case '[':
		case '{':
			stack.push(ch);
			break;

		case ')':
			if (stack.isEmpty() || stack.peek() != '(') return false;
			stack.pop();
			break;

		case ']':
			if (stack.isEmpty() || stack.peek() != '[') return false;
			stack.pop();
			break;

		case '}':
			if (stack.isEmpty() || stack.peek() != '{') return false;
			stack.pop();
			break;

		default:
			break;
		}
	}

	return stack.isEmpty();
}

void sortTrain(const std::string& str)
{
	Stack stack(str.size());

	for (char ch : str) {
		switch (ch) {
		case '(':
		case '[':
		case '{':
			stack.push(ch);
			break;

		case ')':
			if (stack.isEmpty() || stack.peek() != '(');
			stack.pop();
			break;

		case ']':
			if (stack.isEmpty() || stack.peek() != '[');
			stack.pop();
			break;

		case '}':
			if (stack.isEmpty() || stack.peek() != '{');
			stack.pop();
			break;

		default:
			break;
		}
	}

	return stack.isEmpty();
}