#include <iostream>
#include <stack>
using namespace std;


bool balancedParentheses(string s){
    stack<char> st;
    for (char c : s){
        if (c == '[' || c == '{' || c == '('){
            st.push(c);
        } else {
            if (st.empty()){
                return false;
            }

            char top = st.top();
            st.pop();

            if (c == ']' && top != '[' || c == '}' && top != '{' || c == ')' && top != '('){
                return false;
            }
        }
    }

    return st.empty();
}


class Stack{
    int size;
    int top;

};

int main(){

    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (balancedParentheses(s)){
        cout << "Balanced" << endl;
    } else {
        cout << "Not balanced" << endl;
    }
}
