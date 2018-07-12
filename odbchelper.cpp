#include "odbchelper.h"

odbchelper::odbchelper()
{
    this->db=QSqlDatabase::addDatabase("QODBC");
    QString conn = "Driver={PostgreSQL UNICODE(x64)};Server=127.0.0.1;Port=5433;Uid=postgres;Pwd=postgres;Database=database";
    this->db.setDatabaseName(conn);
    if(!this->db.open())
    {
        QMessageBox::critical(0,QString("odbc error"), QString("???open db error").arg(this->db.lastError().text()));
        return;
    }

}

void odbchelper::getpointid()
{
    QSqlQuery *query = new QSqlQuery(db);
    QString sql = "select id from mycollardata order by id";
//    query->bindValue(0,100);

    query->exec(sql);
    int i=0;
    while(query->next())
    {
        qDebug()<<query->value(0).toInt();
        i++;
    }
    qDebug()<<i;
}
