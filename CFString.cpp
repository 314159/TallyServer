#include "CFString.h"

namespace sbn {
    CFString::CFString()
    :m_string{}
    {
    }

    CFString::CFString(std::string s) {
        m_string = CFStringCreateWithCString(kCFAllocatorDefault, s.c_str(), kCFStringEncodingUTF8);
        if (m_string == nullptr) {
            throw "Unable to create CFString";
        }
    }

    CFString::~CFString() {
        CFRelease(m_string);
    }

    std::string CFString::string() {
        auto str = std::string{};
        auto stringSize = CFStringGetLength(m_string) + 1;
        char buf[stringSize];
        if (CFStringGetCString(m_string, buf, stringSize, kCFStringEncodingUTF8)) {
            return buf;
        } else {
            return "";
        }
    }

    CFStringRef& CFString::ref() {
        return m_string;
    }

    CFStringRef* CFString::ptr() {
        return &m_string;
    }
}