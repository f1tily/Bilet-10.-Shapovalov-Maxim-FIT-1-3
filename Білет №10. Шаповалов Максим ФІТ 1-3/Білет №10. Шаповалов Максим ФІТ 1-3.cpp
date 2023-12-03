#include <iostream>

using namespace std;

    void sort_row(int row[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (row[j] > row[j + 1]) {
                    int temp = row[j];
                    row[j] = row[j + 1];
                    row[j + 1] = temp;
                }
            }
        }
    }
    int main() {
        setlocale(LC_ALL, "Ukrainian");
        int array[15][2];

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 2; j++) {
                cout << "Введіть елемент [" << i << "][" << j << "]: ";
                cin >> array[i][j];
            }
        }

        for (int i = 0; i < 15; i++) {
            sort_row(array[i], 2);
        }

        int min_sum = array[0][0] + array[1][0];
        int min_row1 = 0;
        int min_row2 = 1;
        for (int i = 1; i < 14; i++) {
            int sum = array[i][0] + array[i + 1][0];
            if (sum < min_sum) {
                min_sum = sum;
                min_row1 = i;
                min_row2 = i + 1;
            }
        }

        cout << "Номер першого рядка: " << min_row1 << endl;
        cout << "Номер другого рядка: " << min_row2 << endl;
        return 0;
    }