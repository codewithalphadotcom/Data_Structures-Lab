#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 100;

class Stack
{
private:
    char data[MAX];
    int top;

public:
    Stack() : top(-1) {}
    void push(char value);
    char pop();
    char peek();
    bool is_empty();
};

void Stack::push(char value)
{
    if (top < (MAX - 1))
    {
        data[++top] = value;
    }
    else
    {
        cout << "Stack Overflow!" << endl;
    }
}

char Stack::pop()
{
    if (top >= 0)
    {
        return data[top--];
    }
    else
    {
        cout << "Stack Underflow!" << endl;
        return ' ';
    }
}

char Stack::peek()
{
    if (top < 0)
    {
        cout << "Empty Stack!" << endl;
        return 0;
    }
    return data[top];
}

bool Stack::is_empty()
{
    return (top < 0);
}

bool is_palindrome(const char *word)
{
    Stack stack;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        stack.push(word[i]);
    }

    for (int i = 0; i < length; i++)
    {
        if (word[i] != stack.pop()) // stack.pop() will keep returning the ending characters which will then be compared with the "words" character array!
        {
            return false;
        }
    }

    return true;
}

int main()
{
    const char *word = "BORROWROB";
    if (is_palindrome(word))
    {
        cout << word << " is Palindrome!" << endl;
    }
    else
    {
        cout << word << " is not a Palindrome!" << endl;
    }

    return 0;
}