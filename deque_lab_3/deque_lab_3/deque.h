#ifndef DEQUE_H
#define DEQUE_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

template <class TInfo>
class TDeque
{
private:
	struct TDequeItem
	{
		TInfo Info;
		TDequeItem* next;
		TDequeItem* prev;
	};
	TDequeItem* front;
	TDequeItem* rear;
	int32_t size;

	void Erase()
	{
		while (front)
		{
			TDequeItem* temp = front;
			front = front->next;
			delete temp;
		}
		rear = NULL;
		size = 0;
	}

	void Clone(const TDeque& other)
	{
		Erase();
		TDequeItem* curr = other.front;
		while (curr)
		{
			InsRear(curr->Info);
			curr = curr->next;
		}
	}

	void DeleteItem(TDequeItem* item)
	{
		if (!item) return;
		if (item->prev) item->prev->next = item->next;
		else front = item->next;
		if (item->next) item->next->prev = item->prev;
		else rear = item->prev;
		delete item;
		size--;
	}

	void* PtrByIndex(unsigned index)const
	{
		if (index >= size) return NULL;
		TDequeItem* curr = front;
		for (unsigned i = 0; i < index; ++i)
			curr = curr->next;
		return curr;
	}

public:
	TDeque() : front(NULL), rear(NULL), size(0) {}

	TDeque(const TDeque& other) : front(NULL), rear(NULL), size(0)
	{
		Clone(other);
	}

	virtual ~TDeque()
	{
		Erase();
	}

	void InsFront(TInfo value)
	{
		TDequeItem* item = new TDequeItem{ value, front, NULL };
		if (front) front->prev = item;
		else rear = item;
		front = item;
		size++;
	}

	void InsRear(TInfo value)
	{
		TDequeItem* item = new TDequeItem{ value, NULL, rear };
		if (rear) rear->next = item;
		else front = item;
		rear = item;
		size++;
	}

	bool DelFront(TInfo& value)
	{
		if (!front) return false;
		value = front->Info;
		DeleteItem(front);
		return true;
	}

	bool DelRear(TInfo& value)
	{
		if (!rear) return false;
		value = rear->Info;
		DeleteItem(rear);
		return true;
	}

	const TDeque& operator = (const TDeque& other)
	{
		if (this != &other) Clone(other);
		return *this;
	}

	const TInfo& GetByIndex(unsigned index) const
	{
		TDequeItem* item = static_cast<TDequeItem*>(PtrByIndex(index));
		if (!item) throw std::out_of_range("Index out of range");
		return item->Info;
	}

	void SetByIndex(TInfo value, unsigned index)
	{
		TDequeItem* item = static_cast<TDequeItem*>(PtrByIndex(index));
		if (!item) throw std::out_of_range("Index out of range");
		item->Info = value;
	}
	void Browse(void (*func)(TInfo&))
	{
		TDequeItem* curr = front;
		while (curr)
		{
			func(curr->Info);
			curr = curr->next;
		}
	}
	void Browse(void (*func)(TInfo)) const
	{
		TDequeItem* curr = front;
		while (curr)
		{
			func(curr->Info);
			curr = curr->next;
		}
	}
};

void PrintInt(int);
void PrintStr(char*);
void ToUpper(char*&);
#endif