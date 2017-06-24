#include <iostream>
#include <type_traits>

template <class T> 
void encode(
  std::ostream& stream, 
  T const& int_value,
  typename std::enable_if<std::is_integral<T>::value, T>::type* = nullptr)
{
    stream << "int: " << int_value << '\n';
}

template <class T>
void encode(
  std::ostream& stream, 
  T const& enum_value,
  typename std::enable_if<std::is_enum<T>::value>::type* = nullptr)
{
    stream 
      << "enum: " 
      << static_cast<typename std::underlying_type<T>::type>(enum_value)
      << std::endl;
}

template <class T>
void encode(
  std::ostream& stream, 
  T const& float_value,
  typename std::enable_if<std::is_floating_point<T>::value>::type* 
    = nullptr)
{
    stream << "float: " << float_value << '\n';
}

void encode(std::ostream& stream, std::string const& string_value) {
    stream << "str: " << string_value << '\n';
}

            
int main() {
    encode(std::cout, 1);
    enum class color { red, green, blue };
    encode(std::cout, color::blue);
    encode(std::cout, 3.0);
    encode(std::cout, std::string("string"));

    return 0;
}
