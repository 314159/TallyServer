#ifndef _sbn_switcher_h
#define _sbn_switcher_h

#include <iostream>
#include <memory>
#include <vector>
#include "include/BMDSwitcherAPI.h"
#include "include/com_ptr.h"

namespace sbn {
    class SwitcherInput;
    class SwitcherInputIterator;
    class SwitcherMixEffectBlock;
    class SwitcherMixEffectBlockIterator;

    // ConnectionError is used to throw an error when unable to connect
    class ConnectionError{
        public:
        ConnectionError(std::string deviceAddress, BMDSwitcherConnectToFailure failureReason);
 
        private:
        std::string m_deviceAddress;
        BMDSwitcherConnectToFailure m_failureReason;
    };
 
    // Switcher represents a connection to a switcher.
    class Switcher {
        public:
            Switcher(com_ptr<IBMDSwitcher> switcher);
            std::string GetProductName();
            std::vector<std::unique_ptr<SwitcherInput>> GetInputs();
            std::unique_ptr<SwitcherInputIterator> InputIterator();
            std::vector<std::unique_ptr<SwitcherMixEffectBlock>> GetMixEffectBlocks();
            std::unique_ptr<SwitcherMixEffectBlockIterator> MixEffectBlockIterator();

        private:
            com_ptr<IBMDSwitcher> m_switcher;
    };
 
}

#endif