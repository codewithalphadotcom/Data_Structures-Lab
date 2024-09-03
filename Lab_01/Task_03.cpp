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