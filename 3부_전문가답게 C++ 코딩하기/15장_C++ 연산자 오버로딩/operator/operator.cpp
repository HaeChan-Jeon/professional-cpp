class FunctionObject
{
    public:
        int operator() (int param);
        int doSquare(int param);
};

int FunctionObject::operator() (int param)
{
    return doSquare(param);
}

int FunctionObject::doSquare(int param)
{
    return param * param;
}

int main()
{
    int x{ 3 }, xSquared, xSquaredAgain;
    FunctionObject square;
    xSquared = square(x);
    xSquaredAgain = square.doSquare(x);
}