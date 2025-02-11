#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Vector
{
public:
    Vector(int size = 10) :mcur(0), mcap(size)
    {
        marr = new int[mcap]();
    }
    ~Vector()
    {
        delete[]marr;
        marr = nullptr;
    }

public:
    void push_back(int val)
    {
        if (mcur == mcap) expand(2 * mcap);
        marr[mcur++] = val;
    }
    void pop_back()
    {
        if (mcur == 0) return;
        mcur--;
    }
    void insert(int pos, int val)
    {
        if (pos < 0 || pos > mcur)
        {
            return;
        }
        if (mcur == mcap) expand(2 * mcap);
        for (int i = mcur - 1; i >= pos; i--)
        {
            marr[i + 1] = marr[i];
        }
        marr[pos] = val;
        mcur++;
    }
    //按位置删除
    void erase(int pos)
    {
        if (pos < 0 || pos >= mcur) return;
        for (int i = pos + 1; i < mcur; i++)
        {
            marr[i - 1] = marr[i];
        }
        mcur--;
    }
    int find(int val)
    {
        for (int i = 0; i < mcur; i++)
        {
            if (marr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    void show() const
    {
        for (int i = 0; i < mcur; i++)
        {
            cout << marr[i] << " ";
        }
        cout << endl;
    }
private:
    //内部数组扩容
    void expand(int size)
    {
        int* tmp = new int[size];
        memcpy(tmp, marr, sizeof(int) * mcap);
        delete[] marr;
        marr = tmp;
        mcap = size;
    }

private:
    int* marr; //指向可扩容的数组内存
    int mcap;//数组容量
    int mcur;//数组的当前有效个数
};
int main()
{
    Vector arr;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 100);
    }
    arr.show();

    arr.pop_back();
    arr.show();

    arr.insert(0, 100);
    arr.show();
    
    int pos = arr.find(100);
    if (pos != -1)
    {
        arr.erase(pos);
        arr.show();
    }
}

