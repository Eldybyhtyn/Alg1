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
            
            for (size_t i = 0; i < temp_size; ++i) {
                
                temp.add(pop());
            }
            //temp.print_debug();
            for (size_t i = 0; i < temp_size; ++i) {
                cout << *(temp.current_elem()) << endl;
                add(temp.pop());
            }
        }

        void print_debug() {
            for (size_t i = 0; i < 5; ++i) {
                cout << "Debug: " << mas[i] << "  ";
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
    //first.print_debug();
    
}