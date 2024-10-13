#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.1(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(SumElementsTest)
    {
    public:

        int SumElements(int* r, const int size, int i)
        {
            if (i < size)
            {
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

        TEST_METHOD(TestSumElements)
        {
            // Тестовий масив
            int arr1[] = { 1, 2, 3, 4, 5, 6, -1, -2, 8 };
            int size1 = sizeof(arr1) / sizeof(arr1[0]);
            Assert::AreEqual(17, SumElements(arr1, size1, 0)); // 1 + 2 + 3 + 5 + 6 = 17

            int arr2[] = { -1, -2, 0, 4, 8 };
            int size2 = sizeof(arr2) / sizeof(arr2[0]);
            Assert::AreEqual(0, SumElements(arr2, size2, 0)); // Немає додатніх чисел, не кратних 4

            int arr3[] = { 4, 8, 12 };
            int size3 = sizeof(arr3) / sizeof(arr3[0]);
            Assert::AreEqual(0, SumElements(arr3, size3, 0)); // Немає додатніх чисел, не кратних 4

            int arr4[] = { 5, 9, 10, 15 };
            int size4 = sizeof(arr4) / sizeof(arr4[0]);
            Assert::AreEqual(39, SumElements(arr4, size4, 0)); // 5 + 9 + 15 = 29
        }
    };
}
