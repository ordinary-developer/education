#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sysinfo.h"
#include <QWidget>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mCpuWidget(this),
    mMemoryWidget{this}
{
    ui->setupUi(this);
    SysInfo::instance().init();
    ui->centralWidget->layout()->addWidget(&mCpuWidget);
    ui->centralWidget->layout()->addWidget(&mMemoryWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
