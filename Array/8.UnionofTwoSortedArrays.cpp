#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(int arr1[], int n, int arr2[], int m) {
    int i = 0, j = 0;
    vector<int> result;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
        } 
        else if (arr2[j] < arr1[i]) {
            if (result.empty() || result.back() != arr2[j])
                result.push_back(arr2[j]);
            j++;
        } 
        else { // arr1[i] == arr2[j]
            if (result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements
    while (i < n) {
        if (result.empty() || result.back() != arr1[i])
            result.push_back(arr1[i]);
        i++;
    }
    while (j < m) {
        if (result.empty() || result.back() != arr2[j])
            result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int n = 5, m = 4;

    vector<int> unionArr = findUnion(arr1, n, arr2, m);

    cout << "Union: ";
    for (int num : unionArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
