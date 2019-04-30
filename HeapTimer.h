#ifndef __HEAPTIMER_H__
#define __HEAPTIMER_H__

#include <time.h>
#include "Heap.h"

#define TIMER_ONESHOT          0
#define TIMER_PERIODIC         1

typedef void (*call_back)(void *arg);

class TimerData
{
public:
    TimerData():m_expire(0), m_type(0), m_callback(NULL), m_arg(NULL)
    {
    }
    
    TimerData(int type, int delay, call_back cb, void *arg):m_type(type), m_delay(delay), m_callback(cb), m_arg(arg)
    {
        m_expire = time(NULL) + delay;
    }

    virtual ~TimerData()
    {
    }
    
    friend bool operator<(const TimerData& a, const TimerData& b)
    {
        return a.m_expire < b.m_expire;
    }
    
public:
    time_t     m_expire;  /* 超时绝对时间 */
    int        m_delay;
    call_back  m_callback;
    int        m_type;
    void      *m_arg;
};

class HeapTimer
{
public:
    void *StartTimer(int type, int delay, call_back cb, void *arg);
    void *RestartTimer(TimerData& timer);
    bool StopTimer(TimerData& timer);
    bool PopTimer();
    void Tick();
private:
    Heap<TimerData, Less<TimerData> >  m_hp;
};

#endif

