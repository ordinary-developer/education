// a dumb function
double calculateEpsilon() {
    return 1.0;
}

int main() {
    // implicit convertion: double -> float
    float epsilon1 = calculateEpsilon();

    // explicit convertion
    auto epsilon2 = static_cast<float>(calculateEpsilon());
}
