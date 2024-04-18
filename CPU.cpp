#include <vector>

class MemoryObject{};
//seperate memory and cpu.
class CPU{
    public:
        std::vector<int> reg;
        std::vector<int> memory;

        CPU(){
        }
        int getIndex(){
            return (memory.size()-1);
        }
        void reStore(int i, int newVal){
            memory[i] = newVal;
        }
        void store(int newVal){
            memory.push_back(newVal);
        }
        void load(int i){
            reg.push_back(memory[i]);
        }
        int add(){
            reg.push_back(reg[0] + reg[1]);
            return reg[2];
        }
};