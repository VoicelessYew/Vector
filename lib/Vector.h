#ifndef _VECTOR_H_
#define _VECTOR_H_
#define DEFAULT_SIZE 5 // 5 < 0.7 * 8 = 5.6 i.e. largest int smaller than 0.7 times default capacity
#include <iostream>
using namespace std;

template <class T>
class Vector
{
private:
    int sizeOfVec = 0;
    int cap = 8;
    T *head;
    void m_incsize(int newSize)
    {
        if (newSize > 0.7 * cap)
        {
            while (newSize >= 0.7 * cap)
                cap = cap * 2;
            T *temp = new T[cap];
            for (int i = 0; i < sizeOfVec; i++)
            {
                temp[i] = head[i];
            }
            delete[] head;
            head = temp;
        }
    }
    void m_decsize(int newSize)
    {
        if (newSize < 0.7 * cap / 2)
        {
            while (newSize < 0.7 * cap / 2)
                cap = cap / 2;
            T *temp = new T[cap];
            for (int i = 0; i < cap; i++)
            {
                temp[i] = head[i];
            }
            delete[] head;
            head = temp;
        }
    }

public:
    Vector()
    {
        head = new T[cap];
        sizeOfVec = 0;
    }
    // ~Vector()
    // {
    //     delete[] head;
    // }
    void erase(int index)
    {
        if (index >= sizeOfVec)
        {
            cout << "Error! Index too big!\n";
        }
        else
        {
            T *temp = new T[cap];
            for (int i = index; i < sizeOfVec - 1; i++)
            {
                temp[i] = head[i + 1];
            }
            for (int j = 0; j < index; j++)
            {
                temp[j] = head[j];
            }
            delete[] head;
            head = temp;
            sizeOfVec = index + 1;
        }
    }
    void pushBack(T value)
    {
        m_incsize(sizeOfVec + 1);
        head[sizeOfVec++] = value;
    }
    void popBack()
    {
        if (sizeOfVec == 0)
        {
            cout << "Error! Empty Vector!\n";
        }
        else
        {
            sizeOfVec--;
        }
    }
    void insert(int index, T value)
    {
        insert(index, 1, value);
    }
    void insert(int index, int count, T value)
    {
        m_incsize(sizeOfVec + count);
        T *temp = new T[sizeOfVec];
        for (int j = 0; j < sizeOfVec; j++)
        {
            temp[j] = head[j];
        }
        for (int i = index; i < sizeOfVec; i++)
        {
            head[i + count] = temp[i];
        }
        for (int j = 0; j < count; j++)
        {
            head[index + j] = value;
        }
        delete[] temp;
        sizeOfVec = sizeOfVec + count;
    }
    void resize(int newSize)
    {
        resize(newSize, T());
    }
    void resize(int newSize, T value)
    {
        m_incsize(newSize);
        m_decsize(newSize);
        if (newSize > sizeOfVec)
        {
            for (int i = sizeOfVec; i < newSize; i++)
            {
                head[i - 1] = value;
            }
        }
        sizeOfVec = newSize;
    }
    T &at(int index)
    {
        if (index >= sizeOfVec)
        {
            cout << "Error! Index out of bounds!\n";
            return head[0];
        }
        else
        {
            return head[index];
        }
    }
    T &operator[](int index)
    {
        return head[index];
    }
    T &front()
    {
        if (sizeOfVec == 0)
        {
            cout << "Error! Empty array!\n";
            return head[0];
        }
        else
        {
            return head[0];
        }
    }
    T &back()
    {
        if (sizeOfVec == 0)
        {
            cout << "Error! Empty array!\n";
            return head[0];
        }
        else
        {
            return head[sizeOfVec - 1];
        }
    }
    int size()
    {
        return sizeOfVec;
    }
    int capacity()
    {
        return cap;
    }
    void clear()
    {
        sizeOfVec = 0;
        m_decsize(DEFAULT_SIZE);
    }
};

#endif // _VECTOR_H_