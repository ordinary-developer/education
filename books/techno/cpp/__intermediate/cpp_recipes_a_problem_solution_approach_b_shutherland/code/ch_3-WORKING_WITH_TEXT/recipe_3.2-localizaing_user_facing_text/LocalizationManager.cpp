#include "LocalizationManager.h"

#include <sstream>

namespace Localization {

Manager::Manager() {
    static const uint32_t 
        INDEX_EN_US{ static_cast<uint32_t>(Languages::EN_US) };
    m_StringPacks[INDEX_EN_US][STRING_COLOR] = "COLOR";

    static const uint32_t 
        INDEX_EN_GB{ static_cast<uint32_t>(Languages::EN_GB) };
    m_StringPacks[INDEX_EN_GB][STRING_COLOR] = "COLOUR";

    SetLanguage(Languages::EN_US);
}

void Manager::SetLanguage(Languages language) {
    m_CurrentStringPack = 
        &(m_StringPacks[static_cast<uint32_t>(language)]);
}

std::string Manager::GetString(StringID stringId) const {
    std::stringstream resultStream;
    resultStream << "!!!" << stringId << "!!!";
    std::string result{ resultStream.str() };

    auto iter = m_CurrentStringPack->find(stringId);
    if (iter != m_CurrentStringPack->end())
        result = iter->second;

    return result;
}

}
