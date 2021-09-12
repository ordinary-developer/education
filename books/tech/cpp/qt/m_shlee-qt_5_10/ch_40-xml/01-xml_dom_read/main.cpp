#include <QtXml>
#include <QFile>
#include <QDebug>


void traverseNode(QDomNode const& node);

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    QDomDocument domDoc{};
    QFile file{"address_book.xml"};
    if (file.open(QIODevice::ReadOnly)) {
        if (domDoc.setContent(&file)) {
            QDomElement domElement = domDoc.documentElement();
            traverseNode(domElement);
        }
        file.close();
    }
    
    return 0;
}

void traverseNode(QDomNode const& node) {
    QDomNode domNode = node.firstChild();
    while (not domNode.isNull()) {
        if (domNode.isElement()) {
            QDomElement domElement = domNode.toElement();
            if (not domElement.isNull()) {
                if ("contact" == domElement.tagName()) {
                    qDebug() << "attr: " << domElement.attribute("number", "");
                }                    
                else {
                    qDebug() << "TagName: " << domElement.tagName() << "\tText: " << domElement.text();
                }
           }
        }
        traverseNode(domNode);
        domNode = domNode.nextSibling();
    }
}