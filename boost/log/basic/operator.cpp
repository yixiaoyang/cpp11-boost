#include <iostream>

class A{
private:
    int val;
public:
    friend std::ostream& operator<< (std::ostream& out, A& classA);
    
    void operator << (int v){
        val = v;
        std::cout << *this;
    }
    
    void setVal(int v){val = v;}
    int getVal(){return val;}
};

std::ostream& operator << (std::ostream& out, A& classA){
    out << "val=" << classA.getVal() << std::endl;
    return out;
}

int main(){
    A ademo;
    ademo.setVal(12);
    
    std::cout << ademo;
    ademo << 18;
    return 0;
}