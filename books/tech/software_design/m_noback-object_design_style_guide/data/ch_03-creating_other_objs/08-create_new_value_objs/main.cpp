#include <string>
#include <stdexcept>
#include <cassert>
namespace workspace {

class EmailAddress {
public:
    static bool is_valid_email_address(const std::string& emailAddress) { // -> a dummy func for testing purposes only
        return std::string::npos != emailAddress.find("@");
    }

    EmailAddress(const std::string& emailAddress) : emailAddress_(emailAddress) {
        if (!is_valid_email_address(emailAddress)) 
            throw std::invalid_argument("invalid email address");
    }
private:
    const std::string& emailAddress_;
};

class User {
public:
    User(const EmailAddress& emailAddress) : emailAddress_(emailAddress) {}

    User changeEmailAddress(const EmailAddress& emailAddress) { return User(emailAddress); }
private:
    EmailAddress emailAddress_;
};

void run() {
    User user(EmailAddress("correct_email_address@domain"));
    user.changeEmailAddress(EmailAddress("new_correct_email_address@domain"));
    assert((true));

    {
        bool wasException = false;

        try {
            EmailAddress("incorrect_email_address");
        }
        catch (const std::invalid_argument& e) {
            assert((std::string("invalid email address") == std::string(e.what())));
            assert((wasException = true));
        }
        catch (...) { assert((false)); }

        assert((wasException));
    }

    {
        bool wasException  = false;
        try {
            User(EmailAddress("correct_email_address@domain"))
                .changeEmailAddress(EmailAddress("incorrect_email_address"));
        }
        catch (const std::invalid_argument& e) {
            assert((std::string("invalid email address") == std::string(e.what())));
            assert((wasException = true));
        }
        catch (...) { assert((false)); }

        assert((wasException));
    }
}

} // workspace


int main() {
    workspace::run();
    return 0;
}
