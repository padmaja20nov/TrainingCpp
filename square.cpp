#include <iostream>
using namespace std;

class Square
{
        double side;

        public:
                Square(double side)
                {
                        this->side = side;
                }

                void display()
                {
                        cout<<"Side : "<<side<<endl;
                }

                double getSide () {
                        return side;
                }

                friend Square* operator+(int num, const Square&);
};

Square* operator+(int num, const Square &s)
{
        return new Square(s.side + num);
}

int main()
{
        Square square(5);
        Square* biggerSquare = 3 + square;
        biggerSquare->display();
        return 0;
}
