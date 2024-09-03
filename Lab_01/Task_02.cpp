#include <iostream>
using namespace std;

class Exam{
    string name;
    string date;
    float score;
    public:
    void setName(string name){
        this->name = name;
    }
    void setDate(string date){
        this->date = date;
    }
    void setScore(float score){
        this->score = score;
    }
    inline void Display(){
        cout<<"\n\t----------Exam Details----------\n";
        cout<<"Name: "<<this->name<<endl;
        cout<<"Score: "<<this->score<<endl;
        cout<<"Date: "<<this->date<<endl;
    }

};

int main()
{
    Exam e1;
    e1.setName("alpha");
    e1.setScore(93);
    e1.setDate("26-08-2021");

    e1.Display();
    Exam e2 = e1;
    e2.setName("Krrishna");
    e2.Display();
    e1.Display();
    return 0;
}

/*
you'll observe that modifying e2's name also affects
e1's name, because they share the same memory location due
to the shallow copy. This is the expected behavior without a
proper copy constructor and copy assignment operator.
*/