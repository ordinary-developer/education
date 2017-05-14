#include "MyWeatherPrediction.hpp"

#include <iostream>


void MyWeatherPrediction::setCurrentTempCelsius(int inTemp) {
    int fahrenheitTemp = convertCelsiusToFahrenheit(inTemp);
    setCurrentTempFahrenheit(fahrenheitTemp);
    // nothing to do yet
}

int MyWeatherPrediction::getTomorrowTempCelsius() const {
    int fahrenheitTemp = getTomorrowTempFahrenheit();
    return convertFahrenheitToCelsius(fahrenheitTemp);
    // nothing to do yet
}

void MyWeatherPrediction::showResult() const {
    std::cout << "Tomorrow's temperature will be " <<
        getTomorrowTempCelsius() << " degrees Celsius (" <<
        getTomorrowTempFahrenheit() << " degrees Fahrenheit)" << std::endl;
    std::cout << "chance of rain is " << (getChanceOfRain() * 100) << 
        " percent" << std::endl;

    if (getChanceOfRain() > 0.5) {
        std::cout << "Bring an umbrella!" << std::endl;
    }
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int inCelsius) {
    return 0;
    // nothing to do yet
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int inFahrenheit) {
    return 0;
    // nothing to do yet
}


