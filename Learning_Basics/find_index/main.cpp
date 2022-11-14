#include <iostream>

using namespace std;

int main()
{
    int a;
    string phrase = "Netfinity Academy";

    phrase[0] = 'B';
    cout << phrase.length() << endl;
    cout << phrase.find("Academy", 0)<<endl;
    cout << phrase << endl;


    return 0;
}