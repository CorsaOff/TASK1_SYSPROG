#include <iostream>

using namespace std;

int sum_divisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Ru");
    int start, end;
    cout << "Введите границы отрезка (через пробел): ";
    cin >> start >> end;

    cout << "Дружественные числа на отрезке [" << start << ", " << end << "]:" << endl;

    bool found = false;
    for (int a = start; a <= end; ++a) {
        int b = sum_divisors(a);

        if (b > a && b <= end) {
            if (sum_divisors(b) == a) {
                cout << a << " и " << b << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Дружественных чисел не найдено." << endl;
    }

    return 0;
}
