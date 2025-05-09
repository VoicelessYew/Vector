#include "Searching.h"

int Search::BinarySearch(Vector<int> values, int target)
{
    // return BinarySearch_Recursive(values, target, 0, values.size() - 1);
    return BinarySearch_Iterative(values, target);
}

int Search::BinarySearch_Recursive(Vector<int> values, int target, int start, int end)
{
    int low = start;
    int high = end;
    int mid = low + (high - low) / 2;
    if (values.at(mid) == target)
    {
        return mid;
    }
    else if (low != high)
    {
        if (target > values.at(mid))
        {
            return BinarySearch_Recursive(values, target, mid + 1, high);
        }
        else
        {
            return BinarySearch_Recursive(values, target, low, mid - 1);
        }
    }
    return -1;
}

int Search::BinarySearch_Iterative(Vector<int> values, int target)
{
    int low = 0;
    int high = values.size() - 1;
    int mid = low + (high - low) / 2;
    while (values.at(mid) != target)
    {
        if (low == high)
            return -1;
        if (target > values.at(mid))
        {
            low = mid + 1;
            mid = low + (high - low) / 2;
        }
        else
        {
            high = mid - 1;
            mid = low + (high - low) / 2;
        }
    }
    return mid;
}