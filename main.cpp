#include "include/BMDSwitcherAPI.h"
#include "include/com_ptr.h"
#include "Discovery.h"
#include "Switcher.h"
#include "SwitcherInput.h"
#include <iostream>
#include <memory>
#include <iomanip>

int main()
{
    std::cout << "Hello" << std::endl;

    auto s = std::make_unique<sbn::Discovery>()->ConnectTo("127.0.0.1");

    std::cout << "Product: " << s->GetProductName() << "\n";
    std::cout << "Inputs:\n";
    std::cout << std::setw(8) << std::right << "Input#";
    std::cout << " LP ";
    std::cout << std::left << std::setw(4) << "Name" << " " << "Long Name\n";
    for (auto &i : s->GetInputs()) {
        std::cout << std::setw(8) << std::right << i->GetInputId();
        std::cout << " " << ((i->IsLive())    ? "L" : " ") << ((i->IsPreview()) ? "P" : " ");
        std::cout << " " << std::left << std::setw(4) << i->GetShortName() << " " << i->GetLongName();
        std::cout << "\n";
    }
}