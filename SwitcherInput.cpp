#include "SwitcherInput.h"
#include "CFString.h"
#include "include/BMDSwitcherAPI.h"

namespace sbn {
    SwitcherInput::SwitcherInput(com_ptr<IBMDSwitcherInput> input)
    : m_input{input}
    , m_listeners{}
    {
    }

     std::string SwitcherInput::GetShortName() {
        auto str = CFString{};
	
        if (FAILED(m_input->GetShortName(str.ptr()))) {
            return "N/A";
        }
	
        return str.string();
    }

    std::string SwitcherInput::GetLongName() {
        auto str = CFString{};
	
        if (FAILED(m_input->GetLongName(str.ptr()))) {
            return "N/A";
        }
	
        return str.string();
    }

    BMDSwitcherInputId SwitcherInput::GetInputId() {
        auto id = BMDSwitcherInputId{};
        if (m_input->GetInputId(&id) == S_OK) {
            return id;
        }  else {
            return 0;
        }
    }

    bool SwitcherInput::IsLive() {
        auto live = bool{};
        (void)m_input->IsProgramTallied(&live);
        return live;
    }

    bool SwitcherInput::IsPreview() {
        auto preview = bool{};
        (void)m_input->IsPreviewTallied(&preview);
        return preview;
    }

    void SwitcherInput::AddCallback(auto f) {
        (void)m_input->AddCallback(f);
    }
}