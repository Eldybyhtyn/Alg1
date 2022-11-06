#include <iostream>

using namespace std;
void show_mas(int*, int);
int* insert_sort(int* mas, int length) {
    int current_elem;
    for (size_t i = 1; i < length; ++i) {
        current_elem = *(mas + i);
        for (int j = i - 1; j > -1; --j) {
            //show_mas(mas, length);
            if (current_elem < *(mas + j)) {
                *(mas + j + 1) = *(mas + j);
                if (j == 0) *(mas + j) = current_elem;
            } else {
                *(mas + j + 1) = current_elem;
                break;  
            }
        }
    }
    return mas;
}


void show_mas(int* mas, int length) {
    for (size_t i = 0; i < length; ++i) {
        cout << *(mas + i) << " ";
    }
    cout << "\n";
}

void generate_mas(int* mas, size_t length) {
    int random_num;
    for (size_t i = 0; i < length; ++i) {
        random_num = 1 + rand() % 100;
        *(mas + i) = random_num;
        cout << random_num << endl;
    }
}

int main() {
    int mas[10];
    int* ptr;
    ptr = mas;
    //cout << sizeof(ptr) << endl;
    //cout << mas << endl;
    //cout << insert_sort(mas, sizeof(mas)/sizeof(int)) << endl;
    generate_mas(mas, sizeof(mas)/sizeof(int));
    show_mas(mas, sizeof(mas)/sizeof(int));
    ptr = insert_sort(mas, sizeof(mas)/sizeof(int));
    show_mas(ptr, sizeof(mas)/sizeof(int));
}