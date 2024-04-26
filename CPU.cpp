#include <vector>

template<typename T>

class Memory{
    private:
        std::vector<T> memory;

    public:
        Memory(){
            memory;
        }
        void store(T newVal){
            memory.push_back(newVal);
        }
        int getItemAt(int i){
            return memory[i];
        }
        int getIndex(){
            return (memory.size()-1);
        }
        void reStore(int i, T newVal){
            memory[i] = newVal;
        }
        void removeAt(int i){
            memory.erase(memory.begin()+i);
        }
};
class CPU{
    public:
        std::vector<int> reg;

        CPU(){
            reg.reserve(2);
        }
        void load(int value, int i){
            reg[i] = value;
        }
        int add(){
            return reg[0] + reg[1];
        }
        int subtract(){
            return reg[0] - reg[1];
        }
        int divide(){
            return reg[0] / reg[1];
        }
        int multiply(){
            return reg[0] * reg[1];
        }
        void clearReg(){
            reg.clear();
        }
};