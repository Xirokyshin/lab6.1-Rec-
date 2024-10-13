#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* r, const int size, const int Low, const int High, int i)
{
    r[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(r, size, Low, High, i + 1);
}

void Print(int* r, const int size, int i)
{
    cout << setw(4) << r[i];
    if (i < size - 1)
        Print(r, size, i + 1);
    else
        cout << endl;
}

int CountElements(int* r, const int size, int i, int& count_element)
{
    if (i < size)
    {
        // критерій: додатні числа, які не є кратними 4
        if (r[i] > 0 && r[i] % 4 != 0)
        {
            count_element++;
        }
        return CountElements(r, size, i + 1, count_element);
    }
    return count_element;
}

int SumElements(int* r, const int size, int i)
{
    if (i < size)
    {
        // критерій: додатні числа, які не є кратними 4
        if (r[i] > 0 && r[i] % 4 != 0)
        {
            return r[i] + SumElements(r, size, i + 1);
        }
        else
        {
            return SumElements(r, size, i + 1);
        }
    }
    return 0;
}

void ReplaceElements(int* r, const int size, int i)
{
    if (i < size)
    {
        // критерій: додатні числа, які не є кратними 4
        if (r[i] > 0 && r[i] % 4 != 0)
        {
            r[i] = 0;
        }
        ReplaceElements(r, size, i + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 23; // масив із 23 елементів
    int r[n];
    int Low = -19;
    int High = 25;
    int count_element = 0;

    Create(r, n, Low, High, 0);

    cout << "Start masiv:" << endl;
    Print(r, n, 0);

    int sum = SumElements(r, n, 0);
    cout << "Suma elementiv (dodatni, ne kratni 4): " << sum << endl;

    CountElements(r, n, 0, count_element);
    cout << "kilkistb elementiv (dodatni, ne kratni 4): " << count_element << endl;

    ReplaceElements(r, n, 0);

    cout << "Masiv pislya zaminu elementiv na 0 (dodanti ne kratni 4):" << endl;
    Print(r, n, 0);

    return 0;
}
