#include <memory>
#include <iostream>
#include <chrono>
#include <thread>

class Command {
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
};
using CommandPtr = std::shared_ptr<Command>;

class HelloWorldOutputCommand : public Command {
    public:
        virtual void execute() override {
            std::cout << "Hello world!" << "\n";
        }
};

class WaitCommand: public Command {
    public:
        explicit WaitCommand(unsigned int const& durationInMs) noexcept 
            : durationInMs_{ durationInMs } { }

        virtual void execute() override {
            std::chrono::milliseconds duration{ durationInMs_ };
            std::this_thread::sleep_for(duration);
        }

    private:
        unsigned int durationInMs_{ 1000 };
};

class Server {
    public:
        void acceptCommand(CommandPtr const& command) {
            command->execute();
        }
};

class Client {
    public:
        void run() {
            Server theServer{};
            unsigned int const SERVER_DELAY_TIMESPAN{ 3000 };

            CommandPtr waitCommand = 
                std::make_shared<WaitCommand>(SERVER_DELAY_TIMESPAN);
            theServer.acceptCommand(waitCommand);

            CommandPtr helloWorldOutputCommand =
                std::make_shared<HelloWorldOutputCommand>();
            theServer.acceptCommand(helloWorldOutputCommand);
        }
};


int main() {
    Client{}.run();

    return 0;
}
