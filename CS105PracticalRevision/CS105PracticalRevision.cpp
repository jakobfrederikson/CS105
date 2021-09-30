#include <iostream>
using namespace std;

// CS105 Practical Exam will focus on:
//      1. Encapsulation
//      2. Inheritence
//      3. Virtual Functions
//      4. Opererator Overloading


// =============================================================================================
// E N C A P S U L A T I O N
//      - Hiding unnecessary data from the outside world
//      - Wrapping data up under a single type
// ---------------------------------------------------------------------------------------------
class Encapsulation
{
private:
    int encapsulated_variable_;
public:
    void SetEncapsVariable(int x)
    {
        encapsulated_variable_ = x;
    }
    int GetEncapsVariable()
    {
        return encapsulated_variable_;
    }
};
// =============================================================================================


// =============================================================================================
// I N H E R I T E N C E
//      - Create classes by starting with an existing class
//      - Inherit properties of a base class
//      - Base/Parent/Superclass
//      - Child/Subclass
// ---------------------------------------------------------------------------------------------
class Inheritence
{
protected:
    int base_var1;
    double base_var2;
};

class Child : public Inheritence
{
public:
    void SetBaseVars(int x, double y)
    {
        base_var1 = x;
        base_var2 = y;
    }
};

class GrandChild : public Child
{
public:
    int GetBaseVar1()
    {
        return base_var1;
    }
    double getBaseVar2()
    {
        return base_var2;
    }
};
// =============================================================================================


// =============================================================================================
// V I R T U A L  F U N C T I O N S
//      - A virtual function is a member function you expect to be redefined in a derived class
//      - When you refer to a derived class object using a pointer or reference, you can call a
//        virtual function for that object to execute the derived class's version of the function.
//      - Ensures the correct functions is called for an object.
// ---------------------------------------------------------------------------------------------
class Animal
{
public:
    virtual void AnimalSound()
    {
        cout << "Default animal sound.\n";
    }
};

class Dog : public Animal
{
public:
    void AnimalSound()
    {
        cout << "Bark bark! I'm a dog.\n";
    }
};

class Cat : public Animal
{
public:
    void AnimalSound()
    {
        cout << "Meow, I am a cat :)\n";
    }
};
// =============================================================================================


// =============================================================================================
// O P E R A T O R  O V E R L O A D I N G
//      - To make complex datatypes behave like primitive data types
// ---------------------------------------------------------------------------------------------
class Human
{
private:
    string _name;
    double _weightInKG;
    double _heightInCM;
    double _wingspanInCM;
    int _age;

public:
    // For normal humans.
    Human(double weight = 0.00, string n = "default", double height = 0.00, double wingspan = 0.00, int age = 0)
    {
        _name = n;
        _weightInKG = weight;
        _heightInCM = height;
        _wingspanInCM = wingspan;
        _age = age;
        cout << "[ New Human: " << _name << " has been constructed. ]\n";
    }

    // For offspring only.
    Human(string o)
    {
        _name = o;
        cout << "[ New Human: " << _name << " has been constructed. ]\n";
    }

    // Output details of a human.
    void HumanDetails()
    {
        cout << "Name:     " << this->_name << "\n";
        cout << "Age:      " << this->_age << "\n";
        cout << "Weight:   " << this->_weightInKG << "\n";
        cout << "Height:   " << this->_heightInCM << "\n";
        cout << "Wingspan: " << this->_wingspanInCM << "\n\n";
    }

    // Creating a new human.
    Human operator+(const Human& other)
    {
        cout << "Creating new offspring . . .\n";
        string offspring_name = (this->_name.substr(0, 2) + other._name.substr(0, 2));
        Human h(offspring_name);

        h._name = (this->_name.substr(0,2) + other._name.substr(0,2));
        h._weightInKG = (this->_weightInKG + other._weightInKG) / 3;
        h._heightInCM = (this->_heightInCM + other._heightInCM) / 3;
        h._wingspanInCM = (this->_wingspanInCM + other._wingspanInCM) / 3;
        h._age = (this->_age + other._age) / 4;
        
        return h;
    }

    // Clone a human into another human.
    Human operator=(const Human& other)
    {
        cout << "[ CLONING IN PROGRESS ] . . .\n";
        this->_name = other._name;
        this->_age = other._age;
        this->_heightInCM = other._heightInCM;
        this->_weightInKG = other._weightInKG;
        this->_wingspanInCM = other._wingspanInCM;

        return *this;
    }

    // Check if two humans are the exact same.
    bool operator==(const Human& other)
    {
        if (this->_heightInCM == other._heightInCM &&
            this->_weightInKG == other._weightInKG &&
            this->_wingspanInCM == other._wingspanInCM)
            return true;
        else
            return false;
    }
};
// =============================================================================================


int main()
{
    cout << "\n==== ENCAPSULATION ====\n";
    Encapsulation encapsObj;
    encapsObj.SetEncapsVariable(5);
    cout << encapsObj.GetEncapsVariable() << "\n\n";

    cout << "==== INHERITENCE ====\n";
    GrandChild grandObj;
    grandObj.SetBaseVars(3, 4.32);
    cout << grandObj.GetBaseVar1() << " " << grandObj.getBaseVar2() << "\n\n";

    cout << "==== VIRTUAL FUNCTIONS ====\n";
    Animal* NoahsArk[3];
    NoahsArk[0] = new Animal;
    NoahsArk[0]->AnimalSound(); // Default animal sound.
    NoahsArk[1] = new Dog;
    NoahsArk[1]->AnimalSound(); // Dog sound.
    NoahsArk[2] = new Cat;
    NoahsArk[2]->AnimalSound(); // Cat sound.
    cout << "\n";

    cout << "==== OPERATOR OVERLOADING ====\n";
    Human George(83.45, "George", 183, 185, 26);
    Human Sally(68, "Sally", 168, 172, 25);

    George.HumanDetails();
    Sally.HumanDetails();

    cout << boolalpha;
    cout << "George == Sally ? " << (George == Sally) << "\n\n";

    Human unknown1 = George + Sally;
    unknown1.HumanDetails();

    Human unknown2 = unknown1 + George;
    unknown2.HumanDetails();

    unknown1 = unknown2;

    cout << "\nUnknown1 should now equal unknown2\n";
    cout << "\nUnknown1\n";
    unknown1.HumanDetails();
    cout << "Unknown2\n";
    unknown2.HumanDetails();

    cout << "\n\n";
    system("pause");
}
