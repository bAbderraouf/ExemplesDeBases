#include <iostream>


class A {

    int age;

    public :
        void setAge(int a){
            age = a;
        }
        void getAge(void){
            std::cout << "age = " << age << std::endl;
        }

        A(){
            age=0;
        }
        ~A(){}
    
};


int main(){

    A obj1;
    obj1.getAge();

    obj1.setAge(5);
    obj1.getAge();

    return 0;
}