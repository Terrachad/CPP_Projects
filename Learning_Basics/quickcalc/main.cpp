#include <iostream>
#include <cmath>
#include <string>
#include <array>

using namespace std;

int main()
{   
    top:
    char op;
    string str, othercalc;
    double a,b;
    int chararr[7] = {'*','-' , '+', '/', '%' , '!', '^'};
    
    cout << "Scegli l'operatore (operazione)↓ \n\n( *, /, -, +, % (intero e resto), ! or ^ (aᵇ), sqrt (²√x), cbrt (³√x), round (≈), roundup (≈↑), rounddown (≈↓), > or maxint (X>x), < or minint (x<X), sin (x), cos (x) , tan(x), log(x) )\n\nOperatore -> ";
    cin >> str;
    
    bool hasMatch = false; //check bool for chararr
    for (int i=0; i < 7 ;i++) {
        if (str[0] == chararr[i]) 
        {
            cout << "Inserisci valore di A:";
            cin >> a;
            cout << "Inserisci valore di B:";
            cin >> b;
            op = str[0];
            hasMatch = true;
        }
    }
    
    if( !hasMatch ) //switch controller 
    {   
        if(str == "sqrt") {op = '1';}
        else if(str == "cbrt") {op = '2';}
        else if(str == "round") {op = '3';}
        else if(str == "roundup") {op = '4';}
        else if(str == "rounddown") {op = '5';}
        else if(str == "sin") {op = '6';}
        else if(str == "cos") {op = '7';}
        else if(str == "tan") {op = '8';}
        else if(str == "log") {op = '9';}
        else if(str == "maxint" || str == ">") {op = '>';}
        else if(str == "minint" || str == "<") {op = '<';}
        else {goto err;}
    } 

    long intero = a / b;
    long resto = fmod(a,b);
    
    switch( op ){
        case '+': cout<<a<<"+"<<b<<"="<<(a+b)<<endl;
        break;
        case '-': cout<<a<<"-"<<b<<"="<<(a-b)<<endl;
        break;
        case '*': cout<<a<<"*"<<b<<"="<<(a*b)<<endl;
        break;
        case '/':
            if( b != 0.0000){cout<<a<<"/"<<b<<"="<<(a/b)<< endl;}
            else
                for(int i=0; i<=100; i++){cout<<"*/Armaggedon*"<<endl;}
        break;
        case '%':
            cout << "Intero = " << intero << endl;
            cout << "Resto = " << resto << endl;;
        break;
        case '^': case '!': cout << a <<" ^ " << b << "="<< pow(a, b) << endl;
        break;
        case '>':
            if (a == b){cout << "I due valori sono uguali: "<< a << "=" << b << endl;}
            else{
                cout << "Inserisci valore di A:";
                cin >> a;
                cout << "Inserisci valore di B:";
                cin >> b;
                cout << endl << "Tranne A e B maggiore " << fmax(a, b) << endl;}
        break;
        case '<':
            if (a == b){cout << "I due valori sono uguali: "<< a << "=" << b << endl;}
            else{   
                cout << endl << "Inserisci valore di A:";
                cin >> a;
                cout << endl << "Inserisci valore di B:";
                cin >> b;
                cout << endl << "Tranne A e B minore " << fmin(a, b) << endl;}
        break;
        case '1':
            cout << "Radice quadrata di:";
            cin >> a;
            cout << endl <<"²√ " << a << "="<< sqrt(a) << endl;
        break;
        case '2':
            cout << "Radice cubica di:";
            cin >> a;
            cout << endl << "³√ " << a << "="<< cbrt(a) << endl;
        break;
        case '3':
            cout << "Inserisci numero da arotondare: ";
            cin >> a;
            cout << endl << "Valore arrotondato = " << round(a) << endl;
        break;
        case '4':
            cout << "Inserisci numero da arotondare su: ";
            cin >> a;
            cout << endl << "Il numero " << a << " arrotondato su:" << ceil(a) << endl;
        break;
        case '5':
            cout << "Inserisci numero da rotondare giu: ";
            cin >> a;
            cout << endl << "Il numero " << a << " arrotondato giu:" << floor(a) << endl;
        break;
        case '6':
            cout << "Inserisci valore x per trovare suo sin:";
            cin >> a;
            cout << "sin(x) di " << a << " = " << sin(a) << endl;
        break;
        case '7':
            cout << "Inserisci valore x per trovare suo cos :";
            cin >> a;
            cout << endl  << "cos(x) di " << a << " = " << cos(a) << endl;
        break;
        case '8':
            cout << "Inserisci valore x per trovare suo tan :";
            cin >> a;
            cout << endl << "tan(x) di " << a << " = " << tan(a) << endl;
        break;
        case '9':
            cout << "Inserisci valore di x da trovare log :";
            cin >> a;
            cout << endl << "log(x) di " << a << " = " << log(a) << endl;
        break;
            
        err:
        default:
            cout << str <<" - non e un operatore valido. "<< "Hai sbagliato a scegliere la operazione"<< endl;
            
    }

    cout << endl<< "Desideri fare altri operazioni? (Si/No) -> ";
    cin >> othercalc;
    
    if(othercalc == "Si" || othercalc == "SI" || othercalc == "si" || othercalc =="s" ){goto top;}
    else{cout << "Sto uscendo..."<< endl;}
    
    return 0;
}











