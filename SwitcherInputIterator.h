#ifndef sbn_switcherinputiterator_h
#define sbn_switcherinputiterator_h

#include "include/BMDSwitcherAPI.h"
#include "SwitcherInput.h"

namespace sbn {
    class SwitcherInputIterator {
        public:
        SwitcherInputIterator(com_ptr<IBMDSwitcherInputIterator>iterator);
        std::unique_ptr<SwitcherInput> Next();
        private:
        com_ptr<IBMDSwitcherInputIterator> m_iterator;
    };
}

#endif