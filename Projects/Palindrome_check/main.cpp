#include <iostream>
#include <cstring>

int main(){
    int i, leng;
    char string[50];
    bool pal = 0;
    
    
    std::cout << "La stringa da verificare: "; 
    std::cin >> string;
    std::cout<< std::endl;
    
    leng = strlen(string);
    
    for(i=0;i < leng ;i++){
        if(string[i] != string[leng-i-1]){
            pal = 1;
            break;
   }
}
    
    if (pal == 1) {
        std::cout << "La stringa '" << string << "'non è palindroma " << std::endl; 
    }    
    else {
        std::cout << "La stringa '" << string << "' è palindroma " << std::endl; 
    }
    return 0;
}