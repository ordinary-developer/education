#include <stdexcept>
#include <cassert>
namespace workspace {

class ReservationRequest {
public:
    ReservationRequest(
        const int numOfRooms,
        const int numOfAdults,
        const int numOfChildren
        ) : numOfRooms_(numOfRooms), numOfAdults_(numOfAdults), numOfChildren_(numOfChildren) 
        {
            if (numOfRooms_ > numOfAdults_+ numOfChildren_)
                throw std::invalid_argument("num of rooms should not exceed num of guests");
            if (numOfRooms_< 1)
                throw std::invalid_argument("num of rooms should at least be 1");
            if (numOfAdults_< 1)
                throw std::invalid_argument("num of adults should at least be 1");
            if (numOfChildren_< 0)
                throw std::invalid_argument("num of children should at least be 0");
        }

private:
    const int numOfRooms_;
    const int numOfAdults_;
    const int numOfChildren_;
};

void run_with_exception(const int numOfRooms, const int numOfAdults, const int numOfChildren) {
    bool wasException = false;

    try {
        ReservationRequest(numOfRooms, numOfAdults, numOfChildren);
    }
    catch (const std::invalid_argument&) { assert((wasException = true)); }
    catch (...) { assert((false)); }

    assert((wasException));
}

void run() {
    run_with_exception(5, 1, 1);
    run_with_exception(0, 1, 1);
    run_with_exception(1, 0, 1);
    run_with_exception(1, 1, -1);
}

} // workspace


int main() {
    workspace::run();

    return 0;
}
