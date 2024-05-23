#ifndef sbn_switchermixeffectblockiterator_h
#define sbn_switchermixeffectblockiterator_h

#include "include/BMDSwitcherAPI.h"
#include "SwitcherMixEffectBlock.h"

namespace sbn {
    class SwitcherMixEffectBlockIterator {
        public:
        SwitcherMixEffectBlockIterator(com_ptr<IBMDSwitcherMixEffectBlockIterator>iterator);
        std::unique_ptr<SwitcherMixEffectBlock> Next();
        private:
        com_ptr<IBMDSwitcherMixEffectBlockIterator> m_iterator;
    };
}

#endif