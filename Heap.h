#ifndef __HEAP_H__
#define __HEAP_H__

#include <vector>
#include <iostream>

using namespace std;

#define USE_RECURSIVE  /* use recursive algo */

/* �����࣬�Բ�����()�������� */
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
    //���캯��
    Heap();
    Heap(T *a, size_t n);
    virtual ~Heap();
    
    //β��
    void Push(const T& x);
    
    //ȡ�Ѷ�
    bool Pop(T& x);
    
    //�����Ԫ�صĸ���
    size_t Size();
    
    //��Ѷ���Ԫ��
    T& Top();
    
    //�ж϶��Ƿ�Ϊ��
    bool isEmpty();

protected:
    //���µ���
    void PercolateDown(int parent);
    
    //���ϵ���
    void PercolateUp(int child);
    
private:
    vector<T>  m_vec;
    COM        m_com;  /* �ȽϺ������� */
};

#endif
