#pragma once

#include <QtWidgets>


class ExampleWidget final : public QLabel {
    public:
        ExampleWidget(QWidget* pParWgt = nullptr);
        
    protected:
        virtual bool event(QEvent* pEvent) final override;
};