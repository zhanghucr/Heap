#include "HeapTimer.h"

void *HeapTimer::StartTimer(int type, int delay, call_back cb, void *arg)
{
    TimerData  *timer;

    if (delay <= 0 || cb == NULL)
    {
        return NULL;
    }

    timer = new TimerData(type, delay, cb, arg);
    if (timer == NULL)
    {
        return NULL;
    }

    m_hp.Push(*timer);
    return timer;
}

void *HeapTimer::RestartTimer(TimerData& timer)
{
    timer.m_expire = time(NULL) + timer.m_delay;
    m_hp.Push(timer);
    return &timer;
}

bool HeapTimer::StopTimer(TimerData& timer)
{
    timer.m_callback = NULL;
    return true;
}

bool HeapTimer::PopTimer()
{
    TimerData  timer;
    return m_hp.Pop(timer);
}

void HeapTimer::Tick()
{
    time_t currTime = time(NULL);
    
    while (m_hp.Size())
    {
        TimerData timer = m_hp.Top();
        if (timer.m_expire > currTime)
        {
            break;
        }
        
        if (timer.m_callback != NULL )
        {
            timer.m_callback(timer.m_arg);
        }
        
        PopTimer();

        if (timer.m_type == TIMER_PERIODIC)
        {
            RestartTimer(timer);
        }
    }
}

