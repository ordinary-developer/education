#include <iostream>
namespace example01 {

template <int M, int K, int S>
struct MksUnit {
    enum { metre = M, kilogram = K, second = S };
};

template <typename MksUnit>
class Value {
    public:
        explicit Value(long double const magnitude)
            : magnitude_{ magnitude } {}

        long double getMagnitude() const { return magnitude_; }

    private:
        long double magnitude_{ 0.0 };
};

using DimensionlessQuantity = Value<MksUnit<0, 0, 0>>;
using Length = Value<MksUnit<1, 0, 0>>;
using Area = Value<MksUnit<2, 0, 0>>;
using Volume = Value<MksUnit<3, 0, 0>>;
using Mass = Value<MksUnit<0, 1, 0>>;
using Time = Value<MksUnit<0, 0, 1>>;
using Speed = Value<MksUnit<1, 0, -1>>;
using Acceleration = Value<MksUnit<1, 0, -2>>;
using Frequency = Value<MksUnit<0, 0, -1>>;
using Force = Value<MksUnit<1, 1, -2>>;
using Pressure = Value<MksUnit<-1, 1, -2>>;

using Momentum = Value<MksUnit<1, 1, -1>>;

class SpacecraftTrajectoryControl {
    public:
        void applyMomentumToSpacecraftBody(Momentum const& impulseValue) {}
};

void run() {
    SpacecraftTrajectoryControl control{};
    Momentum momentum{ 13.75 };
    control.applyMomentumToSpacecraftBody(momentum);
}

} // namespace example01

#include <iostream>
namespace example02 {

template <int M, int K, int S>
struct MksUnit {
    enum { metre = M, kilogram = K, second = S };
};

template <typename MksUnit>
class Value {
    public:
        constexpr explicit Value(long double const magnitude) noexcept
            : magnitude_{ magnitude } {}

        constexpr long double getMagnitude() const noexcept {
            return magnitude_;
        }

    private:
        long double magnitude_{ 0.0 };
};

using DimensionlessQuantity = Value<MksUnit<0, 0, 0>>;
using Length = Value<MksUnit<1, 0, 0>>;
using Area = Value<MksUnit<2, 0, 0>>;
using Volume = Value<MksUnit<3, 0, 0>>;
using Mass = Value<MksUnit<0, 1, 0>>;
using Time = Value<MksUnit<0, 0, 1>>;
using Speed = Value<MksUnit<1, 0, -1>>;
using Acceleration = Value<MksUnit<1, 0, -2>>;
using Frequency = Value<MksUnit<0, 0, -1>>;
using Force = Value<MksUnit<1, 1, -2>>;
using Pressure = Value<MksUnit<-1, 1, -2>>;

using Momentum = Value<MksUnit<1, 1, -1>>;

template <int M, int K, int S>
constexpr Value<MksUnit<M, K, S>> operator+ (
    Value<MksUnit<M, K, S>> const& lhs, 
    Value<MksUnit<M, K, S>> const& rhs)
noexcept
{
    return Value<MksUnit<M, K, S>>{ lhs.getMagnitude()
                                    + rhs.getMagnitude() };
}

template <int M, int K, int S>
constexpr Value<MksUnit<M, K, S>> operator- (
    Value<MksUnit<M, K, S>> const& lhs, 
    Value<MksUnit<M, K, S>> const& rhs)
noexcept
{
    return Value<MksUnit<M, K, S>>{ lhs.getMagnitude()
                                    - rhs.getMagnitude() };
}

template <int M1, int K1, int S1, int M2, int K2, int S2>
constexpr Value<MksUnit<M1 + M2, K1 + K2, S1 + S2>> operator* (
    Value<MksUnit<M1, K1, S1>> const& lhs,
    Value<MksUnit<M2, K2, S2>> const& rhs
) noexcept
{
    return Value<MksUnit<M1 + M2, K1 + K2, S1 + S2>>
            {lhs.getMagnitude() * rhs.getMagnitude() };
}

template <int M1, int K1, int S1, int M2, int K2, int S2>
constexpr Value<MksUnit<M1 - M2, K1 - K2, S1 - S2>> operator/ (
    Value<MksUnit<M1, K1, S1>> const& lhs,
    Value<MksUnit<M2, K2, S2>> const& rhs
) noexcept
{
    return Value<MksUnit<M1 - M2, K1 - K2, S1 - S2>>
            {lhs.getMagnitude() * rhs.getMagnitude() };
}

class SpacecraftTrajectoryControl {
    public:
        void applyMomentumToSpacecraftBody(Momentum const& impulseValue) {}
};

void run() {
    constexpr Acceleration gravitationAccelerationOnEarth{ 9.80665 };
    std::cout << gravitationAccelerationOnEarth.getMagnitude() 
              << std::endl;

    constexpr Pressure standardPressureOnSeaLevel{ 1013.25 };
    std::cout << standardPressureOnSeaLevel.getMagnitude()
              << std::endl;

    constexpr Speed speedOfLight{ 299792458.0 };
    std::cout << speedOfLight.getMagnitude() << std::endl;

    constexpr Frequency concertPitchA{ 440.0 };
    std::cout << concertPitchA.getMagnitude() << std::endl;

    constexpr Mass neutronMass{ 1.6749286e-27 };
    std::cout << neutronMass.getMagnitude() << std::endl;

    constexpr Momentum impulseValueForCourseCorrection =
        Force{ 30.0 } * Time{ 3.0 };
    SpacecraftTrajectoryControl control{};
    control.applyMomentumToSpacecraftBody(
        impulseValueForCourseCorrection);

}
} // namespace example02

#include <iostream>
namespace example03 {

template <int M, int K, int S>
struct MksUnit {
    enum { metre = M, kilogram = K, second = S };
};

template <typename MksUnit>
class Value {
    public:
        constexpr explicit Value(long double const magnitude) noexcept
            : magnitude_{ magnitude } {}

        constexpr long double getMagnitude() const noexcept {
            return magnitude_;
        }

    private:
        long double magnitude_{ 0.0 };
};

using DimensionlessQuantity = Value<MksUnit<0, 0, 0>>;
using Length = Value<MksUnit<1, 0, 0>>;
using Area = Value<MksUnit<2, 0, 0>>;
using Volume = Value<MksUnit<3, 0, 0>>;
using Mass = Value<MksUnit<0, 1, 0>>;
using Time = Value<MksUnit<0, 0, 1>>;
using Speed = Value<MksUnit<1, 0, -1>>;
using Acceleration = Value<MksUnit<1, 0, -2>>;
using Frequency = Value<MksUnit<0, 0, -1>>;
using Force = Value<MksUnit<1, 1, -2>>;
using Pressure = Value<MksUnit<-1, 1, -2>>;

using Momentum = Value<MksUnit<1, 1, -1>>;

constexpr Force operator"" _N(long double magnitude) {
    return Force(magnitude);
}

constexpr Acceleration operator"" _ms2(long double magnitude) {
    return Acceleration(magnitude);
}

constexpr Time operator"" _s(long double magnitude) {
    return Time(magnitude);
}

constexpr Momentum operator"" _Ns(long double magnitude) {
    return Momentum(magnitude);
}

void run() {
    constexpr Acceleration gravitationAccelerationOnEarth =
        9.80665_ms2;
    std::cout << gravitationAccelerationOnEarth.getMagnitude()
              << std::endl;

    Force force1{ 30.0_N };
    auto force2 = 3.0_N;

    Time time{ 3.0_s };

    constexpr auto acceleration = 100.0_ms2;
}
} // namespace example03

int main() {
    example01::run();
    example02::run();
    example03::run();

    return 0;
}
