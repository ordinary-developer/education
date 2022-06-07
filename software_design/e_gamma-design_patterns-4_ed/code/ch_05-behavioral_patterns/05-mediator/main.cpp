#include <list>

class Widget;

class DialogDirector {
    public:
        virtual ~DialogDirector() = default;

        virtual void ShowDialog() = 0;
        virtual void WidgetChanged(Widget* ) = 0;

    protected:
        DialogDirector() = default;
        virtual void CreateWidgets() = 0;
};

class MouseEvent { };

class Widget {
    public:
        Widget(DialogDirector* director) 
            : _director(director) { }

        virtual void Changed() {
            _director->WidgetChanged(this);
        }

        virtual void HandleMouseEvent(MouseEvent& event) = 0;

    private:
        DialogDirector* _director;
};


class ListBox : public Widget {
    public:
        ListBox(DialogDirector* director) 
            : Widget(director) { }

        virtual char* GetSelection()
        { 
            char* empty_list_case = "bam";
            return (_list.empty()) ? _list.front() : empty_list_case;
        }

        virtual void SetList(std::list<char*>& listItems) {
            _list.insert(_list.begin(),
                         listItems.begin(), listItems.end());
        }

        virtual void HandleMouseEvent(MouseEvent& event) 
                                                final override
        {

        }

    private:
        std::list<char*> _list;
};

class EntryField : public Widget {
    public:
        EntryField(DialogDirector* director) 
            : Widget(director), _text(nullptr) { }

        virtual void SetText(char* text) { _text = text; }
        virtual char* GetText() { return _text; }

        virtual void HandleMouseEvent(MouseEvent& event) 
                                               final override
        {
        }


    private:
        char* _text;
};

class Button : public Widget {
    public:
        Button(DialogDirector* director) 
            : Widget(director) { }

        virtual void SetText(char* text) { _text = text; }
        virtual void HandleMouseEvent(MouseEvent& event) 
                                                    final override
        {
            Changed();
        }

    private:
        char* _text;
};

class FontDialogDirector : public DialogDirector {
    public:
        FontDialogDirector() {
            CreateWidgets();
        }

        virtual void ShowDialog() final override { 
            std::list<char*> strings = { "1", "2", "3" };
            _fontList->SetList(strings);

            MouseEvent event;
            _fontList->HandleMouseEvent(event);
        }


        virtual void WidgetChanged(Widget* widget) final override {
            if (_fontList == widget) {
                _fontName->SetText(_fontList->GetSelection());
            }
            else if (_ok == widget) {

            }
        }
    private:
        virtual void CreateWidgets() final override {
            _ok = new Button(this);
            _cancel = new Button(this);
            _fontList = new ListBox(this);
            _fontName = new EntryField(this);
        }

        Button* _ok;
        Button* _cancel;
        ListBox* _fontList;
        EntryField* _fontName;
};


int main() {
    FontDialogDirector director;
    director.ShowDialog();

    return 0;
}
