#include "bus.h"

List::List()
{
	first = NULL;
}

List::~List()
{
	Clear();
}

List::List(const List& other)
{
	Clone(other);
}

List& List::operator=(const List& other)
{
	if (this == &other)
	{
		return *this;
	}
	Clear();
	Clone(other);

	return *this;
}

void List::Clear()
{
	while (first)
	{
		Listitem* temp = first;
		first = first->next;
		delete temp->info;
		delete temp;
	}
}

List::Listitem::Listitem(Bus* bus)
{
	info = bus;
	next = NULL;
}

void List::Insert(int32_t number, const std::string& name, int32_t route)
{
	Bus* newBus = new Bus{ number, name, route };
	Listitem* newItem = new Listitem(newBus);
	if (first == NULL)
	{
		newItem->next = first;
		first = newItem;
		return;
	}
	Listitem* curr = first;
	while (curr->next != NULL && curr->next->info->busNumber < number)
	{
		curr = curr->next;
	}
	newItem->next = curr->next;
	curr->next = newItem;
}

void List::Clone(const List& other)
{
	first = NULL;
	Listitem* current = other.first;
	Listitem* tail = NULL;

	while (current != NULL)
	{
		Bus* copiedBus = new Bus{
			current->info->busNumber,
			current->info->driverName,
			current->info->routeNumber
		};

		Listitem* newItem = new Listitem(copiedBus);

		if (first == NULL)
		{
			first = newItem;
			tail = newItem;
		}
		else
		{
			tail->next = newItem;
			tail = newItem;
		}

		current = current->next;
	}
}

void List::ListPrint()const
{
	Listitem* item = first;
	if (item == NULL)
	{
		std::cout << "List is empty.\n";
		return;
	}

	std::cout << std::left
		<< std::setw(12) << "Bus Number"
		<< std::setw(20) << "Driver Name"
		<< std::setw(12) << "Route Number" << '\n';
	std::cout << std::string(44, '-') << '\n';

	while (item != NULL)
	{
		std::cout << *(item->info) << '\n';
		item = item->next;
	}
}

std::ostream& operator<<(std::ostream& fout, const Bus& bus)
{
	fout << std::left 
		<< std::setw(12) << bus.busNumber
		<< std::setw(20) << bus.driverName
		<< std::setw(12) << bus.routeNumber;
	return fout;
}

Bus* List::Remove(int32_t busNumber)
{
	Listitem* prev = NULL;
	Listitem* curr = first;

	while (curr != NULL && curr->info->busNumber != busNumber)
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL)
	{
		return NULL;
	}

	if (prev == NULL)
	{
		first = curr->next;
	}
	else
	{
		prev->next = curr->next;
	}

	Bus* bus = curr->info;
	delete curr;
	return bus;
}

//Bus* List::Find(int32_t busNumber) const
//{
//	Listitem* curr = first;
//	while (curr != NULL)
//	{
//		if (curr->info->busNumber == busNumber)
//		{
//			return curr->info;
//		}
//		curr = curr->next;
//	}
//	return NULL;
//}

void CheckInputFile(std::ifstream& fin)
{
	if (!fin.good())
	{
		throw "file doesn't exist\n";
	}
	if (!fin)
	{
		throw "input file error\n";
	}
	if (fin.peek() == EOF)
	{
		throw "file is empty\n";
	}
}

void LoadParkFromFile(const std::string& filename, List& parkList)
{
	std::ifstream file(filename);
	CheckInputFile(file);

	std::string line;

	while (std::getline(file, line))
	{
		std::istringstream fin(line);
		int32_t number;
		int32_t route;
		std::string namePart;
		std::string name;

		if (!(fin >> number))
		{
			//continue;
		}

		while (fin >> namePart)
		{
			if (isdigit(namePart[0]))
			{
				route = std::stoi(namePart);
				break;
			}
			if (!name.empty())
			{
				name += " ";
			}
			name += namePart;
		}

		parkList.Insert(number, name, route);
	}

	std::cout << "Buses uploaded from file.\n";
}

void ShowMenu()
{
	std::cout << "\n1. Exit bus on the route\n"
		<< "2. Return bus in the park\n"
		<< "3. Show bus in the park\n"
		<< "4. Show bus on the route\n"
		<< "0. Finish\n"
		<< "You chouse: ";
}

//void InputDataOfBus(int32_t& number, std::string& name, int32_t& route)
//{
//	std::cout << "Bus number: ";
//	std::cin >> number;
//	std::cin.ignore();
//	if (std::cin.fail() || number <= 0)
//	{
//		throw std::invalid_argument("Bad number.");
//	}
//	std::cout << "Driver's name: ";
//	std::getline(std::cin, name);
//	std::cout << "Route number: ";
//	std::cin >> route;
//	if (std::cin.fail() || route <= 0)
//	{
//		throw std::invalid_argument("Bad route.");
//	}
//
//}
//void AddBusToPark(List& parkList)
//{
//	int32_t number{};
//	std::string name;
//	int32_t route{};
//	InputDataOfBus(number, name, route);
//	if (parkList.Find(number))
//	{
//		std::cout << "Bus with this number already exist.\n";
//	}
//	else
//	{
//		parkList.Insert(number, name, route);
//	}
//}

void SendBusToRoute(List& parkList, List& routeList)
{
	int32_t number;
	std::cout << "Bus number for exit: ";
	std::cin >> number;

	if (Bus* bus = parkList.Remove(number))
	{
		routeList.Insert(bus->busNumber, bus->driverName, bus->routeNumber);
		delete bus;
		std::cout << "Bus exit to the route.\n";
	}
	else
	{
		std::cout << "Bus not found in the park.\n";
	}
}

void ReturnBusToPark(List& parkList, List& routeList)
{
	int32_t number;
	std::cout << "Bus number for return: ";
	std::cin >> number;

	if (Bus* bus = routeList.Remove(number))
	{
		parkList.Insert(bus->busNumber, bus->driverName, bus->routeNumber);
		delete bus;
		std::cout << "Bus return in the park.\n";
	}
	else
	{
		std::cout << "Bus not found on the route.\n";
	}
}

void PrintBuses(const List& List)
{
	List.ListPrint();
}