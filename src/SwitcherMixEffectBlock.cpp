#include "SwitcherMixEffectBlock.h"
#include "CFString.h"
#include "include/BMDSwitcherAPI.h"

namespace sbn {
    SwitcherMixEffectBlock::SwitcherMixEffectBlock(com_ptr<IBMDSwitcherMixEffectBlock> me)
    : m_me{me}
    {
    }

    void SwitcherMixEffectBlock::AddCallback(auto f) {
        (void)m_me->AddCallback(f);
    }
}