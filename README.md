# Data Structures Lab Tasks.

_This repository contains the solution sets of all the assignments of Data Structures Course in my 3rd Semester._

## _Lab-01 (Revision of OOP concepts covered in last semester i.e. 2nd Semester)_

### Task-01

![Task-01](assets/images/Lab_01/Task_01.png)

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

![Task-02](assets/images/Lab_01/Task_02.png)

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

![Task-03](assets/images/Lab_01/Task_03.png)

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

## _Lab-02 (Array Data Structure)_

### Task-01

![Task-01](assets/images/Lab_02/Task_01.png)
1. _Implement Jagged arrays from the above pseudocode by taking a size of 5 and resizing it to 10 in each index._

#### Solution
```CPP
#include <iostream>
using namespace std;

int main()
{

    int **jaggedArray = new int *[5];
    for (int i = 0; i < 5; i++)
    {
        jaggedArray[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            jaggedArray[i][j] = (i + j) + 1; // (i + j) + 1 => just adding some values to the array for testing
        }
    }

    cout << "--------------" << endl;
    cout << "Jagged Array Before Resizing: " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Resizing the jagged array to 5 x 10
    for (int i = 0; i < 5; i++)
    {
        int *temp = new int[10];
        for (int j = 0; j < 5; j++)
        {
            temp[j] = jaggedArray[i][j];
        }
        for (int j = 5; j < 10; j++)
        {
            temp[j] = 9; // placing 9 to the another 5x5 part of the array. 9 => universal number :)
        }
        delete[] jaggedArray[i];
        jaggedArray[i] = temp;
    }

    cout << "--------------" << endl;
    cout << "Jagged Array After Resizing: " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocating the memory here...!
    for (int i = 0; i < 5; i++)
    {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}
```