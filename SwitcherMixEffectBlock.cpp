#include "CFString.h"
#include "SwitcherMixEffectBlock.h"
#include "include/BMDSwitcherAPI.h"
#include <sstream>

namespace sbn {
    SwitcherMixEffectBlock::SwitcherMixEffectBlock(com_ptr<IBMDSwitcherMixEffectBlock> me)
    : m_me{me}
    {
    }

    void SwitcherMixEffectBlock::AddCallback(auto f) {
        (void)m_me->AddCallback(f);
    }

    std::string SwitcherMixEffectBlock::ProgramInput()
    {
        auto i = BMDSwitcherInputId{};
        m_me->GetProgramInput(&i);
        return std::to_string(i);
    }

    std::string SwitcherMixEffectBlock::PreviewInput()
    {
        auto i = BMDSwitcherInputId{};
        m_me->GetPreviewInput(&i);
        return std::to_string(i);
    }
}