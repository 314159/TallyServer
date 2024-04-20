#ifndef sbn_cfstring_h
#define sbn_cfstring_h

#include <string>
#include <CoreFoundation/CoreFoundation.h>

namespace sbn {
    class CFString {
        public:
        CFString();
        CFString(std::string s);
        ~CFString();
        std::string string();
        CFStringRef& ref();
        CFStringRef* ptr();
        private:
        CFStringRef m_string;
    };
}
#endif