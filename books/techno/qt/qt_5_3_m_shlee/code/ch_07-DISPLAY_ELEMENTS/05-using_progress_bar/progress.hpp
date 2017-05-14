#pragma once

#include <QtWidgets>
class QProgressBar;


class Progress : public QWidget {
    Q_OBJECT

    public:
        Progress(QWidget* parentWidget = 0);

    public slots:
        void slotStep();
        void slotReset();

    private:
        QProgressBar* m_progressBar;
        int m_step;
};
