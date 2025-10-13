#include <iostream>

using namespace std;

class Dog
{
    public:
        virtual void bark() { cout << "Woof!" << endl; }
        virtual void eat() { cout << "The dog ate." << endl; }
};

class Bird
{
    public:
        virtual void chirp() { cout << "Chirp!" << endl; }
        virtual void eat() { cout << "The bird ate." << endl; }
};

class DogBird : public Dog, public Bird
{
public:
    void eat() override
    {
        Dog::eat();
    }
    using Dog::eat;
};

int main()
{
    DogBird myConfusedAnimal;
    dynamic_cast<Dog&>(myConfusedAnimal).eat();
    myConfusedAnimal.Dog::eat();
    myConfusedAnimal.eat();
}