#include <iostream>

typedef int Topic;
const Topic NO_HELP_TOPIC = -1;

class HelpHandler {
    public:
        HelpHandler(HelpHandler* handler= 0, 
                    Topic topic = NO_HELP_TOPIC)
                    : _successor(handler), _topic(topic) { }

        virtual bool HasHelp() {
            return _topic != NO_HELP_TOPIC;
        }
        virtual void SetHandler(HelpHandler* handler,
                                Topic topic = NO_HELP_TOPIC)
        {
            _successor = handler;
            _topic = topic;
        }
                                
        virtual void HandleHelp() {
            if (_successor != 0) {
                _successor->HandleHelp();
            }
        }
    
    private:
        HelpHandler* _successor;
        Topic _topic;
};


class Widget : public HelpHandler {
    protected:
        Widget(Widget* parent, Topic t = NO_HELP_TOPIC)
               : HelpHandler(parent, t), _parent(parent) { }
    private:
        Widget* _parent; 
};

class Button : public Widget {
    public:
        Button(Widget* d, Topic t = NO_HELP_TOPIC) : Widget(d, t) { }

        virtual void HandleHelp() final override {
            if (HasHelp()) {
                std::cout << "Button has been worked" << std::endl;
            }
            else {
                HelpHandler::HandleHelp();
            }
        }
};

class Dialog : public Widget {
    public:
        Dialog(HelpHandler* h, Topic t = NO_HELP_TOPIC) 
               : Widget(0) 
        {
            SetHandler(h, t);
        }

        virtual void HandleHelp() final override {
            if (HasHelp()) {
                std::cout << "Dialog has been worked" << std::endl;
            }
            else {
                HelpHandler::HandleHelp();
            }
        }
};

class Application : public HelpHandler {
    public:
        Application(Topic t) : HelpHandler(0, t) { }

        virtual void HandleHelp() final override {
            std::cout << "The last point - application" << std::endl;
        }
};


const Topic PRINT_TOPIC = 1;
const Topic PAPER_ORIENTATION_TOPIC = 2;
const Topic APPLICATION_TOPIC = 3;



int main() {
    Application* application = new Application(APPLICATION_TOPIC);
    Dialog* dialog = new Dialog(application, PRINT_TOPIC);
    Button* button = new Button(dialog, PAPER_ORIENTATION_TOPIC);

    button->HandleHelp();

    return 0;
}
