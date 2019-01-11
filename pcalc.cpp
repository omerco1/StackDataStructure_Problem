#include "pcalc.h"
#include <iostream> 
#include <string>
#include <stdio.h>
#include <stack>

using namespace std;

//struct t_token {
//    bool is_number; // true if number, false if operator (- + or ,)
//    int num; // valid only if is_number is true
//    char op; // valid only if is_number is false.
//    int tok_len; // number of chars in the token
//    // always =1 if is_number is false
//    // otherwise, it contains the number of digits if is_number is true
//};

void Pcalc::parseIn(const char* a) { 
    t_token myTok;
    string s = string(a);
    int size = s.length();
    stack<int> mystack;
    while(size != 0) {
        get_token(s.c_str(), &myTok);
        //cut the string  
        s = s.substr(myTok.tok_len, size-1);
        //decrement iterator
        size -= myTok.tok_len;
        
        //Token is a number i want to push to the stack
        if (myTok.is_number) {
            mystack.push(myTok.num);
        }
        else if (myTok.op == ',' && myTok.is_number == false)
            continue;
        else {
            assert(!mystack.empty()); //Ensure non empty stack
            int num2 = mystack.top();
            mystack.pop();
            int num1 = mystack.top();
            mystack.pop();
            int result;
            switch (myTok.op) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1/num2;
                    break;
                case ',':
                    break;
                default:
                    cout << "There was an error try again" <<endl;
                    //exit(1);
            }
            mystack.push(result);
        }
    }
    if(!mystack.empty()){
        cout << mystack.top() <<endl;
        mystack.pop();
    }
    return;
}


void Pcalc::get_token(const char *s, Pcalc::t_token *tok) {
    string temp ="";
    int size=0;
    tok->is_number = false;
    string s2 = string(s);
    for (int i = 0; i < s2.length(); i++ ) {
        if ((s[i] == '+' | s[i] == '-' | s[i] == '*' | s[i] == '/' | s[i] == ',')) {
            if (tok->is_number==true)
                break;
            else {
                size++;
                tok->op = s[i];
                tok->tok_len = size;
                break;
            }
        }
        else if(s[i] >= '0' && s[i] <= '9') {
            size++;
            tok->tok_len = size;
            tok->is_number =true;
            temp += s[i];
        }
        //
        else {
            cout << "ERROR: Bad input please try again... " << endl;
            exit(1);
        }
    }
    
    if(tok->is_number){ tok->num = stoi(temp); }
    return;
}
