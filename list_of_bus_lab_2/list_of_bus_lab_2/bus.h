#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

struct Bus
{
	int32_t busNumber;
	std::string driverName;
	int32_t routeNumber;
};

class List
{
private:
	struct Listitem
	{
		Bus* info;
		Listitem* next;
		Listitem(Bus* bus);
	};
	Listitem* first;
public:
	List();
	~List();
	List(const List& other);
	List& operator=(const List& other);
	void Insert(int32_t, const std::string&, int32_t);
	void Clone(const List& L);
	void ListPrint() const;
	void Clear();
	Bus* Remove(int32_t);
	//Bus* Find(int32_t) const;
};

std::ostream& operator<<(std::ostream& os, const Bus& bus);
void LoadParkFromFile(const std::string& filename, List& parkList);
void CheckInputFile(std::ifstream& fin);
void ShowMenu();
//void InputDataOfBus(int32_t&, std::string&, int32_t&);
//void AddBusToPark(List& parkList);
void SendBusToRoute(List& parkList, List& routeList);
void ReturnBusToPark(List& parkList, List& routeList);
void PrintBuses(const List& List);

#endif
