#include <iostream>

using namespace std;

class Dog
{
    public:
        virtual void bark() { cout << "Woof!" << endl; }
};

class Bird
{
    public:
        virtual void chirp() { cout << "Chirp!" << endl; }
};

class DogBird : public Dog, public Bird
{
};

int main()
{
    DogBird myConfusedAnimal;
    myConfusedAnimal.bark();
    myConfusedAnimal.chirp();
}