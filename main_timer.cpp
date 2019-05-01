#include <cstdlib>
#include <unistd.h>
#include "Heap.cpp"
#include "HeapTimer.cpp"

void timeout_cb(void *cb)
{
    int arg = *(int *)cb;
    cout << "timeout " << arg << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "CMD <type> <delay> <arg>" << endl;;
        return -1;
    }
    
    int type = atoi(argv[1]);
    int delay = atoi(argv[2]);
    int arg = atoi(argv[3]);
    HeapTimer hpTimer;
    hpTimer.StartTimer(type, delay, timeout_cb, &arg);
    while (1)
    {
        hpTimer.Tick();
        sleep(1);
    }

    return 0;
}


