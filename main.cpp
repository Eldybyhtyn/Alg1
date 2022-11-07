#include <iostream>
#define SIZE 10*10
using namespace std;

class Stack {
    int size = SIZE;
    int* mas;
    int max;
    public:
        Stack() {
            mas = new int[size];
            max = -1;
        }

        ~Stack() {
            delete[] mas;
        }

        void add(int num) {
            mas[++max] = num;
        }

        int* current_elem() {
            return mas + max;
        }
        
        int size_stack() {
            return max + 1;
        }

        int pop() {
            int pop_item = *current_elem();
            --max;
            //cout << pop_item << endl;
            return pop_item;
        }

        void print_stack() {
            int temp_size = size_stack();
            Stack temp;
            cout << endl;
            for (size_t i = 0; i < temp_size; ++i) {
                
                temp.add(pop());
            }
            //temp.print_debug();
            for (size_t i = 0; i < temp_size; ++i) {
                cout << *(temp.current_elem()) << " ";
                add(temp.pop());
            }
        }

        Stack reverse_stack() {
            int length = size_stack();
            Stack tempStack;
            for (size_t i = 0; i < length; ++i) tempStack.add(pop());
            return tempStack;
        }

        

        void sort() {
            int length = size_stack(), temp_elem, temp_length;
            Stack tempStack;
            //tempStack.add(pop());
            for (size_t i = 0; i < length; ++i) {
                temp_elem = *current_elem();
                for (size_t j = 0; j < i + 1; ++j) tempStack.add(pop());
                temp_length = tempStack.size_stack();
                for (size_t j = 0; j < temp_length; ++j) {
                    
                }
                //print_stack();
                
                for (size_t j = 0; j < i + 1; ++j) add(tempStack.pop());
                //print_stack();
                //for (int j = i; j > -1; --j) {

                //}
            }
        }

        
};

int main() {
    Stack first;
    first.add(5);
    first.add(4);
    first.add(57);
    first.add(328);
    first.add(111);
    first.print_stack();
    first.sort();
    
}