#include <string>
#include <memory>

class Password1 {
    public:
        explicit Password1(std::string pwd) 
            : text(std::move(pwd)) { }

        void changeTo(std::string newPwd) {
            text = std::move(newPwd);
        }

    private:
        std::string text;
};

class Password2 {
    public:
        explicit Password2(const std::string& pwd) 
            : text(pwd) { }

        void changeTo(const std::string& newPwd) {
            text = newPwd;
        }

    private:
        std::string text;
};


int main() {
    std::string initPwd("as;lfkajs;dlfkajsldfj");
    Password1 p1(initPwd);
    Password2 p2(initPwd);
    std::string newPassword = "Beware the jabberwock";
    p1.changeTo(newPassword);
    p2.changeTo(newPassword);


    return 0;
}
