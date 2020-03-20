#include <iomanip>
#include <fstream>

using namespace std;

template <typename T>
void BubbleSort(vector <T>& vec)
{
    T temp;

    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void BubbleSortAt(vector <T>& vec)
{
    T temp;

    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec.at(j) > vec.at(j + 1)) {
                temp = vec.at(j);
                vec.at(j) = vec.at(j + 1);
                vec.at(j + 1) = temp;
            }
        }
    }
}


template <typename T>
void BubbleSortIterator(vector <T> &vec)
{
    vector<int>::iterator first = vec.begin();
    vector<int>::iterator second;

    T temp;

    for (first; first < vec.end() - 1; first++) {
        for (second = first+1; second < vec.end(); second++) {
            if (*first > *second) {
                temp = *second;
                *second = *first;
                *first = temp;
            }
        }
    }
}

template <typename T>
void VectorOut(vector <T>& vec)
{
    int i = 1;
    for (T x : vec) {
        cout << setw(3) << x << " ";
        if (i++ % 10 == 0)
            cout << endl;
    }
}

template <typename T>
void VectorFill(vector <T> & vec, int SIZE)
{
    srand((unsigned)time(nullptr));
    for (int i = 0; i < SIZE; ++i)
    {
        vec.push_back(rand() % 100);
    }
}

void VectorFill(vector <double>& vec, int SIZE)
{
    int sign;
    srand((unsigned)time(nullptr));
    for (int i = 0; i < SIZE; ++i)
    {
        if (rand() % 2 == 1)
            sign = 1;
        else
            sign = -1;

        vec.push_back(rand() % 100 / 100.0 * sign);
    }
}

template <typename T>
void FillVectorFromFile (vector <T> & vec)
{
    ifstream fout;

    fout.open("../result.txt");

    copy(vec.begin(),vec.end());

    fout.close();

    cout << "End." << endl;

}

