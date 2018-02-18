#include <iostream>
#include <cstring>

class Point { };
class Event { };

class Graphic {
    public:
        virtual ~Graphic() = default;

        virtual void Draw(const Point& at) = 0;
        virtual void HandleMouse(Event& event) = 0;
        
        virtual const Point& GetExtent() = 0;

        virtual void Load(std::istream& from) = 0;
        virtual void Save(std::ostream& to) = 0;

    protected:
        Graphic() { }
};


class Image : public Graphic {
    public:
        Image(const char* file) { } 
        virtual ~Image() override = default;

        virtual void Draw(const Point& at) override { }
        virtual void HandleMouse(Event& event) override { }

        virtual const Point& GetExtent() override {
            return _point;
        }

        virtual void Load(std::istream& from) override { }
        virtual void Save(std::ostream& to) override { }
        
    private:
        Point _point;
};

class ImageProxy : public Graphic {
    public:
        ImageProxy(const char* imageFile) {
            unsigned int length = strlen(imageFile) + 1;

            _fileName = new char[length];
            for (unsigned int i = 0; i < length; ++i) {
                _fileName[i] = imageFile[i];
            }

            _image = 0;
        }
        virtual ~ImageProxy() override = default;

        virtual void Draw(const Point& at) override { 
            GetImage()->Draw(at);
        }
        virtual void HandleMouse(Event& event) override { 
            GetImage()->HandleMouse(event);
        }

        virtual const Point& GetExtent() override {
            return _extent;
        }

        virtual void Load(std::istream& from) override { 
            from >> _fileName;
        }
        virtual void Save(std::ostream& to) override { 
            to << _fileName;
        }

    protected:
        Image* GetImage() { 
            if (0 == _image) {
                _image = new Image(_fileName);
            }

            return _image;
        }

    private:
        Image* _image;
        Point _extent;
        char* _fileName;
};


class TextDocument {
    public:
        TextDocument() = default;

        void Insert(Graphic*) { } 
};


int main() {
    TextDocument* text = new TextDocument();
    text->Insert(new ImageProxy("anImageFileName"));

    return 0;
}
