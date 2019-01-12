#include <iostream>

#include "utils.h"
#include "version.h"


int main() {
    auto ips = read_from_stream(std::cin);
    write_into_stream(std::cout, ips);    
    return 0;
}
