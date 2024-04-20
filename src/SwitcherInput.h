#ifndef sbn_switcherinput_h
#define sbn_switcherinput_h

#include <string>
#include <memory>
#include <vector>
#include "include/BMDSwitcherAPI.h"
#include "include/com_ptr.h"
#include "Listener.h"

namespace sbn {
    class SwitcherInput {
        public:
            SwitcherInput(com_ptr<IBMDSwitcherInput> input);
            std::string GetShortName();
            std::string GetLongName();
            BMDSwitcherInputId GetInputId();
            bool IsLive();
            bool IsPreview();
            void AddCallback(auto f);
        private:
            com_ptr<IBMDSwitcherInput> m_input;
            std::vector<std::weak_ptr<Listener>> m_listeners;
    };
}

#endif