template <typename char_t = char>
class basic_string
{
};

class my_string : public basic_string<>
{
};

typedef basic_string<wchar_t> your_string;
int main() {
    return 0;
}
