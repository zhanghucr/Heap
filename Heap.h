#ifndef __HEAP_H__
#define __HEAP_H__

#include <vector>
#include <iostream>

using namespace std;

#define USE_RECURSIVE  /* use recursive algo */

/* 函数类，对操作符()进行重载 */
template<typename T>
struct Less
{
    bool operator()(const T& a, const T& b)
    {
        return a < b;
    }
};

template<typename T>
struct Greater
{
    bool operator()(const T& a, const T& b)
    {
        return a > b;
    }
};

template<typename T, typename COM = Greater<T> >
class Heap
{
public:
    //构造函数
    Heap();
    Heap(T *a, size_t n);
    virtual ~Heap();
    
    //尾插
    void Push(const T& x);
    
    //取堆顶
    bool Pop(T& x);
    
    //求堆里元素的个数
    size_t Size();
    
    //求堆顶的元素
    T& Top();
    
    //判断堆是否为空
    bool isEmpty();

protected:
    //向下调整
    void PercolateDown(int parent);
    
    //向上调整
    void PercolateUp(int child);
    
private:
    vector<T>  m_vec;
    COM        m_com;  /* 比较函数对象 */
};

#endif
