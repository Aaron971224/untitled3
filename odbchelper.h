#ifndef ODBCHELPER_H
#define ODBCHELPER_H
#include "QtSql/qsqlquery.h"
#include "QtSql/qsqldatabase.h"
#include "QtSql/qsqlerror.h"
#include <QDebug>
#include <QMessageBox>

class odbchelper{
public:
    odbchelper();
    void getpointid();
    QSqlDatabase db;
};
#endif // ODBCHELPER_H
