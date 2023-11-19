#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "nglRandom.h"
#include "nglColors.h"
#include "sortingList.h"

#define MAX_COUNT_ARRAY 100000
#define COUNT_TESTS 15

#define CUR_SORT 3
#define COUNT_SORT 8

#define BUBBLE_SORT     0
#define SELECT_SORT     1
#define INSERT_SORT     2
#define MERGE_SORT      3
#define QUICK_SORT      4
#define HEAP_SORT       5
#define TIM_SORT        6
#define INTRO_SORT      7
#define SHELL_SORT      8

using namespace std;

int main(){
    double bubbleSortTime{};
    double selectSortTime{};
    //создаем файл с результатами
    ofstream fout("outpur.txt");
    for (int i=CUR_SORT; i < COUNT_SORT; runSortingTest(fout, i++));
    fout.close();
}

void runSortingTest(ofstream &fout, int action){
    double middleTime{};
    string nameSorting{};
    clock_t t0{}, t1{};
    setTextColor(action);
    //количество прогонов с одним массивом
    for (int curTest=0; curTest < COUNT_TESTS; curTest++){
        //создаем массив сортируем случайным образом
        int n = MAX_COUNT_ARRAY;
        int arr[n];

        for (int i=0; i < n; arr[i++] = nglRandom(0,100));
        t0 = clock();
        switch(action){
            case(BUBBLE_SORT): nameSorting = {"Bubble sorting"}; bubbleSort(arr, n); t1 = clock(); break;
            case(SELECT_SORT): nameSorting = {"Selection sorting"}; selectionSort(arr, n); t1 = clock(); break;
            case(INSERT_SORT): nameSorting = {"Insertion sorting"}; insertionSort(arr, n); t1 = clock(); break;
            case(MERGE_SORT): nameSorting = {"Merge sorting"}; mergeSort(arr, 0, n-1); t1 = clock(); break;
            case(QUICK_SORT): nameSorting = {"Quick sorting"}; quickSort(arr, 0, n-1); t1 = clock(); break;
            case(HEAP_SORT): nameSorting = {"Heapsort"}; heapSort(arr, n); t1 = clock(); break;
            case(TIM_SORT): nameSorting = {"Timsorting"}; timSort(arr, n); t1 = clock(); break;
            case(INTRO_SORT): nameSorting = {"Introsorting"}; introSort(arr, n); t1 = clock(); break;
            //case(SHELL_SORT): nameSorting = {"Heapsort"}; heapSort(arr, n); t1 = clock(); break;
        }


        //if (action == INTRO_SORT) for(int i=0; i < n; cout << arr[i++] << ' '); // для проверки
        middleTime += double(t1 - t0) / CLOCKS_PER_SEC;

        cout << curTest + 1 << '\t' << nameSorting << '\t' << double(t1 - t0) / CLOCKS_PER_SEC << " sec" << endl;
        fout << curTest + 1 << '\t' << nameSorting << '\t' << double(t1 - t0) / CLOCKS_PER_SEC << " sec" << endl;

    }
    cout << '\t' << "Middle time: \t" << setprecision(3) << middleTime / COUNT_TESTS << " sec" << endl;
    fout << '\t' << "Middle time: \t" << setprecision(3) << middleTime / COUNT_TESTS << " sec" << endl;
    cout << '\t' << "Summary time: \t" << setprecision(3) << middleTime << " sec" << endl;
    fout << '\t' << "Summary time: \t" << setprecision(3) << middleTime << " sec" << endl;

    cout << "__________________________________________________________ " << endl;
    fout << "__________________________________________________________ " << endl;

}

