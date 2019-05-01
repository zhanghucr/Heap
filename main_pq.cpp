#include <cstdlib>
#include "Heap.cpp"
#include "PriorityQueue.cpp"

/* CTRL+D end input */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "CMD <type>" << endl;;
        return -1;
    }

    int type = atoi(argv[1]);
    int data = 0;
    
    if (type == 0)
    {
        cout << "min heap, input data" << endl;
        PriorityQueue<int, Less<int> > pq_less;
        while (cin >> data)
        {
            pq_less.Push(data);
        }

        while (pq_less.Pop(data))
        {
            cout << data << " ";
        }
    }
    else
    {
        cout << "max heap, input data" << endl;
        PriorityQueue<int, Greater<int> > pq_greater;
        while (cin >> data)
        {
            pq_greater.Push(data);
        }

        while (pq_greater.Pop(data))
        {
            cout << data << " ";
        }
    }

    cout << endl;
    return 0;
}

