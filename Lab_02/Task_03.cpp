#include <iostream>
using namespace std;

class FriendsArray {
private:
    static const int n = 5;
    static bool friends[n][n];

public:
    static bool commonFriend(int personOne, int personTwo) {
        for (int i = 0; i < n; i++) {
            if ((friends[personOne][i]) && (friends[personTwo][i])) {
                return true;
            }
        }
        return false;
    }
};

// Initialize the static member
bool FriendsArray::friends[n][n] = {
    {false, true, false, true, false},
    {true, false, true, false, true},
    {false, true, false, false, false},
    {true, false, false, false, true},
    {true, true, false, true, false}
};

int main() {
    // test the program and verify by changing the index value of the two persons here...!
    int personOne = 2;
    int personTwo = 3;

    if (FriendsArray::commonFriend(personOne, personTwo)) {
        cout << personOne << " and " << personTwo << " have a common friend." << endl;
    } else {
        cout << personOne << " and " << personTwo << " have no common friend." << endl;
    }

    return 0;
}
