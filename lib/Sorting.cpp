#include "Sorting.h"
using namespace std;

void Sort::SelectionSort(Vector<int> &numbers)
{
    int min;
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers.at(min) > numbers.at(j))
            {
                min = j;
            }
        }
        int temp = numbers.at(i);
        numbers.at(i) = numbers.at(min);
        numbers.at(min) = temp;
    }
}

// Vector<int> Sort::m_quickSort(Vector<int> numbers)
// {
//     if (numbers.size() < 2)
//         return numbers;
//     int pivot = numbers.size() / 2;
//     Vector<int> less;
//     Vector<int> greater;
//     for (int i = 0; i < numbers.size(); i++)
//     {
//         if (pivot != i)
//         {
//             if (numbers.at(i) <= numbers.at(pivot))
//                 less.pushBack(numbers.at(i));
//             if (numbers.at(i) > numbers.at(pivot))
//                 greater.pushBack(numbers.at(i));
//         }
//     }
//     Vector<int> result;
//     result = m_quickSort(less);
//     result.Vector::insert(result.size() - 1, numbers.at(pivot));
//     Vector<int> temp = m_quickSort(greater);
//     for (int j = 0; j < temp.size(); j++)
//         result.Vector::insert(result.size() - 1, temp.at(j));
//     return result;
// }

void Sort::QuickSort(Vector<int> &numbers)
{
    if (numbers.size() >= 2)
    {
        int pivot = numbers.size() / 2;
        Vector<int> less;
        Vector<int> greater;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (pivot != i)
            {
                if (numbers.at(i) <= numbers.at(pivot))
                    less.pushBack(numbers.at(i));
                if (numbers.at(i) > numbers.at(pivot))
                    greater.pushBack(numbers.at(i));
            }
        }
        Vector<int> result;
        QuickSort(less);
        result=less;
        result.Vector::insert(result.size(), numbers.at(pivot));
        QuickSort(greater);
        for (int j = 0; j < greater.size(); j++)
            result.Vector::insert(result.size(), greater.at(j));
        numbers = result;
    }
}
