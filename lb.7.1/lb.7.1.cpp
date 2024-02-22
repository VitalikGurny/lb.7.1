#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int Low = -41;
    int High = 23;
    int rowCount = 7;
    int colCount = 9;

    int** T = new int* [rowCount];
    for (int i = 0; i < rowCount; ++i)
        T[i] = new int[colCount];

    Create(T, rowCount, colCount, Low, High);

    cout << "Original Matrix T:" << endl;
    Print(T, rowCount, colCount);

    Sort(T, rowCount, colCount);

    cout << "Sorted Matrix T:" << endl;
    Print(T, rowCount, colCount);

    int sum = 0;
    int count = 0;
    Calc(T, rowCount, colCount, sum, count);

    cout << "Sum of elements satisfying the criterion: " << sum << endl;
    cout << "Count of elements satisfying the criterion: " << count << endl;

    cout << "Modified Matrix T:" << endl;
    Print(T, rowCount, colCount);

    for (int i = 0; i < rowCount; ++i)
        delete[] T[i];
    delete[] T;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; ++i)
        for (int j = 0; j < colCount; ++j)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < rowCount - 1; ++i0)
        for (int i1 = 0; i1 < rowCount - i0 - 1; ++i1)
            if ((a[i1][0] > a[i1 + 1][0])
                || (a[i1][0] == a[i1 + 1][0] && a[i1][1] > a[i1 + 1][1])
                || (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2]))
                Change(a, i1, i1 + 1, colCount);
}

void Change(int** a, const int row1, const int row2, const int colCount) {
    for (int j = 0; j < colCount; ++j) {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; ++i)
        for (int j = 0; j < colCount; ++j)
            if (a[i][j] >= 0 && (i % 2 != 0 || j % 2 != 0)) {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}
