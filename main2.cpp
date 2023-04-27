#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

class Array {
    private:
        int a;
        int b;
        int k;
        int maxElement = numeric_limits<int>::min();
        int length;
        int *massive;
        int *copyMassive1;
        int *copyMassive2;
        vector<int> indexes1;
        vector<int> indexes2;
    public:
        Array();
        void Small();
        int MaxElement();
        void Stepen();
        void Bigger();
        void Out();
};

Array::Array() {
    cout << "������� 1" << endl;
    cout << endl;

    cout << "������� ������ �������" << endl;
    cin >> length;
    cout << "������� �������� �������" << endl;
    massive = new int[length];
    copyMassive1 = new int[length];
    copyMassive2 = new int[length];

    for(int i=0; i<length; i++) {
        cin >> massive[i];
    }
    for(int i=0; i<length; i++) {
        copyMassive1[i] = massive[i];
        copyMassive2[i] = massive[i];
    }
}

int Array::MaxElement() {

    if (a > b) {
        int t = a;
        a = b;
        b = t;
    }

    int maxElement = massive[0];

    for (int i = 0; i < length; i++) {
        if (massive[i] >= a && massive[i] <= b && massive[i] > maxElement) {
            maxElement = massive[i];
        }
    }
    for (int i = 0; i < length; i++) {
        if (massive[i] == maxElement) {
            indexes1.push_back(i);
        }
    }
    return maxElement;
}

void Array::Stepen() {
    for (int i = 0; i < length; i++) {
        copyMassive1[i] = pow(copyMassive1[i], k);
    }
}

void Array::Small() {
    for (int i = 1; i < (length - 1); i++) {
        if (copyMassive2[i] < 0) {
            copyMassive2[i] += copyMassive2[0];
        }
    }
}

void Array::Bigger() {
    for (int i = 0; i < length; i++) {
        if (massive[i] > k) {
            indexes2.push_back(i);
        }
    }
}

void Array::Out() {

    cout << endl;
    cout << "������" << endl;

    for(int i=0; i<length; i++) {
        cout << copyMassive2[i] << " ";
    }
    cout << endl;

    // ������ a, b
    cout << endl;
    cout  << "a =  ";  cin >> a;
    cout  << "b = ";  cin >> b;
    cout << endl;

    // ������� ������������ ������� � �������
    cout << "������������ �������: " << MaxElement() << endl;
    cout << "������� ������������ ���������: ";
    for (int element : indexes1) {
        cout << element << " ";
    }
    cout << endl;

    cout << "������� 2" << endl;
    cout << endl << "������� k = ";  cin >> k;

    // �������� � ������� k �������� ������� � ������� �� � �������
    Stepen();
    cout << "������ 2 �������" << endl;
    for(int i=0; i<length; i++) {
        cout << copyMassive1[i] << " ";
    }
    cout << endl;
    cout << endl;

    // � ������������� ������
    cout << "������� 3" << endl;
    cout << endl;
    Small();
    cout << "������ 3 �������" << endl;
    for(int i=0; i<length; i++) {
        cout << copyMassive2[i] << " ";
    }
    cout << endl;
    cout << endl;

    // ������ k
    cout << "������� 4" << endl;
    cout << endl;
    Bigger();
    cout << "������� ���������, ������� k: ";
    for (int element : indexes2) {
        cout << element << " ";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Array *X = new Array();
    X->Out();
    return 0;
}
