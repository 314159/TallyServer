#include "include/BMDSwitcherAPI.h"
#include <iostream>

int main()
{
    std::cout << "Hello" << std::endl;

    auto switcherDiscovery = CreateBMDSwitcherDiscoveryInstance();
    if (!switcherDiscovery) {
        std::cerr << "CreateBMDSwitcherDiscoveryInstance() returned nullptr\n";
        return 1;
    }

    std::cout << "CreateBMDSwitcherDiscoveryInstance() returned a valid value" << std::endl;
}