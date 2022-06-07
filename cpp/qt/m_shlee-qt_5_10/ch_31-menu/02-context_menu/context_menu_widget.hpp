#include <QtWidgets>
class ContextMenuWidget final : public QTextEdit {
Q_OBJECT

public:
    ContextMenuWidget(QWidget *pWgt = nullptr);

public slots:
    void slotActivated(QAction *pAction);

protected:
    virtual void contextMenuEvent(QContextMenuEvent *pEvent) final override;

private:
    QMenu *pMenu_;
};
