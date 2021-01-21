#include <memory>
#include <iostream>
#include <stack>
#include <vector>

class Command {
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
};

class Revertable {
    public:
        virtual ~Revertable() = default;
        virtual void undo() = 0;
};

class UndoableCommand : public Command, public Revertable {};
using CommandPtr = std::shared_ptr<UndoableCommand>;

// dumb realization
class Point {};

// dumb realization
class DrawingProcessor {
    public:
        void drawCircle(Point const& center, double const radius) {
            std::cout << "drawing a circle" << std::endl;
        }

        void eraseCircle(Point const& center, double const radius) {
            std::cout << "erasing a circle" << std::endl;
        }
};

class DrawCircleCommand : public UndoableCommand {
    public:
        DrawCircleCommand(DrawingProcessor& receiver,
                          Point const& centerPoint,
                          double const radius) noexcept 
            : receiver_{ receiver }, 
              centerPoint_{ centerPoint }, 
              radius_{ radius } { }

        virtual void execute() override {
            receiver_.drawCircle(centerPoint_, radius_);
        }

        virtual void undo() override {
            receiver_.eraseCircle(centerPoint_, radius_);
        }
        
    private:
        DrawingProcessor& receiver_;
        Point const centerPoint_;
        double const radius_;
};

class CommandProcessor {
    public:
        void execute(CommandPtr const& command) {
            command->execute();
            commandHistory_.push(command);
        }

        void undoLastCommand() {
            if (commandHistory_.empty())
                return;

            commandHistory_.top()->undo();
            commandHistory_.pop();
        }

    private:
        std::stack<std::shared_ptr<Revertable>> commandHistory_;
};

class UndoCommand : public UndoableCommand {
    public:
        explicit UndoCommand(CommandProcessor& receiver) noexcept :
            receiver_{ receiver } {}

        virtual void execute() override {
            receiver_.undoLastCommand();
        }

        virtual void undo() override {
            //
        }

    private:
        CommandProcessor& receiver_;
};

// material for the "Composite" pattern
class CompositeCommand : public UndoableCommand {
    public:
        void addCommand(CommandPtr& command) {
            commands_.push_back(command);
        }
        
        virtual void execute() override {
            for (auto const& command : commands_)
                command->execute();
        }

        virtual void undo() override {
            for (auto const& command : commands_)
                command->undo();
        }

    private:
        std::vector<CommandPtr> commands_;
};

int main() {
    CommandProcessor commandProcessor{};
    DrawingProcessor drawingProcessor{};

    auto macroRecorder = std::make_shared<CompositeCommand>();

    Point circleCenterPoint{};
    CommandPtr drawCircleCommand =
        std::make_shared<DrawCircleCommand>(drawingProcessor,
                                            circleCenterPoint,
                                            10);
    commandProcessor.execute(drawCircleCommand);
    macroRecorder->addCommand(drawCircleCommand);

    commandProcessor.execute(macroRecorder);

    CommandPtr undoCommand = 
        std::make_shared<UndoCommand>(commandProcessor);
    commandProcessor.execute(undoCommand);

    return 0;
}
