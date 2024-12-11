#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

const int size = 100;
const int sizze = 10;


int MinSum(int arr[], int start, int minPos, int currentSum, int& minSum)
{

    if (start + sizze - 1 < size)
    {
        currentSum = 0;
        for (int i = start; i < start + sizze; ++i)
        {
            currentSum += arr[i];
        }


        if (currentSum < minSum)
        {
            minSum = currentSum;
            minPos = start;
        }


        return MinSum(arr, start + 1, minPos, currentSum, minSum);
    }


    return minPos;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }

    int minSum = INT_MAX;
    int minPos = 0;


    minPos = MinSum(arr, 0, minPos, 0, minSum);

    std::cout << "Начальная позиция последовательности из 10 чисел с минимальной суммой: " << minPos << std::endl;
    std::cout << "Минимальная сумма: " << minSum << std::endl;

    return 0;
}
