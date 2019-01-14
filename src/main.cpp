#include <iostream>
#include <vector>
#include <algorithm>

#include "utils.h"
#include "version.h"


int main() {
    std::vector<IP> ips1;
    std::cin >> ips1;
    sort(ips1.rbegin(), ips1.rend());
    std::cout << ips1;

    std::vector<IP> ips2;
    std::copy_if(
        ips1.cbegin(), 
        ips1.cend(), 
        std::back_inserter(ips2), 
        [](auto ip){return ip[0] == 1;}
    );
    std::cout << ips2;
    ips2.clear();
    std::copy_if(
        ips1.cbegin(), 
        ips1.cend(), 
        std::back_inserter(ips2), 
        [](auto ip){return (ip[0] == 46) && (ip[1] == 70);}
    );
    std::cout << ips2;
    ips2.clear();
    std::copy_if(
        ips1.cbegin(), 
        ips1.cend(), 
        std::back_inserter(ips2), 
        [](auto ip){return std::find(ip.cbegin(), ip.cend(), 46) != ip.cend();}
    );
    std::cout << ips2;
    return 0;
}
