#include "Vector.h"
using namespace std;

class Search
{
private:
    int BinarySearch_Recursive(Vector<int> values, int target, int start, int end);
    int BinarySearch_Iterative(Vector<int> values, int target);

public:
    int BinarySearch(Vector<int> values, int target);
};