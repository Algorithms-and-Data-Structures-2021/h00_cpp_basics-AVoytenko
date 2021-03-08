#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs && rhs){
        int temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if(num_cols < 1 || num_rows <1){
        return nullptr;
    }
    int **array = new int *[num_rows];
    for(int i = 0; i < num_rows; i++){
        array[i] = new int [num_cols];
        for (int j = 0; j < num_cols; j++){
            array[i][j] = init_value;
        }
    }
    return array;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if(!(arr_2d_source && arr_2d_target)){
        return false;
    }
    if (num_rows < 1 || num_cols < 1){
        return false;
    }
    for ( int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_cols; j++){
            arr_2d_target[i][j] = arr_2d_source[i][j];
        }
    }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for (int i = 0; i < (arr.size()/ 2); i++){
        int temp = arr[i];
        arr[i] = arr[arr.size()-i -1];
        arr[arr.size()-i -1] = temp;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin && arr_end){
        if (arr_begin > arr_end){
            return;
        }
        int temp = *arr_begin;
        *arr_begin = *arr_end;
        *arr_end = temp;
        reverse_1d_array(arr_begin + 1,arr_end -1);
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if(!arr || size <= 0){
        return nullptr;
    }
    int *max_number = &arr[0];
    for (int i = 0; i < size; i ++){
        if( arr[i] > *max_number){
            max_number = &arr[i];
        }
    }
    return max_number;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> result;
    for (auto elem : arr){
        if(elem % 2 != 0){
            result.push_back(elem);
        }
    }
    return result;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> result;
    for(auto a_elem : arr_a){
        for (auto b_elem : arr_b){
            if (a_elem == b_elem){
                result.push_back(a_elem);
            }
        }
    }
    return result;
}