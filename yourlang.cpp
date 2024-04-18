#include "C:\Users\malsa\OneDrive\Documents\Programming\Personal\Cpp-Final-Project\CPU.cpp"

CPU cpu;
Memory mem;

class Cipher{
    private:
        int value;
        int index;
    public:
        Cipher(){
            value = 0;
            mem.store(value);
            index = mem.getIndex();
        }
        int getValue(){return mem.getItemAt(index);}

        int operator=(int newValue){
            value = newValue;
            mem.store(newValue);
            mem.removeAt(index);
            index = mem.getIndex();
            return value;
        }
        int operator+(int newValue){
            cpu.load(value, 0);
            mem.store(newValue);
            int newIndex = mem.getIndex();
            cpu.load(newValue, 1);
            value = cpu.add();
            mem.store(value);
            mem.removeAt(newIndex);
            mem.removeAt(index);
            index = mem.getIndex();
            return value;
            cpu.clearReg();
        }
        int operator-(int newValue){
            cpu.load(value, 0);
            mem.store(newValue);
            int newIndex = mem.getIndex();
            cpu.load(newValue, 1);
            value = cpu.subtract();
            mem.store(value);
            mem.removeAt(newIndex);
            mem.removeAt(index);
            index = mem.getIndex();
            return value;
            cpu.clearReg();
        }
        int operator/(int newValue){
            cpu.load(value, 0);
            mem.store(newValue);
            int newIndex = mem.getIndex();
            cpu.load(newValue, 1);
            value = cpu.divide();
            mem.store(value);
            mem.removeAt(newIndex);
            mem.removeAt(index);
            index = mem.getIndex();
            return value;
            cpu.clearReg();
        }
        int operator*(int newValue){
            cpu.load(value, 0);
            mem.store(newValue);
            int newIndex = mem.getIndex();
            cpu.load(newValue, 1);
            value = cpu.multiply();
            mem.store(value);
            mem.removeAt(newIndex);
            mem.removeAt(index);
            index = mem.getIndex();
            return value;
            cpu.clearReg();
        }
        friend std::ostream& operator<<(std::ostream& os, const Cipher& cipher){
            os << cipher.value;
            return os;
        }
        
        
};