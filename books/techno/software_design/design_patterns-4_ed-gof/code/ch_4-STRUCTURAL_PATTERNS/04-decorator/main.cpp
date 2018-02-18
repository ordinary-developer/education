class VisualComponent {
    public:
        VisualComponent() = default;

        virtual ~VisualComponent() = default;

        virtual void Draw() { }
        virtual void Resize() { }
};

class Decorator : public VisualComponent {
    public:
        Decorator(VisualComponent* component) 
            : _component(component) { }

        virtual ~Decorator() override = default;

        virtual void Draw() override { 
            _component->Draw();
        }
        virtual void Resize() override { 
            _component->Resize();
        }

    private:
        VisualComponent* _component;
};

class BorderDecorator : public Decorator {
    public:
        BorderDecorator(VisualComponent* component, int borderWidth)
            : Decorator(component), _width(borderWidth) { }

        virtual ~BorderDecorator() override = default;

        virtual void Draw() override {
            Decorator::Draw();
            DrawBorder(_width);
        }

    private:
        void DrawBorder(int width) { }

        int _width;
};

class TextView : public VisualComponent {
    public:
        virtual ~TextView() override = default;
};


class Window {
    public:
        void SetContents(VisualComponent* contents) {
            _contents = contents;
        }
    private:
        VisualComponent* _contents;
};

int main() {
    Window* window = new Window();
    TextView* textView = new TextView;
    window->SetContents(new BorderDecorator(textView, 1));

    return 0;
}
