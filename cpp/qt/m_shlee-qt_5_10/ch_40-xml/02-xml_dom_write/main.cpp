#include <QtXml>
#include <QDebug>


QDomElement makeElement(
    QDomDocument& domDoc,
    QString const& strName,
    QString const& strAttr = QString::null,
    QString const& strTxt = QString::null);

   
QDomElement contact(
    QDomDocument& domDoc,
    QString const& strName,
    QString const& strPhone,
    QString const& strEmail);
    

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {  
    QDomDocument doc{"addressbook"};
    QDomElement domElement = doc.createElement("addressbook");
    doc.appendChild(domElement);
    
    QDomElement contact1 =
        contact(doc, "Piggy", "+49 631322187", "piggy@media.de");
        
    QDomElement contact2 =
        contact(doc, "Kermit", "+49 631322181", "kermit@mega.de");
        
    QDomElement contact3 =
        contact(doc, "Gonzo", "+49 631322186", "gonzo@mega.de");
    
    domElement.appendChild(contact1);
    domElement.appendChild(contact2);
    domElement.appendChild(contact3);
    
    QFile file{"addressbook.xml"};
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream(&file) << doc.toString();
        file.close();
    }
    
	return 0; 
}

QDomElement makeElement(
    QDomDocument& domDoc,
    QString const& strName,
    QString const& strAttr /* = QString::null */,
    QString const& strTxt /* = QString::null */)
{
    QDomElement domElement = domDoc.createElement(strName);
    
    if (not strAttr.isEmpty()) {
        QDomAttr domAttr = domDoc.createAttribute("number");
        domAttr.setValue(strAttr);
        domElement.setAttributeNode(domAttr);
    }
    
    if (not strTxt.isEmpty()) {
        QDomText domTxt = domDoc.createTextNode(strTxt);
        domElement.appendChild(domTxt);
    }
    
    return domElement;
}

QDomElement contact(
    QDomDocument& domDoc,
    QString const& strName,
    QString const& strPhone,
    QString const& strEmail)
{
    static int num = 1;
    
    QDomElement domElement = makeElement(domDoc, "contact", QString{}.setNum(num));
    domElement.appendChild(makeElement(domDoc, "name", "", strName));
    domElement.appendChild(makeElement(domDoc, "phone", "", strPhone));
    domElement.appendChild(makeElement(domDoc, "email", "", strEmail));
    
    num++;
    
    return domElement;
}
