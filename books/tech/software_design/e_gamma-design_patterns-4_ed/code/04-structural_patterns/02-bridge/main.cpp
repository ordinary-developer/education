#include <iostream>

class WindowImp {
    public:
        virtual void DeviceBitmap() = 0;
};

class IconWindowImp : public WindowImp {
    public:
        virtual void DeviceBitmap() override { 
            std::cout << "\t-> IconWindowImp->draw()" << std::endl;
        }
};

class WindowSystemFactory {
    public:
        static WindowSystemFactory* Instance() {
            if (_instance == 0) {
                _instance = new WindowSystemFactory;
            }
            return _instance;
        }

        virtual WindowImp* MakeWindowImp() {
            return new IconWindowImp();
        }
    protected:
        WindowSystemFactory() { }
    private:
        static WindowSystemFactory* _instance;
};

class View { };
class Window {
    public:
        Window(View* contents) :
            _contents(contents) { }

        virtual void DrawContents() = 0;

    protected:
        WindowImp* GetWindowImp() { 
            if (_imp == 0) {
                _imp = 
                    WindowSystemFactory::Instance()->MakeWindowImp();
            }
            return _imp;
        }
        View* GetView() { return _contents; }
    private:
        WindowImp* _imp;
        View* _contents;
};


class IconWindow : public Window {
    public:
        IconWindow(View* contents) : Window(contents) { }

        virtual void DrawContents() override {
            std::cout << "-> IconWindow->draw()" << std::endl;
            WindowImp* imp = GetWindowImp();
            if (imp != 0) {
                imp->DeviceBitmap();
            }
        }
};

WindowSystemFactory* WindowSystemFactory::_instance = 0;

int main() {
    View* view = new View();
    Window* window = new IconWindow(view);
    window->DrawContents();

    return 0;
}
