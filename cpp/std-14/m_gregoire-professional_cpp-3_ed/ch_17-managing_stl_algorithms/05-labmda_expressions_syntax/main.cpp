#include <iostream>


auto main() -> int {
    auto basicLambda = [] { std::cout << "Hello from lambda" << std::endl; };
    basicLambda();

    auto parametersLambda = 
        [] (int value) { std::cout << "The value is " << value << std::endl; };
    parametersLambda(42);

    auto returningLambda = [] (int a, int b) -> int { return a + b; };
    int sum = returningLambda(11, 22);
    std::cout << "The result is " << sum << std::endl;

    auto returningLambda2 = [] (int a, int b) { return a + b; };
    int sum2 = returningLambda(11, 22);
    std::cout << "The result is " << sum2 << std::endl;

    double data = 1.23;
    auto capturingLambda = [data] { std::cout << "Data = " << data << std::endl; };
    capturingLambda();

    const double data2 = 1.23;
    auto capturingLambda2 = [data2] { std::cout << "Data = " << data2 << std::endl; };
    capturingLambda2();

    double data3 = 1.23;
    auto capturingLambda3 = [data3] () mutable 
    { data3 *= 2; std::cout << "Data = " << data3 << std::endl; };
    capturingLambda3();
    std::cout << data3 << std::endl;

    double data4 = 1.23;
    auto capturingLambda4 = [&data4] { data4 *= 2; };
    capturingLambda4();
    std::cout << data4 << std::endl;

    return 0;
}
