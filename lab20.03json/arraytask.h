#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class ArrayTask {
public:
    void run();

private:
    void saveToJson(int S2, int S3, int duplicatesCount, const vector<int>& V1, const vector<int>& V2);
    void printVector(const vector<int>& vec, const string& name);

    // Власні функції сортування (Bubble Sort)
    void sortAsc(vector<int>& arr);  // за зростанням
    void sortDesc(vector<int>& arr); // за спаданням
};