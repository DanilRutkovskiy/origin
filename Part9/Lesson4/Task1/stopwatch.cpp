#include "stopwatch.h"

Stopwatch::Stopwatch(int precition, QObject *parent):
    QObject{parent},
    m_lapNum{0},
    m_currentTime{0},
    m_lapTime{0},
    m_precition{precition},
    m_mode{Mode::Stopped}
{
    m_timer = new QTimer{this};
    m_timer->setInterval(m_precition);
    QObject::connect(m_timer, &QTimer::timeout, this, &Stopwatch::onUpdateTime);
}

void Stopwatch::start()
{
    m_mode = Mode::Started;
    m_timer->start();
}

void Stopwatch::stop()
{
    m_mode = Mode::Stopped;
    m_timer->stop();
}

void Stopwatch::reset()
{
    m_timer->stop();
    m_currentTime = 0;
    m_lapTime = 0;
    m_lapNum = 0;
    m_mode = Mode::Stopped;
    emit timeUpdated(m_currentTime);
}

std::pair<int, int> Stopwatch::lap()
{
    int temp = m_lapTime;
    m_lapNum += 1;
    m_lapTime = 0;

    return {m_lapNum, temp};
}

Stopwatch::Mode Stopwatch::getMode() const
{
    return m_mode;
}

void Stopwatch::onUpdateTime()
{
    m_currentTime += m_precition;
    m_lapTime += m_precition;
    emit timeUpdated(m_currentTime);
}
