#include <iostream>
#include "Windows.h"
#define SIZE 1000005
using namespace std;

class Stack {
    int size = SIZE;
    public:
        int N_op = 0;
        int* mas;
        int max, counter = 0;
        Stack() { // 3
            mas = new int[size]; // 2
            max = -1; // 1
            N_op += 3;
        }

        ~Stack() {
            delete[] mas; // 2
        }

        void add(int num) { // 4
            mas[++max] = num; 
            
        }

        int* current_elem() { // 2
            
            return mas + max;
        }
        
        int size_stack() { // 2
            
            return max + 1;
        }

        int pop() { // 5
           
            int pop_item = *current_elem(); // 3
            --max; // 1
            return pop_item; // 1
        }

        void print_stack() {
            int temp_size = size_stack();
            Stack temp;
            
            for (size_t i = 0; i < temp_size; ++i) {
                temp.add(pop());
            }

            for (size_t i = 0; i < temp_size; ++i) {
                cout << *(temp.current_elem()) << " ";
                add(temp.pop());
            }
            
        }    


        void sort() {
            int length = size_stack(), temp_elem, temp_length; // 1
            cout << length << endl;
            N_op += 3;
            for (size_t i = 1; i < length; ++i) { // 2
                N_op += 2;
                Stack tempStack;
                N_op += 2;
                for (size_t j = 0; j < i; ++j) {
                    cout << j << " ";
                    N_op += 11;
                    tempStack.add(pop()); // 13
                }
                N_op += 5;
                temp_elem = pop(); // 5
                Stack remain_stack;
                N_op += 2;
                int temp_length = tempStack.size_stack(); // 2
                N_op += 2;
                for (size_t j = 0; j < i; ++j) {  // 2
                    N_op += 2;
                    N_op += 3;
                    if (temp_elem >= *tempStack.current_elem()) { // 3
                        N_op += 9;
                        //++counter;
                        remain_stack.add(tempStack.pop()); // 9
                    } else {
                        cout << "lalala" << " ";
                        N_op += 5;
                        tempStack.add(temp_elem); // 4
                        break; // 1
                    }
                    
                } // 2
                N_op += 2;
                tempStack.add(temp_elem); // 2
                int remain_length = remain_stack.size_stack(); // 3
                //cout << counter << " " << i << " " << remain_length << endl;
                //counter = 0;
                N_op += 2;
                for (size_t j = 0; j < i; ++j) { // 2
                    N_op += 2;
                    N_op += 9;
                    tempStack.add(remain_stack.pop()); // 9
                } // 2
                N_op += 2;
                temp_length = tempStack.size_stack(); // 2
                cout << temp_length << endl;
                N_op += 3;
                for (size_t j = 0; j < i + 1; ++j) {
                    N_op += 3;
                    N_op += 9;
                    add(tempStack.pop()); // 13
                }
            } // 2
        }  
};

int main() {
    int time_start, time_end;
    Stack first;
    for (int i = 0; i < 30; i++) {
        first.add(30 - i);
    }
    //first.sort();
    first.print_stack();
    cout << "\n";
    time_start = GetTickCount();
    first.sort();
    time_end = GetTickCount();
    first.print_stack();
    cout << "\n" << time_end - time_start << endl;
    cout << first.N_op << endl;
    
    
}

// F(n) = 24n^2 + 109n + 3