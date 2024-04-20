#include "include/BMDSwitcherAPI.h"
#include "include/com_ptr.h"
#include "SwitcherInput.h"
#include "SwitcherInputIterator.h"

namespace sbn {
    SwitcherInputIterator::SwitcherInputIterator(com_ptr<IBMDSwitcherInputIterator> iterator)
    :m_iterator{iterator}
    {}

    std::unique_ptr<SwitcherInput> SwitcherInputIterator::Next() {
        auto input = com_ptr<IBMDSwitcherInput>{};
        auto result = m_iterator->Next(input.releaseAndGetAddressOf());
        if (result != S_OK) {
            return nullptr;
        }

        return std::make_unique<SwitcherInput>(input);
    }
}