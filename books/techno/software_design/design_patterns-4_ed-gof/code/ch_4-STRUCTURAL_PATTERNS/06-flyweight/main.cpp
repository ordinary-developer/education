class Window { };

class Font { 
    public:
        Font(char* str) : _str(str) { }
    
    private:
        char* _str;
};

class BTree { };

class GlyphContext {
    public:
        GlyphContext() = default;
        virtual ~GlyphContext() = default;

        virtual void Next(int step = 1) { 
            _index += step;
        }
        virtual void Insert(int quantity = 1) { }

        virtual Font* GetFont() { return new Font("a dump string"); }
        virtual void SetFont(Font*, int span = 1) { }

    private:
        int _index;
        BTree* _fonts;
};

class Glyph {
    public:
        virtual ~Glyph() = default;

        virtual void Draw(Window*, GlyphContext& ) { }
        virtual void SetFont(Font*, GlyphContext& ) { }
        virtual Font* GetFont(GlyphContext&) { 
            return new Font("a dump string"); 
        }

        virtual void First(GlyphContext&) { }
        virtual void Next(GlyphContext& glyphContext) { 
            glyphContext.Next();
        }
        virtual bool IsDone(GlyphContext&) { return true; }
        virtual Glyph* Current(GlyphContext&) { return this; }

        virtual void Insert(Glyph*, GlyphContext&) { }
        virtual void Remove(GlyphContext&) { } 

    protected:
        Glyph() = default;
};

class Character : public Glyph {
    public:
        Character(char charCode) : _charCode(charCode) { }

        virtual void Draw(Window*, GlyphContext&) override { }

    private:
        char _charCode;
};

const int NCHARCODES = 128;

class Row { };
class Column { };

class GlyphFactory {
    public:
        GlyphFactory() {
            for (int i = 0; i < NCHARCODES; ++i) {
                _character[i] = 0;
            }
        }

        virtual ~GlyphFactory() = default;

        virtual Character* CreateCharacter(char c) {
            if (!_character[c]) {
                _character[c] = new Character(c);
            }

            return _character[c];
        }

        virtual Row* CreateRow() { return new Row(); }
        virtual Column* CreateColumn() { return new Column(); }

    private:
        Character* _character[NCHARCODES];
};

int main() {
    GlyphContext gc;

    Font* times12 = new Font("Times-Roman-12");
    Font* timesItalic12 = new Font("Times-Italic-12");
    gc.SetFont(times12, 6);

    gc.Insert(6);
    gc.SetFont(timesItalic12, 6);


    return 0;
}
