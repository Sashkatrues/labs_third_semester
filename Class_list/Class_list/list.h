#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
private:
	struct Listitem
	{
		int info;
		Listitem* next;
	};
	Listitem* first;
public:
	List();
	List(const List&);
	~List();
	const List& operator = (const List&);
	const int Top() const;
	void InsertFirst(const int&);
	void Insert(const int, List&);
	bool DeleteFirst();
	void ListPrint() const;
	void ForEach(void(int))const;
	void ForEach(void(int&));
	void Erase();
private:
	void Clone(const List&);
};
	void PrintItem(int value);
	void Increment(int& value);

#endif