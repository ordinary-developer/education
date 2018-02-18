class Coord { };

class Compositor {
    public:
        virtual int Compose(Coord natural[], 
                            Coord stretch[], 
                            Coord shrink[],
                            int componentCount, 
                            int lineWidth, 
                            int breaks[]) = 0;

    protected:
        Compositor() = default;
};

class Component { };

class Composition {
    public:
        Composition(Compositor* compositor) 
            : _compositor(compositor) {}

        void Repair() { 
            Coord* natural;
            Coord* stretchability;
            Coord* shrinkability;
            int componentCount;
            int* breaks;
            // do something
            int breakCount;
            breakCount = _compositor->Compose(natural,
                                              stretchability,
                                              shrinkability,
                                              componentCount,
                                              _lineWidth, breaks);
        }
    private:
        Compositor* _compositor;
        Component* _components;
        int _componentCount;
        int _lineWidth;
        int* _lineBreaks;
        int _lineCount;
};

class SimpleCompositor : public Compositor {
    public:
        SimpleCompositor() = default;

        virtual int Compose(Coord natural[], 
                            Coord stretch[], 
                            Coord shrink[],
                            int componentCount, 
                            int lineWidth, 
                            int breaks[]) final override { }
};

class TeXCompositor : public Compositor {
    public:
        TeXCompositor() = default;

        virtual int Compose(Coord natural[], 
                            Coord stretch[], 
                            Coord shrink[],
                            int componentCount, 
                            int lineWidth, 
                            int breaks[]) final override { }
};

class ArrayCompositor : public Compositor {
    public:
        ArrayCompositor() = default;

        virtual int Compose(Coord natural[], 
                            Coord stretch[], 
                            Coord shrink[],
                            int componentCount, 
                            int lineWidth, 
                            int breaks[]) final override { }
};

int main() {
    Composition* quick = new Composition(new SimpleCompositor);
    Composition* slick = new Composition(new TeXCompositor);
    Composition* iconic = new Composition(new ArrayCompositor());

    return 0;
}
