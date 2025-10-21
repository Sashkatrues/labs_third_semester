#include "header.h"

int main() {
    std::string input;
    std::cout << "input string: ";
    std::cin >> input;

    try {
        if (isBracketRight(input)) {
            std::cout << "right.\n";
        }
        else {
            std::cout << "false.\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "error: " << e.what();
    }

    return 0;
}