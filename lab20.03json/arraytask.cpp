#include "arraytask.h"

// Сортування бульбашкою за зростанням (ASC)
void ArrayTask::sortAsc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Сортування бульбашкою за спаданням (DESC)
void ArrayTask::sortDesc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ArrayTask::printVector(const vector<int>& vec, const string& name) {
    cout << name << ": [ ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "]\n";
}

void ArrayTask::saveToJson(int S2, int S3, int duplicatesCount, const vector<int>& V1, const vector<int>& V2) {
    json j;
    j["S2"] = S2;
    j["S3"] = S3;
    j["S3_minus_S2"] = S3 - S2;
    j["duplicates_count"] = duplicatesCount;
    j["V1"] = V1;
    j["V2"] = V2;

    ofstream jsonFile("results.json");
    if (jsonFile.is_open()) {
        jsonFile << j.dump(4);
        jsonFile.close();
        cout << "\nДані успішно збережено у results.json\n";
    }
    else {
        cout << "\nПомилка створення JSON файлу!\n";
    }
}

void ArrayTask::run() {
    srand(time(0));

    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    if (size <= 0) {
        cout << "Розмір має бути більшим за нуль!\n";
        return;
    }

    vector<int> V1(size);
    for (int i = 0; i < size; i++) {
        V1[i] = rand() % 20; // Невеликий діапазон для генерації повторів
    }

    printVector(V1, "Початковий масив V1");

    int n;
    cout << "Введіть число n (для поділу на групи): ";
    cin >> n;

    ofstream txtFile("e.txt");
    if (txtFile.is_open()) {
        int groupNum = 1;
        for (int i = 0; i < size; i += n) {
            int sum = 0;
            for (int j = i; j < i + n && j < size; j++) {
                sum += V1[j];
            }
            txtFile << "S" << groupNum << " = " << sum << "\n";
            groupNum++;
        }
        txtFile.close();
        cout << "Суми груп записані у файл e.txt\n\n";
    }

    // Створюємо копію та сортуємо за зростанням
    vector<int> V1_asc = V1;
    sortAsc(V1_asc);

    int S2 = 0;
    for (int i = 0; i < V1_asc.size(); i++) {
        S2 += V1_asc[i];
    }
    cout << "Сума всіх елементів масиву V1 (S2): " << S2 << "\n";

    // Створюємо копію та сортуємо за спаданням
    vector<int> V1_desc = V1;
    sortDesc(V1_desc);

    int sumDesc = 0;
    for (int i = 0; i < V1_desc.size(); i++) {
        sumDesc += V1_desc[i];
    }
    cout << "Сума елементів за спаданням: " << sumDesc << " (має співпадати з S2)\n";

    vector<int> V2;
    vector<int> deletedElements;

    if (V1_asc.size() > 0) {
        V2.push_back(V1_asc[0]);
        for (int i = 1; i < V1_asc.size(); i++) {
            if (V1_asc[i] != V1_asc[i - 1]) {
                V2.push_back(V1_asc[i]);
            }
            else {
                deletedElements.push_back(V1_asc[i]);
            }
        }
    }

    int S3 = 0;
    for (int i = 0; i < V2.size(); i++) {
        S3 += V2[i];
    }
    cout << "Сума унікальних елементів V2 (S3): " << S3 << "\n";
    cout << "Різниця сум (S3 - S2): " << (S3 - S2) << "\n";

    int duplicatesCount = deletedElements.size();
    cout << "Кількість повторюваних елементів: " << duplicatesCount << "\n";

    saveToJson(S2, S3, duplicatesCount, V1_asc, V2);

    printVector(deletedElements, "Видалені елементи |V1 - V2|");
}