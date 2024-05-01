#ifndef YOURLANG_H
#define YOURLANG_H


#include "CPU.h"
#include <iostream>

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
        int operator-(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            object.setValue(cpu.subtract<int>());
            mem.reStore(object.getIndex(), &object);
            mem.removeAt(otherObject.getIndex());
            return object.getValue();
            cpu.clearReg();
        }
        int operator*(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            object.setValue(cpu.multiply<int>());
            mem.reStore(object.getIndex(), &object);
            mem.removeAt(otherObject.getIndex());
            return object.getValue();
            cpu.clearReg();
        }
        int operator/(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            object.setValue(cpu.divide<int>());
            mem.reStore(object.getIndex(), &object);
            mem.removeAt(otherObject.getIndex());
            return object.getValue();
            cpu.clearReg();
        }
        bool operator>(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.greater<int>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        bool operator<(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.less<int>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        bool operator>=(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.greaterEqual<int>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        bool operator<=(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.lessEqual<int>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        bool operator==(int otherValue){
            IntObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.isEqual<int>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        friend std::ostream& operator<<(std::ostream& os, Cipher& cipher){
            os << cipher.object.getValue();
            return os;
        }
        friend std::istream& operator>>(std::istream& is, Cipher& cipher){
            int value;
            is >>value;
            cipher.object.setValue(value);
            return is;
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
        DoubleObject getObject(){return object;}

        double operator=(double newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<DoubleObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        double operator=(Hover newHover){
            object.setValue(newHover.getObject().getValue());
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
        double operator-(double otherValue){
            DoubleObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            object.setValue(cpu.subtract<double>());
            mem.reStore(object.getIndex(), &object);
            mem.removeAt(otherObject.getIndex());
            return object.getValue();
            cpu.clearReg();
        }
        double operator*(double otherValue){
            DoubleObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            object.setValue(cpu.multiply<double>());
            mem.reStore(object.getIndex(), &object);
            mem.removeAt(otherObject.getIndex());
            return object.getValue();
            cpu.clearReg();
        }
        double operator/(double otherValue){
            DoubleObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            object.setValue(cpu.divide<double>());
            mem.reStore(object.getIndex(), &object);
            mem.removeAt(otherObject.getIndex());
            return object.getValue();
            cpu.clearReg();
        }
        bool operator>(double otherValue){
            DoubleObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.greater<double>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        bool operator<(double otherValue){
            DoubleObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.less<double>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        bool operator>=(double otherValue){
            DoubleObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.greaterEqual<double>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        bool operator<=(double otherValue){
            DoubleObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.lessEqual<double>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        bool operator==(double otherValue){
            DoubleObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.isEqual<double>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        friend std::ostream& operator<<(std::ostream& os, Hover& hover){
            os << hover.object.getValue();
            return os;
        }
        friend std::istream& operator>>(std::istream& is, Hover& hover){
            double value;
            is >>value;
            hover.object.setValue(value);
            return is;
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
        BoolObject getObject(){return object;}

        bool operator=(bool newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<BoolObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        bool operator=(Argument newArgument){
            object.setValue(newArgument.getObject().getValue());
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<BoolObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        bool operator==(bool otherValue){
            BoolObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.isEqual<bool>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        friend std::ostream& operator<<(std::ostream& os, Argument& argument){
            os << argument.object.getValue();
            return os;
        }
        friend std::istream& operator>>(std::istream& is, Argument& argument){
            bool value;
            is >>value;
            argument.object.setValue(value);
            return is;
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
        StringObject getObject(){return object;}

        std::string operator=(std::string newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<StringObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        std::string operator=(Chain newChain){
            object.setValue(newChain.getObject().getValue());
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<StringObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        bool operator==(std::string otherValue){
            StringObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.isEqual<bool>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        friend std::ostream& operator<<(std::ostream& os, Chain& chain){
            os << chain.object.getValue();
            return os;
        }
        friend std::istream& operator>>(std::istream& is, Chain& chain){
            std::string value;
            std::getline(is, value);
            chain.object.setValue(value);
            return is;
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
        CharObject getObject(){return object;}
        char operator=(char newValue){
            object.setValue(newValue);
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<CharObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        char operator=(Figure newFigure){
            object.setValue(newFigure.getObject().getValue());
            mem.reStore(object.getIndex(), &object);
            return dynamic_cast<CharObject*>(mem.getItemAt(object.getIndex()))->getValue();
        }
        bool operator==(char otherValue){
            CharObject otherObject(otherValue, object.getIndex()+1);
            mem.store(&otherObject);
            cpu.load(&object, 0);
            cpu.load(&otherObject, 1);
            return cpu.isEqual<bool>();
            mem.removeAt(otherObject.getIndex());
            cpu.clearReg();
        }
        friend std::ostream& operator<<(std::ostream& os, Figure& figure){
            os << figure.object.getValue();
            return os;
        }
        friend std::istream& operator>>(std::istream& is, Figure& figure){
            char value;
            is >>value;
            figure.object.setValue(value);
            return is;
        } 
};

template<typename T>
void gain(T& value) {
    std::cin >> value;
}
void reveal() {
    std::cout << std::endl;
}
template<typename T, typename... Args>
void reveal(T value, Args&&... args) {
    std::cout << value;
    reveal(std::forward<Args>(args)...);//little help from gpt here
}
template<typename T>
T condition(bool condition, T ifTrue, T ifFalse){
    if(condition){
        return ifTrue;
    }
    else{
        return ifFalse;
    }
}

template <typename T>
void reRun(T value, int times) {
    int i = 0;
    while(i < times){
        reveal(value);
        i++;
    }
}


#endif