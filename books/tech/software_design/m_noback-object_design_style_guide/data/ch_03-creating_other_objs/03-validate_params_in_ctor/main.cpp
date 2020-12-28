#include <stdexcept>
#include <cassert>
namespace workspace {

class ReservationRequest {
public:
    ReservationRequest(
        const int numOfRooms,
        const int numOfAdults,
        const int numOfChildren
        ) : _numOfRooms(numOfRooms), _numOfAdults(numOfAdults), _numOfChildren(numOfChildren) 
        {
            if (_numOfRooms > _numOfAdults + _numOfChildren)
                throw std::invalid_argument("num of rooms should not exceed num of guests");
            if (_numOfRooms < 1)
                throw std::invalid_argument("num of rooms should at least be 1");
            if (_numOfAdults < 1)
                throw std::invalid_argument("num of adults should at least be 1");
            if (_numOfChildren < 0)
                throw std::invalid_argument("num of children should at least be 0");
        }
private:
    const int _numOfRooms;
    const int _numOfAdults;
    const int _numOfChildren;
};

void _run_with_exception(const int numOfRooms, const int numOfAdults, const int numOfChildren) {
    bool wasException = false;

    try {
        ReservationRequest(numOfRooms, numOfAdults, numOfChildren);
    }
    catch (const std::invalid_argument&) { assert((wasException = true)); }
    catch (...) { assert((false)); }

    assert((wasException));
}

void run() {
    _run_with_exception(5, 1, 1);
    _run_with_exception(0, 1, 1);
    _run_with_exception(1, 0, 1);
    _run_with_exception(1, 1, -1);
}

} // workspace


int main() {
    workspace::run();
    return 0;
}
