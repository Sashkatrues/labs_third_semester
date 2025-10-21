#include "list.h"

	List::List()
	{
		first = NULL;
	}

void List::InsertFirst(const int& ainfo)
{
	Listitem* P = new Listitem;
	P->info = ainfo;
	P->next = first;
	first = P;
}

void List::Insert(const int num, List& L)
{
	Listitem* newPtr = new Listitem;
	newPtr->info = num;
	if (L.first == NULL)
	{
		newPtr->next = L.first;
		L.first = newPtr;
		return;
	}
	Listitem* curr = L.first;
	while (curr->next != NULL && curr->next->info < num)
	{
		curr = curr->next;
	}
	newPtr->next = curr->next;
	curr->next = newPtr;
}

bool List::DeleteFirst()
{
	if (first == NULL)
	{
		return false;
	}
	Listitem* P = first;
	first = first->next;
	delete P;
	return true;
}

const int List::Top() const
{
	if (first == NULL)
	{
		throw "list is empty";
	}
	int x = first->info;
	return x;
}

void List::Clone(const List& L)
{
	Listitem* p, * q, * r;
	r = NULL;
	p = L.first;
	while (p != NULL)
	{
		q = new Listitem;
		q->info = p->info;
		q->next = NULL;
		if (r == NULL)
		{
			first = q;
		}
		else
		{
			r->next = q;
		}
		r = q;
		p = p->next;
	}
}

void List::Erase()
{
	Listitem* p;
	Listitem* q;
	p = first;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	first = NULL;
}

List::List(const List& L)
{
	Clone(L);
}

const List& List::operator = (const List& L)
{
	if (&L == this)
	{
		return *this;
	}
	Erase();
	Clone(L);
	return *this;
}

void List::ForEach(void (*func)(int))const
{
	Listitem* p = first;
	while(p!=NULL)
	{
		func(p->info);
		p = p->next;
	}
}

void PrintItem(int value)
{
	std::cout << value << '\n';
}

void List::ForEach(void (*func)(int&))
{
	Listitem* p = first;
	if (p == NULL)
	{
		std::cout << "list is empty" << '\n';
	}
	if (p != NULL)
	{
		func(p->info);
		p = p->next;
	}

}

void Increment(int& value)
{
	++value;
}

List::~List()
{
	Erase();
}

void List::ListPrint()const
{
	Listitem* p = first;
	if (p == NULL)
	{
		std::cout << "list is empty" << '\n';
	}
	if (p != NULL)
	{
		std::cout << "contents of the list" << '\n';
		while (p != NULL)
		{
			std::cout << p->info << '\n';
			p = p->next;
		}
	}
}

void Print(int x)
{
	std::cout << x << '\n';
}

//void List::ForEach(void Fun(int))const
//{
//	Listitem* p = first;
//	if (p == NULL)
//	{
//		std::cout << "list is empty" << '\n';
//	}
//	if (p != NULL)
//	{
//		std::cout << "contents of the list" << '\n';
//		while (p != NULL)
//		{
//			Fun(p->info);
//			p = p->next;
//		}
//	}
//}