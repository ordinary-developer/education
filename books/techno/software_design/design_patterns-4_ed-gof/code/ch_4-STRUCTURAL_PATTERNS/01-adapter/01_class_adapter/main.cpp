// initial data
class Coord;

class Point { 
    public:
        Point(const Coord& coord1, const Coord& coord2) {

        }

};

class Manipulator { };

class Shape {
    public:
        Shape() { }

        virtual void BoundingBox(
            Point& bottomLeft, Point& topRight) const = 0;

        virtual Manipulator* CreateManipulator() const = 0;
};

class Coord { };

class TextView {
    public:
        TextView() { }

        void GetOrigin(Coord& x, Coord& y) const { }

        void GetExtent(Coord& width, Coord& height) const { }

        virtual bool IsEmpty() const { return true; }
};

class TextManipulator : public Manipulator { };

// Adapter pattern
class TextShape : public Shape, private TextView {
    public:
        TextShape() { }

        virtual void BoundingBox(
            Point& bottomLeft, Point& topRight) const override 
        {
            Coord bottom, left, width, height;

            GetOrigin(bottom, left);
            GetExtent(width, height);

            bottomLeft = Point(bottom, left);
        }

        virtual Manipulator* CreateManipulator() const override
        {
            return new TextManipulator();
        }

        virtual bool IsEmpty() const 
        {
            return TextView::IsEmpty();
        }
};

int main() {
    TextShape textShape;
    textShape.IsEmpty();

    return 0;
}
