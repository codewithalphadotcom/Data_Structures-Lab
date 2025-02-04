## _Lab-01 (Revision of OOP concepts covered in last semester i.e. 2nd Semester)_

### Task-01

![Task-01](../assets/images/Lab_01/Task_01.png)

#### Solution

```CPP
#include <iostream>
using namespace std;

class BankAccount
{
    double balance;

public:
    BankAccount()
    {
        this->balance = 0;
    }

    BankAccount(double balance)
    {
        this->balance = balance;
    }

    BankAccount(const BankAccount &account)
    {
        balance = (account.balance) - 200;
    }

    void Display()
    {
        cout << "Your Account Balance is: " << balance << "\n\n";
    }
};

int main()
{
    BankAccount account1;
    account1.Display();

    BankAccount account2(1000);
    account2.Display();

    BankAccount account3(account2);
    account3.Display();
    account2.Display();

    return 0;
}
```

### Task-02

![Task-02](../assets/images/Lab_01/Task_02.png)

#### Solution

```CPP
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
```

### Task-03

![Task-03](../assets/images/Lab_01/Task_03.png)

#### Solution

```CPP
#include <iostream>
#include <string>
using namespace std;

class Document
{
private:
    string *textContent;

public:
    Document()
    {
        textContent = nullptr;
    }

    Document(string content)
    {
        textContent = new string(content);
    }

    Document(const Document &other)
    {
        textContent = new string(*other.textContent);
    }

    Document &operator=(const Document &other)
    {
        if (this != &other)
        {
            delete textContent;
            textContent = new string(*other.textContent);
        }
        return *this;
    }

    const string &getTextContent() const
    {
        return *textContent;
    }

    ~Document()
    {
        delete textContent;
    }
};

int main()
{
    Document doc("Subscribe to codewithalpha Youtube Channel");

    Document copiedDoc(doc);
    Document copyUsingCAO;
    copyUsingCAO = doc;
    doc = Document("Checkout krrishkumar.me for more social handles");

    cout << "\n---------------\n";
    cout << "Original: " << doc.getTextContent() << endl;
    cout << "Copy using Copy Constructor: " << copiedDoc.getTextContent() << endl;
    cout << "Copy using Copy Assignment Operator: " << copyUsingCAO.getTextContent() << endl;
    cout << "--------------------------------\n";

    return 0;
}
```
