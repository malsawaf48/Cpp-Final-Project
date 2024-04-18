#include "C:\Users\malsa\OneDrive\Documents\Programming\Personal\Cpp-Final-Project\CPU.cpp"

CPU cpu;

class Cipher{
    private:
        int value;
        int index;
    public:
        Cipher(){
            value = 0;
            cpu.store(value);
            index = cpu.getIndex();
        }
        int getValue(){return value;}

        int operator=(int newValue){
            value = newValue;
            cpu.reStore(index, newValue);
            return value;
        }
        int operator+(int newValue){
            cpu.load(index);
            cpu.store(newValue);
            cpu.load(index+1);
            return cpu.add();
        }
        
};