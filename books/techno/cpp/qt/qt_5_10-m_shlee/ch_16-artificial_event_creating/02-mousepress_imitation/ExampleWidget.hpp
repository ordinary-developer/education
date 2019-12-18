#pragma once

#include <QLabel>


class ExampleWidget final : public QLabel {
    public:
        ExampleWidget(QWidget * pParWgt = nullptr);
        
    protected:
        virtual void mousePressEvent(QMouseEvent *pEvent) final override;
};
