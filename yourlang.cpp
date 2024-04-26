#include "CPU.h"
#include <ostream>

CPU cpu;
Memory mem;

class Cipher{
    private:
        IntObject object;
        
    public:
        Cipher(){
            object.setValue(0);
            mem.store(object);
            object.setIndex(mem.getIndex());
        }

        int operator=(int newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), object);
            return mem.getItemAt(object.getIndex()).getValue();
        }
        int operator+(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(otherObject);
            cpu.load(object, 0);
            cpu.load(otherObject, 1);
            object.setValue(cpu.addInt());
            mem.removeAt(otherObject.getIndex());
            mem.reStore(object.getIndex(), object);
            return object.getValue();
            cpu.clearReg();
        }
        friend std::ostream& operator<<(std::ostream& os, Cipher& cipher){
            os << cipher.object.getValue();
            return os;
        } 
};

class Hover{
    private:
        DoubleObject object;
        
    public:
        Hover(){
            object.setValue(0.0);
            mem.store(object);
            object.setIndex(mem.getIndex());
        }

        int operator=(double newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), object);
            return mem.getItemAt(object.getIndex()).getValue();
        }
        friend std::ostream& operator<<(std::ostream& os, Hover& hover){
            os << hover.object.getValue();
            return os;
        } 

};