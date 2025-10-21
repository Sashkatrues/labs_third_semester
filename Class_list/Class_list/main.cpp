#include "list.h"

int main()
{
	try
	{
		List L;
		//int x = L.Top();
		//std::cout << x << '\n';
		//L.ListPrint();
		L.Insert(10, L);
		L.Insert(20, L);
		L.Insert(30, L);
		L.Insert(12, L);
		L.ListPrint();
		//List M = L;
		//std::cout << "list M" << '\n';
		//M.ListPrint();
		//int a = L.Top();
		//std::cout << "Element at the top of list = ";
		//std::cout << a << '\n';
		//if (L.DeleteFirst())
		//{
		//	std::cout << "after delete" << '\n';
		//	L.ListPrint();
		//}
		//else
		//{
		//	std::cout << "list is empty" << '\n';
		//}
		//L.InsertFirst(40);
		//L.ForEach(PrintItem);
		//L.ForEach(Increment);

	}
	catch (const char* msg) { std::cerr << msg; }
}