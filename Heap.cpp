#include "Heap.h"

template<typename T, typename COM>
Heap<T, COM>::Heap()
{
}

template<typename T, typename COM>
Heap<T, COM>::Heap(T *a, size_t n):m_vec(a, a + n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)  /* 对(n - 1) / 2个非叶子节点进行过滤 */
    {
        PercolateDown(i);
    }
}

template<typename T, typename COM>
Heap<T, COM>::~Heap()
{
}

template<typename T, typename COM>
void Heap<T, COM>::Push(const T& x)
{
    m_vec.push_back(x);
    PercolateUp(m_vec.size() - 1);
}

template<typename T, typename COM>
bool Heap<T, COM>::Pop(T& x)
{
    if (isEmpty())
    {
        return false;
    }

    x = m_vec[0];
    swap(m_vec[0], m_vec[m_vec.size() - 1]);
    m_vec.pop_back();
    PercolateDown(0);
    return true;
}

template<typename T, typename COM>
size_t Heap<T, COM>::Size()
{
    return m_vec.size();
}

template<typename T, typename COM>
T& Heap<T, COM>::Top()
{
    return m_vec[0];
}

template<typename T, typename COM>
bool Heap<T, COM>::isEmpty()
{
    return m_vec.size() == 0;
}

#ifdef USE_RECURSIVE
template<typename T, typename COM>
void Heap<T, COM>::PercolateDown(int parent)
{
    size_t child = parent * 2 + 1;

    if (child >= m_vec.size())
    {
        return;  /* 递归结束 */
    }
    
    //找左右孩子中值最大的
    if (child + 1 < m_vec.size() && m_com(m_vec[child + 1], m_vec[child]))
    {
        ++child;
    }
    
    //将孩子和父母做比较
    if (m_com(m_vec[child], m_vec[parent]))
    {
        swap(m_vec[child], m_vec[parent]);
        PercolateDown(child);
    }
}

template<typename T, typename COM>
void Heap<T, COM>::PercolateUp(int child)
{
    //Compare com;
    int parent = (child - 1) / 2;

    if (parent < 0)
    {
        return;  /* 递归结束 */
    }
    
    if (m_com(m_vec[child], m_vec[parent]))
    {
        swap(m_vec[child], m_vec[parent]);
        PercolateUp(parent);
    }
}

#else

template<typename T, typename COM>
void Heap<T, COM>::PercolateDown(int parent)
{
    int child = parent * 2 + 1;
    //此处的条件有两个：
    //1.当孩子的值小于/大于父母的值时候这个已经在break处理过了
    //2.当是叶子节点的时候
    while (child < m_vec.size())
    {
        //找左右孩子中值最大的
        if (child + 1 < m_vec.size() && m_com(m_vec[child + 1], m_vec[child]))
        {
            ++child;
        }
        
        //将孩子和父母做比较
        if (m_com(m_vec[child], m_vec[parent]))
        {
            swap(m_vec[child], m_vec[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

template<typename T, typename COM>
void Heap<T, COM>::PercolateUp(int child)
{
    //Compare com;
    int parent = (child - 1) / 2;
    while (parent >= 0)
    {
        if (m_com(m_vec[child], m_vec[parent]))
        {
            swap(m_vec[child], m_vec[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

#endif

