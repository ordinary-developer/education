#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H

#include <QtGlobal>
#include <QVector>
#include "sysinfo.h"

class SysInfoLinuxImpl : public SysInfo
{
public:
    SysInfoLinuxImpl();
    virtual ~SysInfoLinuxImpl() final override = default;

    virtual void init() final override;
    virtual double cpuLoadAverage() final override;
    virtual double memoryUsed() final override;

private:
    QVector<qulonglong> cpuRawData();

    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOLINUXIMPL_H
