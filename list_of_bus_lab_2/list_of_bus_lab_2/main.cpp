#include "bus.h"

int main()
{
    List parkList;
    List routeList;
    List clone;

    LoadParkFromFile("buses.txt", parkList);
    //clone = parkList;
    //std::cout << "\nBus clone:\n";
    //PrintBuses(clone);

    int32_t choice;
    bool menu{1};
    try
    {
        while (menu)
        {
            ShowMenu();
            std::cin >> choice;

            switch (choice)
            {
            case 0:
                menu = 0;
                break;
            case 1:
                SendBusToRoute(parkList, routeList);
                break;
            case 2:
                ReturnBusToPark(parkList, routeList);
                break;
            case 3:
                std::cout << "\nBus in the park:\n";
                PrintBuses(parkList);
                break;
            case 4:
                std::cout << "\nBus on the route:\n";
                PrintBuses(routeList);
                break;
            default:
                throw std::invalid_argument("Bad choice.\n");
            }
        }
    }
    catch (std::invalid_argument& e) { std::cout << e.what(); }
    catch (const char* m) { std::cout << m; }
    return 0;
}