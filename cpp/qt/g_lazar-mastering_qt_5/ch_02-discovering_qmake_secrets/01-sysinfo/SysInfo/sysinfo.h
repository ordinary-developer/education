#ifndef SYSINFO_H
#define SYSINFO_H


class SysInfo
{
public:
    static SysInfo& instance();
    virtual ~SysInfo() = default;

    SysInfo(SysInfo const&) = default;
    SysInfo& operator=(SysInfo const&) = default;

    virtual void init() = 0;
    virtual double cpuLoadAverage() = 0;
    virtual double memoryUsed() = 0;

protected:
    explicit SysInfo() = default;

private:
};

#endif // SYSINFO_H
