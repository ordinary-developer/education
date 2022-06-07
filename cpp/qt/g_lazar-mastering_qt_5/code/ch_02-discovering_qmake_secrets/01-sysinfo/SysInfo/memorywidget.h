#ifndef MEMORYWIDGET_H
#define MEMORYWIDGET_H

#include <QtCharts/QLineSeries>
#include "sysinfowidget.h"

class MemoryWidget : public SysInfoWidget
{
    Q_OBJECT
public:
    explicit MemoryWidget(QWidget* parent = 0);

protected slots:
    virtual void updateSeries() final override;

private:
    QtCharts::QLineSeries* mSeries;
    qint64 mPointPositionX;
};

#endif // MEMORYWIDGET_H
