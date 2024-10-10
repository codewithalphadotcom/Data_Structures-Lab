#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (top)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(string value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    string pop()
    {
        if (top == nullptr)
        {
            return "";
        }

        string value = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    string peek()
    {
        if (top)
            return top->data;

        return "";
    }

    bool isEmpty()
    {
        return (top == nullptr);
    }
};

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;

    return -1;
}

bool isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return true;

    return false;
}

string infixToPostfix(const string &infix)
{
    Stack st;
    string postfix;
    string number;

    for (int i = 0; i < infix.length(); ++i)
    {
        char c = infix[i];
        if (isdigit(c) || c == '.')
        {
            number += c;
        }
        else
        {
            if (!number.empty())
            {
                postfix += number + ' ';
                number.clear();
            }
            if (isalpha(c))
            {
                postfix += c;
            }
            else if (c == '(')
            {
                st.push(string(1, c));
            }
            else if (c == ')')
            {
                while (!st.isEmpty() && st.peek()[0] != '(')
                {
                    postfix += st.pop() + ' ';
                }
                st.pop();
            }
            else if (isOperator(c))
            {
                while (!st.isEmpty() && precedence(st.peek()[0]) >= precedence(c))
                {
                    postfix += st.pop() + ' ';
                }
                st.push(string(1, c));
            }
        }
    }

    if (!number.empty())
    {
        postfix += number + ' ';
    }

    while (!st.isEmpty())
    {
        postfix += st.pop() + ' ';
    }

    return postfix;
}

double evaluatePostfix(const string &postfix)
{
    Stack st;
    string token;
    for (int i = 0; i < postfix.length(); ++i)
    {
        char c = postfix[i];
        if (isdigit(c) || c == '.')
        {
            token += c;
        }
        else if (c == ' ' && !token.empty())
        {
            st.push(token);
            token.clear();
        }
        else if (isOperator(c))
        {
            double op2 = stod(st.pop());
            double op1 = stod(st.pop());

            double result;

            if (c == '+')
                result = op1 + op2;
            else if (c == '-')
                result = op1 - op2;
            else if (c == '*')
                result = op1 * op2;
            else if (c == '/')
                result = op1 / op2;
            else if (c == '^')
                result = pow(op1, op2);
            else
                return 0;

            st.push(to_string(result));
        }
    }
    return stod(st.pop());
}

int main()
{
    string expression = "12+13-5*(0.5+0.5)+1";
    string infix = "x=" + expression;

    cout << "Infix Expression: " << infix << endl
         << endl;

    string postfix = infixToPostfix(expression);
    cout << "Postfix Expression: " << postfix << endl;

    double result = evaluatePostfix(postfix);

    cout << fixed << setprecision(2); // fixed and setprecision() are just for formatting
    cout << "Result: " << result << endl;

    Stack st;
    st.push("x=");
    st.push(to_string(result));

    cout << "\nFinal Stack Contents:" << endl;

    string value = st.pop();
    cout << fixed << setprecision(2) << stod(value) << endl;
    string x = st.pop();
    cout << x << endl;

    cout << x << fixed << setprecision(2) << stod(value) << endl;

    return 0;
}
