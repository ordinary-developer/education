#include <vector>

class Widget {
};

// a dumb function
std::vector<bool> features(const Widget& w) {
    std::vector<bool> resultVector(5, true);
    return resultVector;
}

// a dumb function
void processWidget(Widget& w, bool value) {
}


int main() {
    Widget w;

    // all right
    bool highPriority1 = features(w)[5];
    processWidget(w, highPriority1);

    // the type of highPriority 2 is vector<bool>::reference
    // it points to a temporary object returned by features(w)
    // and this object will be destroyed in the next string
    auto highPriority2 = features(w)[5];
    // undefiend behavior
    processWidget(w, highPriority2);

    // the correct way
    auto highPriority3 = static_cast<bool>(features(w)[5]);
    processWidget(w, highPriority3);
}
