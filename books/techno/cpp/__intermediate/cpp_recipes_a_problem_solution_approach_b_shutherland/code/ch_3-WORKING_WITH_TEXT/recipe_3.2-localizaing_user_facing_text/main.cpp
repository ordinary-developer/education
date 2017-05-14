#include "LocalizationManager.h"

#include <iostream>

int main() {
    Localization::Manager localizationManager;
    std::string color =
        localizationManager.GetString(Localization::STRING_COLOR);
    std::cout << "EN_US Localized string: " << color << std::endl;

    localizationManager.SetLanguage(Localization::Languages::EN_GB);
    color = 
        localizationManager.GetString(Localization::STRING_COLOR);
    std::cout << "EN_GB Localized string: " << color << std::endl;

    color = localizationManager.GetString(1);
    std::cout << color << std::endl;

    return 0;
}

