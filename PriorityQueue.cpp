#include "PriorityQueue.h"

template<typename T, typename COM>
PriorityQueue<T, COM>::PriorityQueue()
{
}

template<typename T, typename COM>
PriorityQueue<T, COM>::~PriorityQueue()
{
}

template<typename T, typename COM>
void PriorityQueue<T, COM>::Push(const T& x)
{
    m_hp.Push(x);
}

template<typename T, typename COM>
bool PriorityQueue<T, COM>::Pop(T& x)
{
    return m_hp.Pop(x);
}

template<typename T, typename COM>
size_t PriorityQueue<T, COM>::Size()
{
    return m_hp.Size();
}

template<typename T, typename COM>
T& PriorityQueue<T, COM>::Top()
{
    return m_hp.Top();
}

template<typename T, typename COM>
bool PriorityQueue<T, COM>::isEmpty()
{
    return m_hp.isEmpty();
}

