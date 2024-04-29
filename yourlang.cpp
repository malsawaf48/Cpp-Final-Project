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
            mem.store(&object);
            object.setIndex(mem.getIndex());
        }
        IntObject getObject(){return object;}

        int operator=(int newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<IntObject*>(mem.getItemAt(object.getIndex()))->getValue(); //help from gpt on this line
        }
        int operator=(Cipher newCipher){
            object.setValue(newCipher.getObject().getValue());
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<IntObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        int operator+(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            object.setValue(cpu.add<int>());
            mem.reStore(object.getIndex(), &object);
            mem.removeAt(otherObject.getIndex());
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
            mem.store(&object);
            object.setIndex(mem.getIndex());
        }
        int operator=(double newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<DoubleObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        double operator+(double otherValue){
            DoubleObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            object.setValue(cpu.add<double>());
            mem.reStore(object.getIndex(), &object);
            mem.removeAt(otherObject.getIndex());
            return object.getValue();
            cpu.clearReg();
        }
        friend std::ostream& operator<<(std::ostream& os, Hover& hover){
            os << hover.object.getValue();
            return os;
        }
};
class Argument{
    private:
        BoolObject object;
    public:
        Argument(){
            object.setValue(true);
            mem.store(&object);
            object.setIndex(mem.getIndex());
        }
        bool operator=(bool newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<BoolObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        friend std::ostream& operator<<(std::ostream& os, Argument& argument){
            os << argument.object.getValue();
            return os;
        }
};

class Chain{
    private:
        StringObject object;
    public:
        Chain(){
            object.setValue("");
            mem.store(&object);
            object.setIndex(mem.getIndex());
        }
        std::string operator=(std::string newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<StringObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        friend std::ostream& operator<<(std::ostream& os, Chain& chain){
            os << chain.object.getValue();
            return os;
        }
};
class Figure{
    private:
        CharObject object;
    public:
        Figure(){
            object.setValue('0');
            mem.store(&object);
            object.setIndex(mem.getIndex());
        }
        char operator=(char newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<CharObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        friend std::ostream& operator<<(std::ostream& os, Figure& figure){
            os << figure.object.getValue();
            return os;
        }
};