#ifndef MY_WEATHER_PREDICTION_HPP
#define MY_WEATHER_PREDICTION_HPP

#include "WeatherPrediction.hpp"

class MyWeatherPrediction : public WeatherPrediction {
    public:
        virtual void setCurrentTempCelsius(int inTemp);
        virtual int getTomorrowTempCelsius() const;
        virtual void showResult() const override;
    private:
        static int convertCelsiusToFahrenheit(int inCelsius);
        static int convertFahrenheitToCelsius(int inFahrenheit);
};
#endif

