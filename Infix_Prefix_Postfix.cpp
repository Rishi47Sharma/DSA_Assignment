/* Name :-Rishikesh Sharma
   Roll no. :-27061
   Class :- SE IT B
   Topic:- DSA Assignment 2 */

#include <iostream>
#include <string.h>
//#include "stack.h"
using namespace std;

template <typename T>
class stack {
  private:
    struct node {
      T data;
      node *next;
    };
    //head and top pointer
    node *head, *topData;
    bool is_empty = true;
  public:
    stack(){
      head = NULL;
    }

    void push(T n){
        //create new node
      node *temp = new node;
      temp->data = n;
      temp->next = NULL;

      if (head == NULL){
        head = temp;
        topData = temp;
        if (head != NULL){
          is_empty = false;
        }
      }
      else {
        node * tmp = head;
        while(tmp->next != NULL){
          tmp = tmp->next;
        }
        tmp->next = temp;
        topData = temp;
      }
      if (head == NULL){
        is_empty = true;
      }
    }
    node* gethead(){
      return head;
    }
    void display(node *head){
      if (head == NULL){
        cout << "NULL\n";
      }
      else {
        cout << head->data << "\n";
        display(head->next);
      }
    }
    T top(){
      return topData->data;
    }
    void pop(){
      if (head == NULL){
          is_empty = true;
        }
      if(head != NULL) {
        if(head->next == NULL) {
          head = NULL;
          if (head == NULL){
            is_empty = true;
          } else {
            is_empty = false;
          }
        } else {
          node* temp = head;
          while(temp->next->next != NULL)
            temp = temp->next;
          node* lastNode = temp->next;
          temp->next = NULL;
          topData = temp;
          free(lastNode);
        }
      }
    }
    bool empty(){
      return is_empty;
    }
};

bool exp_valid (string infix){
  stack<char> st;
  for (int i = 0; i < infix.length(); i++){
	  if (infix[i] == '('){
		st.push(infix[i]);
	  } else if (infix[i] == ')'){
		if (!st.empty()){
			st.pop();
		} else {
			st.push(infix[i]);
		}
	  }
  }
  if (!st.empty()){
	cout << "\n<--------------------------->\n";
	cout << "Enter valid Infix Expression!";
	cout << "\n<--------------------------->\n";
	return false;
  }
  return true;
}

int prec(char c){
  if (c == '^'){
    return 3;
  }
  else if (c == '*' || c == '/'){
    return 2;
  }
  else if (c == '+' || c == '-'){
    return 1;
  } else {
    return -1;
  }
}

// Reverses The String
string reverse(string s){
  string tempS = "";
  for (int i = s.length() - 1; i >= 0; i--){
    tempS += s[i];
  }
  return tempS;
}

// Infix To Postfix Conversion Function
string InfixToPostfix ( string s ){
  stack<char> st;
  string postfix = "";

  for (int i = 0; i < s.length(); i++){
        //check whether it is an operand
    if (isalnum(s[i])){
      postfix += s[i];
    }
  //check whether it is an parentheses if true than push it in stack
    else if (s[i] == '('){
      st.push(s[i]);
    }
    else if (s[i] == ')'){
      while ( !st.empty() && st.top() != '('){
        postfix += st.top();
        st.pop();
      }
      if (!st.empty()){
        st.pop();
      }
    }
    else {
      while (!st.empty() && prec(st.top()) > prec(s[i])){
        postfix += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }
  while (!st.empty()){
    postfix += st.top();
    st.pop();
  }
  return postfix;
}

// Infix To Prefix Conversion Function
string InfixToPrefix ( string infix ){

  string i = InfixToPostfix ( infix );
  string s = reverse(i);
  return s;

}

// Prefix Evaluation Function
int PreEval (string s){
  stack<char> st;

  for (int i = s.length() - 1; i >= 0; i--){
    if (isalnum(s[i])){
      st.push((s[i]) - 48);
    }
    else {
      int i_1 = st.top();
      st.pop();
      int i_2 = st.top();
      st.pop();

      switch(s[i]){
        case '+':
          st.push( i_1 + i_2 );
          break;
        case '-':
          st.push( i_1 - i_2 );
          break;
        case '*':
          st.push( i_1 * i_2 );
          break;
        case '/':
          st.push( i_1 / i_2 );
          break;
      }
    }
  }
  return st.top();
}

// Postfix Evaluation Function
int PostEval (string s){
  stack<char> st;
  int val;
  char x;
  for (int i = 0; s[i] != '\0'; i++){
      x=s[i];
    if (isalpha(x)){
        cout<<"\n Enter value of "<<x<<" : ";
        cin>>val;
        st.push(val);
    }
    else {
      int i_1 = st.top();
      st.pop();
      int i_2 = st.top();
      st.pop();

      switch(s[i]){
        case '+':
          st.push( i_2 + i_1 );
          break;
        case '-':
          st.push( i_2 - i_1 );
          break;
        case '*':
          st.push( i_2 * i_1 );
          break;
        case '/':
          st.push( i_2 / i_1 );
          break;
      }
    }
  }
  return st.top();
}

// Main Function
int main(){
  // Flag Declaration For Menu
	bool flag = true;
  // Loop For Menu
  while(flag){
	  string infix, prefix, postfix;
	  int n;
	  int result;
	      cout<<"-------------------------------------"<<endl;
          cout<<"      CONVERSION AND EVALUATION      "<<endl;
          cout<<"-------------------------------------"<<endl;
    cout<<endl<<"*************************************";
    cout<<endl<<"|\t\t\t"<<"SELECT METHOD\t\t\t|";
    cout<<endl<<"*************************************";
    cout<<endl<<"|1. Infix To Prefix Conversion       |";
    cout<<endl<<"|2. Infix To Postfix Conversion      |";
    cout<<endl<<"|3. Prefix Evaluation                |";
    cout<<endl<<"|4. Postfix Evaluation               |";
    cout<<endl<<"|5. Exit                             |";
    cout<<endl<<"*************************************";

	  cout << "\nEnter Choice: ";
	  cin >> n;
	  cout<<endl;
      cout<<"------------------------------------"<<endl;
	  switch(n){
		  case 1:
			cout << "Enter Infix Expression: ";
			cin >> infix;
			if (!exp_valid(infix)){
				continue;
				break;
			}
			cout << "\nInfix To Prefix: " <<     // Display Infix To Prefix
			InfixToPrefix(infix) << "\n";
			cout<<endl;
      cout<<"------------------------------------"<<endl;
			break;

		  case 2:
			cout << "Enter Infix Expression: ";
			cin >> infix;
			if (!exp_valid(infix)){
				continue;
				break;
			}
			cout << "\nInfix To Postfix: " <<      // Display Infix To Postfix
			InfixToPostfix(infix) << "\n";
			break;
			cout<<endl;
      cout<<"------------------------------------"<<endl;

		  case 3:
			cout << "Enter Infix Expression: ";
			cin >> infix;
			if (!exp_valid(infix)){
				continue;
				break;
			}
		  prefix = InfixToPrefix(infix);

			cout << "\nPrefix Evaluation of: " << prefix << " = " <<      // Dispaly Prefix Evaluation
			PreEval(prefix) << "\n";
			break;
			cout<<endl;
      cout<<"------------------------------------"<<endl;

		  case 4:
			cout << "Enter Infix Expression: ";
			cin >> infix;
			if (!exp_valid(infix)){
				continue;
				break;
			}
			postfix = InfixToPostfix(infix);
            result = PostEval(postfix);
			cout << "\nPostfix Evaluation of: " << postfix << " = " <<    // Dispaly Postfix Evaluation
			result<< "\n";
			break;
			cout<<endl;
      cout<<"------------------------------------"<<endl;

		  case 5:
			cout << "\n\nExiting.......\n\n";
			cout<<"----✖----✖----✖----✖----✖----✖----";
            exit(0);
		  default:
			break;
	  }
  }
  return 0;
}
