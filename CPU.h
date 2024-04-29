#ifndef CPU_H
#define CPU_H

#include <vector>
#include <iostream>
class MemoryObject{
    private:
        int index;
    public:
        MemoryObject(int i){
            index = i;
        }
        MemoryObject(){
        }
        virtual void setIndex(int newIndex){index = newIndex;}
        virtual int getIndex(){return index;}
};
class IntObject : public MemoryObject{
    private:
        int value;
    public:
        IntObject(int v, int i){
            value = v;
            setIndex(i);}
        IntObject(){}
        void setValue(int newValue){value = newValue;}
        int getValue(){ return value; }
};

class DoubleObject : public MemoryObject{
     private:
        double value;
    public:
        DoubleObject(double v, int i){
            value = v;
            setIndex(i);}
        DoubleObject(){}
        void setValue(double newValue){value = newValue;}
        double getValue(){ return value; }
};


class Memory {
    private:
        std::vector<MemoryObject*> memory;

    public:
        Memory(){
        }
        void store(MemoryObject* newObject){memory.push_back(newObject);}

        MemoryObject* getItemAt(int i){return memory[i];}

        int getIndex(){return memory.size() - 1;}

        void reStore(int i, MemoryObject* newObject) {memory[i] = newObject;}

        void removeAt(int i) { memory.erase(memory.begin() + i); }
};

class CPU{
    public:
        std::vector<MemoryObject*> reg;

        CPU(){
            reg.reserve(2);
        }
        void load(MemoryObject* value, int i){
            reg[i] = value;
        }
        template<typename T>
        T add() {
            if (typeid(*reg[0]) == typeid(IntObject)) { //learned from chatgpt how to do this
                IntObject* obj1 = dynamic_cast<IntObject*>(reg[0]);
                IntObject* obj2 = dynamic_cast<IntObject*>(reg[1]);
                return obj1->getValue() + obj2->getValue();
            }//end help from gpt
            else if (typeid(*reg[0]) == typeid(DoubleObject)){
                DoubleObject* obj1 = dynamic_cast<DoubleObject*>(reg[0]);
                DoubleObject* obj2 = dynamic_cast<DoubleObject*>(reg[1]);
                return obj1->getValue() + obj2->getValue();
            }
            // Handle case when objects are of different types
            return static_cast<T>(0);
        }

        void clearReg(){
            reg.clear();
        }
};
#endif