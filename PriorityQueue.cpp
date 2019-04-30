#include "PriorityQueue.h"

template<typename T, typename com>
PriorityQueue<T, com>::PriorityQueue()
{
}

template<typename T, typename com>
PriorityQueue<T, com>::~PriorityQueue()
{
}

template<typename T, typename com>
void PriorityQueue<T, com>::Push(const T& x)
{
    m_hp.Push(x);
}

template<typename T, typename com>
bool PriorityQueue<T, com>::Pop(T& x)
{
    return m_hp.Pop(x);
}

template<typename T, typename com>
size_t PriorityQueue<T, com>::Size()
{
    return m_hp.Size();
}

template<typename T, typename com>
T& PriorityQueue<T, com>::Top()
{
    return m_hp.Top();
}

template<typename T, typename com>
bool PriorityQueue<T, com>::isEmpty()
{
    return m_hp.isEmpty();
}

