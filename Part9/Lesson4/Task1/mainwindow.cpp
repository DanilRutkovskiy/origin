#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_stopwatch{new Stopwatch{100, this}}
{
    ui->setupUi(this);
    ui->lap_Btn->setEnabled(false);

    QObject::connect(m_stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateTime);
    QObject::connect(ui->start_stop_Btn, &QPushButton::clicked, this, &MainWindow::onStartStopBtnClicked);
    QObject::connect(ui->clear_Btn, &QPushButton::clicked, this, &MainWindow::onClearBtnClicked);
    QObject::connect(ui->lap_Btn, &QPushButton::clicked, this, &MainWindow::onLapBtnClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime(int currentTime)
{
    ui->full_time_label->setText(QString::number(currentTime / 1000.0));
}

void MainWindow::onStartStopBtnClicked()
{
    if(Stopwatch::Mode::Started == m_stopwatch->getMode()){
        m_stopwatch->stop();
        ui->start_stop_Btn->setText("Старт");
        ui->lap_Btn->setEnabled(false);
    }
    else if(Stopwatch::Mode::Stopped == m_stopwatch->getMode()){
        m_stopwatch->start();
        ui->start_stop_Btn->setText("Стоп");
        ui->lap_Btn->setEnabled(true);
    }
}

void MainWindow::onClearBtnClicked()
{
    m_stopwatch->reset();
    ui->start_stop_Btn->setText("Старт");
    ui->textEdit->clear();
    ui->lap_Btn->setEnabled(false);
}

void MainWindow::onLapBtnClicked()
{
    auto lap = m_stopwatch->lap();
    ui->textEdit->append("Круг " + QString::number(lap.first) + ": " + QString::number(lap.second / 1000.0) + "\n");
}
