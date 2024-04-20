#include <memory>
#include "Discovery.h"
#include "CFString.h"
#include "Switcher.h"

namespace sbn {
    Discovery::Discovery()
    : m_discovery{com_ptr<IBMDSwitcherDiscovery>{CreateBMDSwitcherDiscoveryInstance()}}
    {
    }

    std::unique_ptr<Switcher> Discovery::ConnectTo(std::string deviceAddress)
    {
        auto address = CFString{deviceAddress};
        auto failReason = BMDSwitcherConnectToFailure{};
        auto switcher = com_ptr<IBMDSwitcher>{};
        if (S_OK != m_discovery.get()->ConnectTo(address.ref(), switcher.releaseAndGetAddressOf(), &failReason)) {
            return nullptr;
        }
        return std::make_unique<Switcher>(switcher);
    }
}