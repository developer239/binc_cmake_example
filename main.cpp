#include "externals/binc/utility.h"
#include <iostream>

int main() {
    std::cout << "Initializing binc..." << std::endl;

    path_to_address("Hello world");

    std::cout << "binc initialized successfully." << std::endl;
    return 0;
}
