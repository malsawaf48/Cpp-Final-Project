#ifndef CPU_H
#define CPU_H

#include <vector>
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
        void setValue(){}
        int getValue(){return 0;}
};
class IntObject : public MemoryObject{
    private:
        int value;
    public:
        IntObject(int v, int i){
            value = v;
            setIndex(i);
        }
        IntObject(){
        }
        void setValue(int newValue){value = newValue;}
        int getValue(){return value;}
};
class DoubleObject : public MemoryObject{
     private:
        double value;
    public:
        DoubleObject(double v, int i){
            value = v;
            setIndex(i);
        }
        DoubleObject(){
        }
        void setValue(double newValue){value = newValue;}
        double getValue(){return value;}
};

class Memory {
    private:
        std::vector<MemoryObject> memory;

    public:
        Memory(){
        }
        void store(MemoryObject newObject){memory.push_back(newObject);}

        MemoryObject getItemAt(int i){return memory[i];}

        int getIndex(){return memory.size() - 1;}

        void reStore(int i, MemoryObject newObject) {memory[i] = newObject;}

        void removeAt(int i) { memory.erase(memory.begin() + i); }
};

class CPU{
    public:
        std::vector<MemoryObject> reg;

        CPU(){
            reg.reserve(2);
        }
        void load(MemoryObject value, int i){
            reg[i] = value;
        }
        int addInt(){
            return reg[0].getValue() + reg[1].getValue();
        }

        void clearReg(){
            reg.clear();
        }
};
#endif