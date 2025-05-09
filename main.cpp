#include "lib/Searching.h"
#include "lib/Sorting.h"
#include "lib/Vector.h"

using namespace std;

void print(Vector<int> vals)
{
    for (int i = 0; i < vals.size(); i++)
    {
        cout << vals.at(i) << " ";
    }
    cout << endl;
}

void testFunc(int a, int b, int c, int d, int e, int f)
{
    Vector<int> temp;
    int index;
    Sort sorter;
    Search searcher;
    temp.pushBack(a);
    temp.pushBack(b);
    temp.pushBack(c);
    temp.pushBack(d);
    temp.pushBack(e);
    cout << "Vector is : " << endl;
    print(temp);
    cout << "Selection sort is : " << endl;
    print(temp);
    sorter.SelectionSort(temp);
    print(temp);
    temp.clear();
    temp.pushBack(a);
    temp.pushBack(b);
    temp.pushBack(c);
    temp.pushBack(d);
    temp.pushBack(e);
    cout << "Quick sort is : " << endl;
    print(temp);
    sorter.QuickSort(temp);
    print(temp);
    cout << "Searching for " << f << " :\n";
    print(temp);
    index = searcher.BinarySearch(temp, f);
    if (index == -1)
    {
        cout << "Doesn't exist!\n";
    }
    else
    {
        cout << "Exists at: " << index + 1 << endl;
    }
}

int main()
{
    cout << "starting\n";
    testFunc(12, 23, 34, 45, 50, 33);
    testFunc(50, 45, 34, 23, 12, 23);
    testFunc(34, 45, 12, 78, 67, 34);
    testFunc(12, 12, 98, 45, 12, 12);
    return 0;
}
