#include <iostream>

using namespace std;

class AnotherClass
{
    public:
        int ab;
        char ch;
        AnotherClass() = default;
        AnotherClass(char ch_char)
            : ch{ch_char}, ab{0}
        {
        }
        //AnotherClass(char ch_char, int num)
        //    : ch{ch_char}, ab{num}
        //{
        //}
        
};

class Test
{
    private:
        int val;
        AnotherClass a;
    public:
        Test(){}
        void set(int tmp);
        int get();
};

void Test::set(int tmp)
{
    val = tmp;
}

int Test::get()
{
    return val;
}


int main()
{
    Test test;
    
    test.set(10);
    cout << test.get() << '\n';

    return 0;
}
