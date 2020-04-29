#pragma once

#include <QtWidgets>

class WidgetMimeData : public QMimeData {
    public:
        virtual ~WidgetMimeData() = default;

        static QString mimeType() { return "application/widget"; }

        void setWidget(QWidget* pWgt) {
            pWgt_ = pWgt;
            setData(mimeType(), QByteArray{});
        }

        QWidget* widget() const { return pWgt_; }

    private:
        QWidget* pWgt_;
};

class WidgetDrag : public QDrag {
    public:
        WidgetDrag(QWidget* pWgtDragSrc = nullptr) 
            : QDrag(pWgtDragSrc) {}

        void setWidget(QWidget* pWgt) {
            WidgetMimeData* pMd{ new WidgetMimeData{} };
            pMd->setWidget(pWgt);
            setMimeData(pMd);
        }
};
