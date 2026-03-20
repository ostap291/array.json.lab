#include "arraytask.h"

int main() {
	cout << "Tests are starting!\n";
	ArrayTask task;

	// test 1 ascending sort check
	vector<int> arr1 = { 5, 2, 9, 1, 5, 6 };
	task.sortAsc(arr1);
	vector<int> expected1 = { 1, 2, 5, 5, 6, 9 };
	assert(arr1 == expected1 && "Bubble sort ASC failed!");

	// test 2 descending sort check
	vector<int> arr2 = { 5, 2, 9, 1, 5, 6 };
	task.sortDesc(arr2);
	vector<int> expected2 = { 9, 6, 5, 5, 2, 1 };
	assert(arr2 == expected2 && "Bubble sort DESC failed!");

	cout << "All test are succesfully completed!\n";
}