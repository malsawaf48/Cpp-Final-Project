#include <iostream>
#include "C:\Users\malsa\OneDrive\Documents\Programming\Personal\Cpp-Final-Project\yourlang.cpp"

int main(){
    Cipher num;
    std::cout<<"\nnum is: "<<num;
    num = 3;
    std::cout<<"\nnum = 3 is: "<<num;
    num = 300;
    std::cout<<"\nnum = 300 is: "<<num;

    Cipher num2;
    std::cout<<"\n\nnum2 is: "<<num2;
    num2 = num;
    std::cout<<"\nnum2 = num is: "<<num2;
    num = num + 2;
    std::cout<<"\nnum = num + 2 is: "<<num;

    Hover decimal;
    std::cout<<"\n\ndecimal is: "<<decimal;
    decimal = 4.7;
    std::cout<<"\ndecimal = 4.7 is: "<<decimal;
    decimal = 521.123;
    std::cout<<"\ndecimal = 521.123 is: "<<decimal;
    decimal = decimal + 20.3;
    std::cout<<"\ndecimal = decimal + 20.3 is: "<<decimal;

    Argument boolean;
    std::cout<<"\n\nboolean is: "<<boolean;
    boolean = false;
    std::cout<<"\nboolean = false is: "<<boolean;
    boolean = true;
    std::cout<<"\nboolean = true is: "<<boolean;

    Chain text;
    std::cout<<"\n\ntext is: "<<text;
    text = "Hello World";
    std::cout<<"\ntext = Hello World is: "<<text;

    Figure character;
    std::cout<<"\n\ncharacter is: "<<character;
    character = 'm';
    std::cout<<"\ncharacter = m is: "<<character;
};