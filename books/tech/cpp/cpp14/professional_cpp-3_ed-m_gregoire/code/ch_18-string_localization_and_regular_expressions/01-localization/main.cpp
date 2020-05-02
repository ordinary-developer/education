#include <iostream>
namespace example1 {
void run() {
    wchar_t myWideCharacter{ L'm' };
    std::wcout << myWideCharacter << std::endl;
    std::wcout << L"I am wide-character aware." << std::endl;
}
}

#include <iostream>
namespace example2 {
void run() {
    const char* s1{ u8R"(Raw UTF-8 encoded string literal)" };
    const wchar_t* s2{ LR"(Raw wide string literal)" };
    const char16_t* s3{ uR"(Raw char16_t string literal)" };
    const char32_t* s4{ UR"(Raw char32_t string literal)" };

    const wchar_t* formula { L"\u03C0 r\u00B2" };
    std::wcout << formula << std::endl;
}
}

#include <iostream>
#include <locale>
namespace example3 {
void run() {
    std::wcout.imbue(std::locale{""});
    std::wcout << 32767 << std::endl;

    std::wcout.imbue(std::locale{"C"});
    std::wcout << 32767 << std::endl;

    try {
        std::wcout.imbue(std::locale{"en_US"});
        std::wcout << 32767 << std::endl;
    }
    catch (...) { std::wcout << "cannot create a locale" << std::endl; }
}
}

#include <iostream>
#include <locale>
#include <string>
namespace example4 {
void run() {
    std::locale loc{""};
    if (loc.name().find("en_US") == std::string::npos && 
        loc.name().find("United States") == std::string::npos)
    {
        std::wcout << L"Welcome non-U.S. English speaker!" << std::endl;
    }
    else 
        std::wcout << L"Welcome U.S. English speaker!" << std::endl;
}
}

#include <iostream>
#include <locale>
#include <string>
namespace example5 {
void run() {
    std::locale userLocale{""};
    std::wstring money = 
        std::use_facet<std::moneypunct<wchar_t>>(userLocale).curr_symbol();
    std::wcout << L"the currency symbol is " << money << std::endl;
}
}

int main() {
    example1::run();
    example2::run();
    example3::run();
    example4::run();
    example5::run();

    return 0;
}
