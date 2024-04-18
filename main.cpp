#include <iostream>
#include "C:\Users\malsa\OneDrive\Documents\Programming\Personal\Cpp-Final-Project\yourlang.cpp"
int main(){
    Cipher num;
    std::cout << num.getValue();

    num = 5;
    std::cout <<"\n"<< num.getValue();

    num = num + 4;
    std::cout <<"\n"<< num.getValue();

    Cipher num2;
    std::cout <<"\n"<< num2.getValue();

    num2 = 3;
    std::cout <<"\n"<< num2.getValue();
};