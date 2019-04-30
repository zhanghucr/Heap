#include "Heap.cpp"
#include "PriorityQueue.cpp"

int main(int argc, char *argv[])
{
    int data;
    int buff[] = {10, 16, 18, 12, 11, 13, 15, 17, 14, 19, 9};
    Heap<int, Less<int> > hp1(buff, sizeof(buff) / sizeof(int));  /* > >·Ö¿ª·ÀÖ¹±àÒëÆ÷ÓëÓÒÒÆ²Ù×÷·û»ìÏı */
    hp1.Push(20);
    while (hp1.Pop(data))
    {
        cout << data << " ";
    }
    cout << endl << "-----------------------------------" << endl;

    PriorityQueue<int, Greater<int> > hp2;
    hp2.Push(8);
    hp2.Push(10);
    hp2.Push(3);
    hp2.Push(8);
    hp2.Push(23);
    hp2.Push(16);
    hp2.Push(20);
    hp2.Push(19);
    hp2.Push(7);
    hp2.Push(14);
    while (hp2.Pop(data))
    {
        cout << data << " ";
    }
    cout << endl << "-----------------------------------" << endl;
    return 0;
}

