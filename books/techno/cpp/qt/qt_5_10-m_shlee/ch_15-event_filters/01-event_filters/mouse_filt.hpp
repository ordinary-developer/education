#pragma once

#include <QObject>

class MouseFilter : public QObject {
    public:
        MouseFilter(QObject* parObj = nullptr);
    
    protected:
        virtual bool eventFilter(QObject*, QEvent*) final override;
};
