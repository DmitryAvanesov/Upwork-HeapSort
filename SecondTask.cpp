#include <iostream>
using namespace std;

bool isMaxheap(int atree[], int size)
{
    // start with first root element
    for (int i = 0; i <= (size - 2) / 2; i++)
    {
        // left child is i * 2 + 1
        // if left child is greater than element above it, the tree is not max heap
        int leftElementIndex = i * 2 + 1;
        if (atree[leftElementIndex] > atree[i])
            return false;
        // right child is i * 2 + 2
        // the tree may not include right child. We have to check it using this condition: rightElementIndex < size
        // if right child is greater than element above it, the tree is not max heap
        int rightElementIndex = i * 2 + 2;
        if (atree[rightElementIndex] > atree[i] && rightElementIndex < size)
            return false;
    }
    return true;
}

int main()
{
    // example of usage
    int n = 10;
    int array[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    cout << "\n"
         << isMaxheap(array, n);
    return 0;
}
