#include <iostream>

using namespace std;

template <typename T, int SIZE>
class Stack {
  private:
        T items[SIZE];
        int topPointer;

  public:
        Stack () : topPointer(0){
        }

        void push (T const& item) {
                if (topPointer != SIZE) {
                        items[topPointer] = item;
                        topPointer++;
                } else {
                        cout << "The stack is full";
                }
        }

        void pop() {
                if (isEmpty()) {
                        cout << "The stack is empty";
                } else {
                        --topPointer;
                }
        }

        T top () const
        {
                if (isEmpty()) {
                        cout << "The stack is empty";
                        return NULL;
                }
                return items[topPointer - 1];
        }

        bool isEmpty () const
        {
                return topPointer == 0;
        }
};

int main()
{
        Stack<int, 50> intStack;
        Stack<char, 100> charStack;
        
        intStack.push(5);
        cout << intStack.top() << endl;

        charStack.push('a');
        cout << charStack.top() << endl;
        charStack.pop();
}
