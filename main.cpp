#include <iostream>
#define SIZE 10*10
using namespace std;

class Stack {
    int size = SIZE;
    public: int* mas;
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
                cout << *(temp.current_elem()) << " ";
                add(temp.pop());
            }
            
        }    

        void sort() {
            int length = size_stack(), temp_elem, temp_length;
            
            //tempStack.add(pop());
            for (size_t i = 0; i < length; ++i) {
                if (i == 0) continue;
                Stack tempStack;    
                for (size_t j = 0; j < i; ++j) tempStack.add(pop());
                temp_elem = pop();
                //cout << temp_elem << endl;
                //cout << temp_elem << endl;
                
                
                Stack remain_stack;
                int temp_length = tempStack.size_stack();
                for (size_t j = 0; j < temp_length; ++j) {
                    
                    //cout << *tempStack.current_elem() << " - elem\n";
                    if (temp_elem >= *tempStack.current_elem()) {
                        remain_stack.add(tempStack.pop());
                        //cout << temp_elem << endl;
                    } else {
                        tempStack.add(temp_elem);
                        break;
                    }
                    if (j == temp_length - 1) {
                        tempStack.add(temp_elem);
                        break;
                    }
                }
                //remain_stack.print_stack();
                //cout << "- remain_stack\n";
                //tempStack.print_stack();
                //cout << "- tempStack before removing remain_stack\n";
                int remain_length = remain_stack.size_stack();
                for (size_t j = 0; j < remain_length; ++j) {
                    tempStack.add(remain_stack.pop());
                }
                
                //tempStack.print_stack();
                //cout << "- tempStack after removing remain_stack\n";
                
                //cout << tempStack.size_stack() << "\n";
                temp_length = tempStack.size_stack();
                for (size_t j = 0; j < temp_length; ++j) add(tempStack.pop());
                //print_stack();
                //cout << "- main Stack\n";
                //for (int j = i; j > -1; --j) {

                //}
            }
        }

        
};

int main() {
    Stack first;
    first.add(4);
    first.add(5);
    first.add(1);
    first.add(4);
    first.add(3);
    first.add(2);
    first.add(2);
    //first.sort();
    first.print_stack();
    cout << "\n";
    first.sort();
    first.print_stack();
    
}