#include "include/BMDSwitcherAPI.h"
#include "include/com_ptr.h"
#include "SwitcherMixEffectBlock.h"
#include "SwitcherMixEffectBlockIterator.h"

namespace sbn {
    SwitcherMixEffectBlockIterator::SwitcherMixEffectBlockIterator(com_ptr<IBMDSwitcherMixEffectBlockIterator> iterator)
    :m_iterator{iterator}
    {}

    std::unique_ptr<SwitcherMixEffectBlock> SwitcherMixEffectBlockIterator::Next() {
        auto me = com_ptr<IBMDSwitcherMixEffectBlock>{};
        auto result = m_iterator->Next(me.releaseAndGetAddressOf());
        if (result != S_OK) {
            return nullptr;
        }

        return std::make_unique<SwitcherMixEffectBlock>(me);
    }
}