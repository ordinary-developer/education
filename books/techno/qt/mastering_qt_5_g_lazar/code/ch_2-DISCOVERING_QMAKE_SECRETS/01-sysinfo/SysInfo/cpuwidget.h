#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include "sysinfowidget.h"

#include<QtCharts/QPieSeries>

class CpuWidget : public SysInfoWidget
{
    Q_OBJECT
public:
    explicit CpuWidget(QWidget* parent = 0);

protected slots:
    virtual void updateSeries() override;

private:
    QtCharts::QPieSeries* mSeries;
};

#endif // CPUWIDGET_H
