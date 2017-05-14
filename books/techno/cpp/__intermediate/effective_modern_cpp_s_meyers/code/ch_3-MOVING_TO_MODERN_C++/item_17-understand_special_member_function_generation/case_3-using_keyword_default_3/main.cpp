#include <string>
#include <map>

class StringTable {
    public:
        StringTable() {
            makeLogEntry(L"Creating StringTable object"); 
        }

        ~StringTable() {
            makeLogEntry(L"Destroying StringTable object");
        }

        StringTable(const StringTable&) = default;
        StringTable& operator=(const StringTable&) = default;

        StringTable(StringTable&&) = default;
        StringTable& operator=(StringTable&&) = default;

    private:
        void makeLogEntry(const std::wstring& text) { }

        std::map<int, std::string> values;
};

int main() {
    return 0;
}
