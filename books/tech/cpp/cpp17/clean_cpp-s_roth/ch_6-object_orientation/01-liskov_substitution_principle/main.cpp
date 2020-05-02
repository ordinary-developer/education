#include <memory>
#include <vector>
#include <iostream>
namespace example01 {

class Point final {
    public:
        Point() : x_{5}, y_{5} {}
        Point(unsigned int const x, unsigned int const y)
            : x_{x}, y_{y} {}

        void setCoordinates(unsigned int const x, unsigned int const y) {
            x_ = x;
            y_ = y;
        }

    private:
        unsigned int x_;
        unsigned int y_;
};

class Shape {
    public:
        Shape() : isVisible_{ false } {}

        virtual ~Shape() = default;

        virtual void moveTo(Point const& centerPoint) {
            hide();
            centerPoint_ = centerPoint;
            show();
        }

        virtual void show() = 0;
        virtual void hide() = 0;

    private:
        Point centerPoint_;
        bool isVisible_;
};

class Rectangle : public Shape {
    public:
        Rectangle() : width_{2}, height_{1} {} 

        Rectangle(unsigned int const width, unsigned int const height) 
            : width_{ width }, height_{ height } {}

        virtual ~Rectangle() override = default;

        virtual void show() override {
            std::cout << "[rectangle] -> show" << std::endl;
        }

        virtual void hide() override {
            std::cout << "[rectangle] -> hide" << std::endl;
        }

        void setWidth(unsigned int const width) {
            width_ = width;
        }

        void setHeight(unsigned int const height) {
            height_ = height;
        }

        void setEdges(unsigned int const width, unsigned int const height) 
        {
            width_ = width;
            height_ = height;
        }

        unsigned long long getArea() const {
            return static_cast<unsigned long long>(width_) * height_;
        }
        
    private:
        unsigned int width_;
        unsigned int height_;
};

class Square : public Shape {
    public:
        Square() {
            impl_.setEdges(5, 5);
        }
        explicit Square(unsigned const edgeLength) {
            impl_.setEdges(edgeLength, edgeLength);
        }

        virtual ~Square() override = default;

        void setEdge(unsigned int length) {
            impl_.setEdges(length, length);
        }

        virtual void moveTo(Point const& centerPoint) override {
            impl_.moveTo(centerPoint);
        }

        virtual void show() override {
            impl_.show();
        }

        virtual void hide() override {
            impl_.hide();
        }

        unsigned long long getArea() const {
            return impl_.getArea();
        }

    private:
        Rectangle impl_;
};

using ShapePtr = std::shared_ptr<Shape>;
using ShapeCollection = std::vector<ShapePtr>;

void showAllShapes(ShapeCollection const& shapes) {
    for (auto& shape : shapes) 
        shape->show();
}

void run() {
    ShapeCollection shapes{};
    shapes.push_back(std::make_shared<Rectangle>());
    shapes.push_back(std::make_shared<Square>());

    showAllShapes(shapes);
}
}

int main() {
    example01::run();

    return 0;
}
