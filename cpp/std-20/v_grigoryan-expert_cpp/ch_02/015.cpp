#include <cstdlib>


struct Point {
    float x;
    float y;
};


int main() {
    void * raw = std::malloc(sizeof(Point));
    
    Point * p1 = static_cast<Point*>(raw);
    (*p1).x = 0.24;
    p1->x = 0.24;    

    Point * p2 = static_cast<Point*>(std::malloc(sizeof(Point)));
    (*p2).x = 0.24;
    p2->x = 0.24;

    free(raw);

    Point * p3 = new Point{};
    (*p3).x = 0.24;
    p3->x = 0.24;

    delete p3;    
}
