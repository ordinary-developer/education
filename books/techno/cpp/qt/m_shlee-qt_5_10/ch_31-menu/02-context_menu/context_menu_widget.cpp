#include "context_menu_widget.hpp"

ContextMenuWidget::ContextMenuWidget(QWidget *pWgt /* = nullptr */) : QTextEdit{ pWgt } {
    setReadOnly(true);
    
    pMenu_ = new QMenu{ this };
    pMenu_->addAction("red");
    pMenu_->addAction("green");
    pMenu_->addAction("blue");
    
    connect(pMenu_,
        &QMenu::triggered,
        this,
        &ContextMenuWidget::slotActivated);
}

void ContextMenuWidget::slotActivated(QAction *pAction) {
    const QString strColor = pAction->text().remove("&");
    setHtml(QString{ "<body bgcolor=%1></body>" }.arg(strColor));
}

void ContextMenuWidget::contextMenuEvent(QContextMenuEvent *pEvent) {
    pMenu_->exec(pEvent->globalPos());
}
