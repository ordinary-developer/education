#include <QDate>
#include <QDebug>
namespace example {
    
void run() {
    {
        QDate date{ 2017, 10, 25 };
        qDebug() << "year:" << date.year() << "month:" << date.month() << "day:" << date.day(); 
    
        QDate dateAux;
        dateAux.setDate(2017, 10, 25);
        qDebug() << "year:" << dateAux.year() << "month:" << dateAux.month() << "day:" << dateAux.day(); 
    }
    
    {
        QDate date{ 2017, 10, 25 };
        qDebug() << "days in month:" << date.daysInMonth() << "days in year:" << date.daysInYear();
        qDebug() 
            << "day of week:" << date.dayOfWeek() 
            << "day of year:" << date.dayOfYear()
            << "week number:" << date.weekNumber();
    }
    
    {
        QString str{};
        QDate date(2017, 7, 3);
        
        str = date.toString(Qt::TextDate);
        qDebug() << str;
        
        str = date.toString(Qt::ISODate);
        qDebug() << str;
        
        str = date.toString("d.M.yy");
        qDebug() << str;
        
        str = date.toString("dd/MM/yy");
        qDebug() << str;
        
        str = date.toString("yyyy.MMM.ddd");
        qDebug() << str;
        
        str = date.toString("yyyy.MMMM.dddd");
        qDebug() << str;
    }
    
    {
        QDate date{ 2017, 1, 3 };
        QDate date2 = date.addDays(-7);
        qDebug() << date2.toString("dd/MM/yyyy");
    }
    
    {
        QDate date{ QDate::fromString("27/12/2016", "dd/MM/yyyy") };
        qDebug() << date.toString(Qt::ISODate);
    }
    
    {
        QDate dateToday = QDate::currentDate();
        QDate dateNewYear{ dateToday.year(), 12, 31 };
        qDebug() << dateToday.daysTo(dateNewYear) << "remains until New Year";
    }
    
    {
        QDate date1{ 2017, 1, 3 };
        QDate date2{ 2017, 1, 5 };
        bool b = (date1 == date2);
        qDebug() << b;
    }
}
} // example


#include <QDebug>
int main(int, char**) {
    qDebug() << "example => "; example::run(); qDebug() << "";
    
    return 0;
}
