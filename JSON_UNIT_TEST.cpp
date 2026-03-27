#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\OSTAP.ONUFRYK\source\repos\jsonlab\jsonlab\arraytask.cpp" 
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests // Namespace for our test project
{
    TEST_CLASS(ArrayTaskTests)
    {
    public:

        TEST_METHOD(TestSortAsc)
        {
            ArrayTask task;
            vector<int> arr = { 5, 2, 9, 1, 5, 6 };
            task.sortAsc(arr);
            vector<int> expected = { 1, 2, 5, 5, 6, 9 };

            // Check if the array is sorted in ascending order
            Assert::IsTrue(arr == expected);
        }

        TEST_METHOD(TestSortDesc)
        {
            ArrayTask task;
            vector<int> arr = { 5, 2, 9, 1, 5, 6 };
            task.sortDesc(arr);
            vector<int> expected = { 9, 6, 5, 5, 2, 1 };

            // Check if the array is sorted in descending order
            Assert::IsTrue(arr == expected);
        }
    };
}