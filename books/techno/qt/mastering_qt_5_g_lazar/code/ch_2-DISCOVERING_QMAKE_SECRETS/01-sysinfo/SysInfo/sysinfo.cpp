#include "sysinfo.h"

#include <QtGlobal>

#ifdef Q_OS_LINUX
    #include "sysinfolinuximpl.h"
#endif

SysInfo& SysInfo::instance()
{
    #ifdef Q_OS_LINUX
        static SysInfoLinuxImpl singleton{};
    #endif

    return singleton;
}
