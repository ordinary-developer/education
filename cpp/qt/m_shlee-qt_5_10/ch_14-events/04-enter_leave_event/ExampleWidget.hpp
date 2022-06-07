#pragma once

#include <QtWidgets>

class ExampleWidget final : public QLabel {
    public:
        ExampleWidget(QWidget* pParWgt = nullptr);
        
    protected:
        virtual void enterEvent(QEvent* pEvent) final override;
        virtual void leaveEvent(QEvent* pEvent) final override;
};