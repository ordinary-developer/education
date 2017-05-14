#ifndef __SCPP_ASSERT_HPP_INCLUDED__
#define __SCPP_ASSERT_HPP_INCLUDED__

#include <sstream>

#ifdef SCPP_THROW_EXCEPTION_ON_BUG
#include <exception>

namespace scpp {
    class ScppAssertFailedException : public std::exception {
        public:
            ScppAssertFailedException(const char* file_name,
                                      unsigned long line_number,
                                      const char* message) { }

            virtual ~ScppAssertFailedExceptiono() throw() { }

            virtual const char* what() const throw() {
                return what_.c_str();
            }

        private:
            std::string what_;
    };
}
#endif // SCPP_THROW_EXCEPTION_ON_BUG

void SCPP_AssertErrorHandler(const char* file_name,
                             unsigned line_number,
                             const char* message);

#define SCPP_ASSERT(condition, msg)                 \
    if (!(condition)) {                             \
        std::ostringstream s;                       \
        s << msg;                                   \
        SCPP_AssertErrorHandler(__FILE__,           \
                                __LINE__,           \
                                s.str().c_str());   \
    }                                               \

#ifdef _DEBUG
    #define SCPP_TEST_ASSERT_ON
#endif

#ifdef SCPP_TEST_ASSERT_ON
    #define SCPP_TEST_ASSERT(condition, msg) SCPP_ASSERT(condition, \
                                                         msg)       \

#else
    #define SCPP_TEST_ASSERT(condition, msg) //do nothing
#endif


#endif // __SCPP_ASSERT_HPP_INCLUDED__
