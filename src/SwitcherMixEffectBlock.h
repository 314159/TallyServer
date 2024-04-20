#ifndef sbn_SwitcherMixEffectBlock_h
#define sbn_SwitcherMixEffectBlock_h

#include <string>
#include <memory>
#include <vector>
#include "include/BMDSwitcherAPI.h"
#include "include/com_ptr.h"
#include "Listener.h"

namespace sbn {
    class SwitcherMixEffectBlock {
        public:
            SwitcherMixEffectBlock(com_ptr<IBMDSwitcherMixEffectBlock> me);
            void AddCallback(auto f);
        private:
            com_ptr<IBMDSwitcherMixEffectBlock> m_me;
    };
}

#endif