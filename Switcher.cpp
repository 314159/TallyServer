#include "Switcher.h"
#include "SwitcherInput.h"
#include "SwitcherInputIterator.h"
#include "SwitcherMixEffectBlock.h"
#include "SwitcherMixEffectBlockIterator.h"
#include "CFString.h"

namespace sbn {
    ConnectionError::ConnectionError(std::string deviceAddress, BMDSwitcherConnectToFailure failureReason)
    : m_deviceAddress(deviceAddress)
    , m_failureReason(failureReason)
    {
    }

    Switcher::Switcher(com_ptr<IBMDSwitcher> switcher)
    : m_switcher{switcher}
    {
    }

    std::string Switcher::GetProductName() {
        auto name = CFString{};
	
        if (FAILED(m_switcher->GetProductName(name.ptr()))) {
            return "N/A";
        }
	
        return name.string();
    }

    std::vector<std::unique_ptr<SwitcherInput>> Switcher::GetInputs() {
        auto iterator = InputIterator();
        auto inputs = std::vector<std::unique_ptr<SwitcherInput>>{};

        while (auto input = iterator->Next()) {
            inputs.emplace_back(std::move(input));
        }

        return inputs;
    }

    std::unique_ptr<SwitcherInputIterator> Switcher::InputIterator() {
        auto iterator = com_ptr<IBMDSwitcherInputIterator>{};
        if (FAILED(m_switcher->CreateIterator(IID_IBMDSwitcherInputIterator, reinterpret_cast<LPVOID *>(iterator.releaseAndGetAddressOf())))) {
            return nullptr;
        }
        auto i = std::make_unique<SwitcherInputIterator>(iterator);
        return std::move(i);
    }

    std::vector<std::unique_ptr<SwitcherMixEffectBlock>> Switcher::GetMixEffectBlocks() {
        auto iterator = MixEffectBlockIterator();
        auto inputs = std::vector<std::unique_ptr<SwitcherMixEffectBlock>>{};

        while (auto input = iterator->Next()) {
            inputs.emplace_back(std::move(input));
        }

        return inputs;
    }

    std::unique_ptr<SwitcherMixEffectBlockIterator> Switcher::MixEffectBlockIterator() {
        auto iterator = com_ptr<IBMDSwitcherMixEffectBlockIterator>{};
        if (FAILED(m_switcher->CreateIterator(IID_IBMDSwitcherMixEffectBlockIterator, reinterpret_cast<LPVOID *>(iterator.releaseAndGetAddressOf())))) {
            return nullptr;
        }
        auto i = std::make_unique<SwitcherMixEffectBlockIterator>(iterator);
        return std::move(i);
    }
}
