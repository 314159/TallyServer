#pragma once

#include "include/BMDSwitcherAPI.h"
#include "include/com_ptr.h"
#include "CFString.h"
#include <memory>
#include <string>

namespace sbn {
    class Switcher;

    class Discovery {
        public:
            Discovery();
            std::unique_ptr<Switcher> ConnectTo(std::string ipaddress);
        private:
            com_ptr<IBMDSwitcherDiscovery> m_discovery;
    };
}