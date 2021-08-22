#include <iostream>
using namespace std;

template <class T>
struct Functions // Structure within a template to define multiple functions.
                 // Otherwise, I'm pretty sure you can only define one thing under a template. 
{
    // use T as the return type so you can use whatever data type you want when calling the functions
    // a static function is a member function that can be called even when an object of the class is not initialized
    static T divide_num(T a, T b) 
    {
        return (a / b);
    }

    static T add_num(T a, T b)
    {
        return a + b;
    }
};

int main()
{
    long a = 3425, b = 7456, c;
    double d = 3.444, e = 78.323, f;
    float g = 55.345, h = 23.155, i;
    string hello = "Hello ", world = "World!", helloworld;
    
    // functions being called from the class even when there is no object of the class
    c = Functions<long>::add_num(a , b); 
    f = Functions<double>::divide_num(d, e);
    i = Functions<float>::add_num(g, h); 
    helloworld = Functions<string>::add_num(hello, world); // add_num even works with string, because the function is just adding to variables together

    cout << c << endl;
    cout << f << endl;
    cout << i << endl;
    cout << helloworld << endl;

    return 0;
}