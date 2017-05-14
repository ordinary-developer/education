#include "scpp_assert.hpp"

#include <iostream>
#include <stdlib.h>

#ifdef SCPP_THROW_EXCEPTION_ON_BUG
namespace scpp {
    ScppAssetFailedException::ScppAssertFaliedException(
        const char* file_name, 
        unsigned line_number,
        const char* message)
    {
        std::ostringstream s;
        s << "SCPP assertion falied with message '" << message
          << "' in file " << file_name << " #" << line_number;

        what_ = s.str();
    }
}
#endif // SCPP_THROW_EXCEPTION_ON_BUG


void SCPP_AssertErrorHandler(const char* file_name,
                             unsigned line_number,
                             const char* message)
{
#ifdef SCPP_THROW_EXCEPTION_ON_BUG
    throw scpp::ScppAssertFaliedException(file_name,
                                          line_number,
                                          message);
#else
    std:: cerr << message << " in file " << file_name 
               << " #" << line_number << std::endl << std::flush;
    exit(1);
#endif
}
