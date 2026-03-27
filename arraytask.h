#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "json.hpp"
#include <cassert>

using namespace std;
using json = nlohmann::json;

class ArrayTask {
public:
    void run();

    // Bubble Sort
    void sortAsc(vector<int>& arr);  // ascending
    void sortDesc(vector<int>& arr); // descending

private:
    void saveToJson(int S2, int S3, int duplicatesCount, const vector<int>& V1, const vector<int>& V2);
    void printVector(const vector<int>& vec, const string& name);

};
