#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class clMatrix
{
private:
    T* mat;
    T* matCopy;
    int len{ 0 };
    T maxElement{ 0 };
    T minElement{ 0 };
    T positiveSum{ 0 };
    int negativeCount{ 0 };
    double meanNum{ 0 };
    int aCount{ 0 };
    int bCount{ 0 };
    int rangeCount{ 0 };
public:
    clMatrix();
    ~clMatrix();
    void output();
    T findMax();
    T findMin();
    int findMin(int, int);
    void copyMatrix();
    void swapItem(int, int);
    void extrSortUp();
    T sumPosNum();
    int countNegNum();
    int isOdd();
    double mean();
    void outputCopyMat();
    int range();
    double sum();
};

template<class T>
clMatrix<T>::clMatrix()
{
    cout << "Введите длину массива: ";
    cin >> len;
    mat = new T[len];
    for (int i = 0; i < len; i++)
    {
        cout << "Введите " << i << " элемент массива: ";
        cin >> mat[i];
    }
}

template<class T>
clMatrix<T>::~clMatrix()
{
    delete mat;
}

template<class T>
void clMatrix<T>::output()
{
    cout << "Максимальный элемент: " << maxElement << endl;
    cout << "Минимальный элемент: " << minElement << endl;
    cout << "Скопированный массив: ";
    for (int i = 0; i < len; i++)
    {
        cout << matCopy[i] << " ";
    }
    cout << endl;
    cout << "Отсортированный массив: ";
    for (int i = 0; i < len; i++)
    {
        cout << mat[i] << " ";
    }
    cout << endl;
    cout << "Сумма положительных чисел: " << positiveSum << endl;
    cout << "Количество отрицательных чисел: " << negativeCount << endl;
    cout << "Среднее значение: " << meanNum << endl;
    cout << "Количство чисел в диапозоне " << matCopy[aCount] << " до " << matCopy[bCount] << ": " << rangeCount << endl;
}

template<class T>
T clMatrix<T>::findMax()
{
    maxElement = mat[0];
    for (int i = 0; i < len; i++)
    {
        if (maxElement < mat[i])
            maxElement = mat[i];
    }
    return maxElement;
}

template<class T>
T clMatrix<T>::findMin()
{
    minElement = mat[0];
    for (int i = 0; i < len; i++)
    {
        if (minElement > mat[i])
            minElement = mat[i];
    }
    return minElement;
}

template<class T>
int clMatrix<T>::findMin(int iLow, int iHigh)
{
    int iMin = iLow;
    for (int i = iLow; i <= iHigh; i++)
        iMin = (mat[i] < mat[iMin]) ? i : iMin;
    return iMin;
}

template<class T>
void clMatrix<T>::copyMatrix()
{
    matCopy = new T[len];
    for (int i = 0; i < len; i++)
    {
        matCopy[i] = mat[i];
    }
}

template<class T>
void clMatrix<T>::swapItem(int a, int b)
{
    T temp;
    temp = mat[a];
    mat[a] = mat[b];
    mat[b] = temp;
}

template<class T>
void clMatrix<T>::extrSortUp()
{
    for (int i = len - 1; i > 0; i--)
        swapItem(i, findMin(0, i));
}

template<class T>
T clMatrix<T>::sumPosNum()
{
    for (int i = 0; i < len; i++)
        if (mat[i] > 0)
            positiveSum += mat[i];
    return positiveSum;
}

template<class T>
int clMatrix<T>::countNegNum()
{
    for (int i = 0; i < len; i++)
        if (mat[i] < 0)
            negativeCount++;
    return negativeCount;
}

template<class T>
int clMatrix<T>::isOdd()
{
    int oddCount{ 0 };
    for (int i = 0; i < len; i++)
        if (((mat[i] % 2) == 0) && (mat[i] != 0))
            oddCount++;
    return oddCount;
}

template<class T>
double clMatrix<T>::mean()
{
    for (int i = 0; i < len; i++)
        meanNum += mat[i];
    meanNum /= len;
    return meanNum;
}

template<class T>
void clMatrix<T>::outputCopyMat()
{
    cout << "Изначальный массив: ";
    for (int i = 0; i < len; i++)
    {
        cout << matCopy[i] << " ";
    }
    cout << endl;
}

template<class T>
int clMatrix<T>::range()
{
    cout << "Введите первое значение: ";
    T a;
    cin >> a;

    cout << "Введите второе значение: ";
    T b;
    cin >> b;

    for (int i = 0; i < len; i++)
    {
        if (fabs(a - matCopy[i]) < 0.001)
        {
            aCount = i;
            goto continuation;
        }
    }
continuation:
    for (int i = aCount; i < len; i++)
    {
        if (fabs(b - matCopy[i]) < 0.001)
            bCount = i;
    }
    for (int i = aCount; i <= bCount; i++)
        rangeCount++;
    return rangeCount;
}

template<class T>
double clMatrix<T>::sum()
{
    T sum{ 0 };
    for (int i = 0; i < len; i++)
    {
        sum += matCopy[i];
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    cout << "Массив целых чисел" << endl;
    clMatrix<int>* intVec = new clMatrix<int>();
    intVec->findMax();
    intVec->findMin();
    intVec->copyMatrix();
    intVec->extrSortUp();
    intVec->sumPosNum();
    intVec->countNegNum();
    cout << "Количество чётных чисел: " << intVec->isOdd() << endl;
    intVec->mean();
    intVec->outputCopyMat();
    intVec->range();
    intVec->output();
    
    cout << endl;

    cout << "Массив вещественных чисел" << endl;
    clMatrix<double>* doubleVec = new clMatrix<double>();
    doubleVec->findMax();
    doubleVec->findMin();
    doubleVec->copyMatrix();
    doubleVec->extrSortUp();
    doubleVec->sumPosNum();
    doubleVec->countNegNum();
    cout << "Сумма всех элементов массива: " << doubleVec->sum() << endl;
    doubleVec->mean();
    doubleVec->outputCopyMat();
    doubleVec->range();
    doubleVec->output();
}