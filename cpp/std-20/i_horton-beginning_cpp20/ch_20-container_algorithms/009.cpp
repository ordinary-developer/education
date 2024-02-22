#include <iostream>
#include <vector>

class Box {
public:
    Box() = default;
    Box(double length, double width, double height)
        : m_length{ length }, m_width{ width }, m_height{ height }
    {}
    
    double getLength() const { return m_length; }
    double getWidth() const { return m_width; }
    double getHeight() const { return m_height; }
    
    void setLength(double length) { if (length > 0) m_length = length; }
    void setWidth(double width) { if (width > 0) m_width = width; }
    void setHeight(double height) { if (height > 0) m_height = height; }
    
    double volume() const { return m_length *  m_width * m_height; }
    
private:
    double m_length{ 1.0 };
    double m_width{ 1.0 };
    double m_height{ 1.0 };
};


int main() {
    {
        std::vector<Box> boxes{ Box{ 1.0, 2.0, 3.0 } };
    
        auto iter{ boxes.begin() };
        std::cout << iter->volume() << std::endl;
    
        *iter = Box{ 2.0, 3.0, 4.0 };
        std::cout << iter->volume() << std::endl;
        
        iter->setHeight(7.0);
        std::cout << iter->volume() << std::endl;
    }
    
    {
        const std::vector<Box> boxes{ Box{ 1.0, 2.0, 3.0 } };
        
        const auto iter1{ boxes.cbegin() };
        std::cout << iter1->volume() << std::endl;
        
        const auto iter2{ std::cbegin(boxes) };
        std::cout << iter2->volume() << std::endl;
        
    }
}
