#include <iostream>
using namespace std;

class Camera
{
public:
    virtual void TakeASelfie() = 0;
    virtual void VentChat() = 0;
};

class HuaweiP20 : public Camera
{
public:
    void TakeASelfie()
    {
        cout << "Jay taking a selfie\n";
    }

    void VentChat()
    {
        cout << "\tI hacked Keith's laptop\n";
    }
};

class KeithsLaptop : public Camera
{
public:
    void TakeASelfie()
    {
        cout << "Hacker takes a selfie of Keith\n";
    }

    void VentChat()
    {
        cout << "\tGive me your money and I'll delete the selfie\n";
    }
};

int main()
{
    Camera* c1 = new HuaweiP20();
    Camera* c2 = new KeithsLaptop();

    c1->TakeASelfie();
    c2->TakeASelfie();

    cout << endl;

    c1->VentChat();
    c2->VentChat();

    system("pause");
}
