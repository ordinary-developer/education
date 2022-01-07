#ifndef WEATHER_PREDICTION_HPP
#define WEATHER_PREDICTION_CPP

#include <string>


class WeatherPrediction {
    public:
        virtual ~WeatherPrediction();
        virtual auto setCurrentTempFahrenheit(int inTemp) -> void;
        virtual auto setPositionOfJupiter(int inDistanceFromMars) -> void;
        virtual int getTomorrowTempFahrenheit() const;
        virtual double getChanceOfRain() const;
        virtual void showResult() const;
        virtual std::string getTemperature() const;
    private:
        int mCurrentTempFahrenheit;
        int mDistanceFromMars;
};

#endif
