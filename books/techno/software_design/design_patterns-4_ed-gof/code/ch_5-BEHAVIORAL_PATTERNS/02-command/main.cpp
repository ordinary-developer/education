#include <iostream>

class Command {
    public:
        virtual ~Command() = default;
        virtual void Execute() = 0;

    protected:
        Command() { }
};

class Document {
    public:
        explicit Document(char* name)
            :_name(name) { }

        void Open() {
            std::cout << "-> [APP]::openning - " << _name << std::endl;
        }

        void Paste() {
            std::cout << "-> [DOC]::pasting" << std::endl;
        }

    private:
        char* _name;
};

class Application { 
    public:
        void Add(Document* document) { 
            std::cout << "-> adding a doc to the app" << std::endl;
        }
};

class OpenCommand : public Command {
    public:
        explicit OpenCommand(Application* application)
            : _application(application) { }

        virtual ~OpenCommand() final override = default;

        virtual void Execute() final override {
            char* name = AskUser();
            if (0 != name) {
                Document* document = new Document(name);
                _application->Add(document);
                document->Open();
            }
        }

    protected:
        virtual char* AskUser() { return "42"; }

    private:
        Application* _application;
};

class PasteCommand : public Command {
    public:
        PasteCommand(Document* document) 
            : _document(document) { }

        virtual ~PasteCommand() final override = default;

        virtual void Execute() final override {
            _document->Paste();
        }

    private:
        Document* _document;
};


class Receiver {
    public:
        void DoSomething() { 
            std::cout << "->[Receiver]::action calling" << std::endl;
        }
};

template <class ReceiverType>
class SimpleCommand : public Command {
    public:
        typedef void (ReceiverType::*Action)();

        SimpleCommand(ReceiverType* receiver, Action action)
            : _receiver(receiver), _action(action) { }

        virtual ~SimpleCommand() final override = default;

        virtual void Execute() final override {
            (_receiver->*_action)();
        }
        
    private:
        ReceiverType* _receiver;
        Action _action;
};

#include <vector>

class MacroCommand : public Command {
    public:
        MacroCommand() { }

        virtual ~MacroCommand() final override = default;

        virtual void Add(Command* command) {
            _commands.push_back(command); 
        }

        // a dump method
        virtual void Remove(Command* command) { }


        virtual void Execute() {
            for (const auto command : _commands) {
                command->Execute();    
            }
        }

    private:
        std::vector<Command*> _commands;
};


int main() {
    Receiver* receiver = new Receiver;
    Command* command = new SimpleCommand<Receiver>(receiver, 
                                                  &Receiver::DoSomething);
    command->Execute();

    return 0;
}
