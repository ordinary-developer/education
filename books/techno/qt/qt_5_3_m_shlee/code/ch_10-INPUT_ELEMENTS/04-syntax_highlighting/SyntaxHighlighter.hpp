#pragma once

#include <QSyntaxHighlighter>

class QTextDocument;


class SyntaxHighlighter : public QSyntaxHighlighter {
    Q_OBJECT
    public:
        SyntaxHighlighter(QTextDocument* parent = 0);

    protected:
        enum { NormalState = -1, InsideCStyleComment, InsideCString };
        virtual void highlightBlock(const QString&) final override;
        QString getKeyword(int i, const QString& str) const;

    private:
        QStringList m_lstKeywords;
};
