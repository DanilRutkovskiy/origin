#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QTimer>
#include <QObject>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    enum class Mode{
        Started,
        Stopped
    };
public:
    explicit Stopwatch(int precition, QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    std::pair<int, int> lap();
    Mode getMode() const;

signals:
    void timeUpdated(int currentTime);

private slots:
    void onUpdateTime();

private:
    QTimer* m_timer;
    int m_lapNum;
    int m_lapTime;
    int m_currentTime;
    int m_precition;
    Mode m_mode;
};

#endif // STOPWATCH_H
