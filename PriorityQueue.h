#ifndef __PRIORITY_QUE_H__
#define __PRIORITY_QUE_H__

#include "Heap.h"

using namespace std;

template<typename T, typename COM = Greater<T> >
class PriorityQueue
{
public:
    PriorityQueue();

    virtual ~PriorityQueue();
    
    void Push(const T& x);
    
    bool Pop(T& x);
    
    size_t Size();
    
    T& Top();
    
    bool isEmpty();
   
private:
    Heap<T, COM>  m_hp;
};

#endif  /* __PRIORITY_QUE_H__ */


