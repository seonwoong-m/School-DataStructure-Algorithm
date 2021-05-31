#include <iostream>
#include <ctype.h> 
#include <stdlib.h>
using namespace std;

//중위를 후위로 바꾸기 위한 연산
class CharStack {
private: //class 내부 접근
    int stack[100];
    int top;
public: // 내부/외부 접근 가능
    CharStack() { top = -1; }
    void push(char val) { stack[++top] = val; }  //stack 에 val 값 넣기
    char pop() { return stack[top--]; }   //stack 에 값 빼기
    int isEmpty() { return top == -1; }
    int isFull() { return top == 99; }
    char getTop() { return stack[top]; }
};

//intStack  -- postfix result 연산위한 stack
class IntStack {
private:
    int stack[100];
    int top;
public:
    IntStack() { top = -1; }
    void push(int val) { stack[++top] = val; }
    int pop() { return stack[top--]; }
    int isEmpty() { return top == -1; }
    int isFull() { return top == 99; }
};

//calculator class 정의
class Calculator {
private:
    char buffer[80];
    char postfix[80];

    IntStack s1;
    CharStack s2;

    void infixTopostfix();
    void result();
    int priority(char);

public:
    void calculate(char[]);
};

int Calculator::priority(char ch) { // 연산자에 우선순위를 지정해 준다
    if (ch == ')')
        return 4;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 1;
}

void Calculator::calculate(char infix[]) { // 중위 표기법인 연산들을 buffer[i]에 넣어준다
    for (int i = 0; i < 80; i++)
        buffer[i] = infix[i];
    infixTopostfix();
    result();
}

void Calculator::infixTopostfix() { //중위 표기법 -> 후위 표기법
    int i = 0, j = 0;
    char ch;

    while (buffer[i] != NULL) {
        if (buffer[i] == ' ') //공백이면 다음 버퍼로 넘어간다
            i++;
        else if (isdigit(buffer[i])) { //buffer[i]의 값이 숫자면 postfix에 출력
            while (isdigit(buffer[i]))
                postfix[j++] = buffer[i++];
            postfix[j++] = ' ';
        }

        else if (buffer[i] == '(') { //시작 괄호는 스택에 넣어준다
            s2.push(buffer[i]);
            i++;
        }
        else if (buffer[i] == ')') { //마침 괄호를 발견 할때까지 연산자들을 pop
            ch = s2.pop();
            while (ch != '(') {
                postfix[j++] = ch;
                postfix[j++] = ' ';
                ch = s2.pop();
            }
            i++;
        }

        else if (buffer[i] == '{') {
            s2.push(buffer[i]);
            i++;
        }
        else if (buffer[i] == '}') {
            ch = s2.pop();
            while (ch != '{') {
                postfix[j++] = ch;
                postfix[j++] = ' ';
                ch = s2.pop();
            }
            i++;
        }
        else if (buffer[i] == '[') {
            s2.push(buffer[i]);
            i++;
        }
        else if (buffer[i] == ']') {
            ch = s2.pop();
            while (ch != '[') {
                postfix[j++] = ch;
                postfix[j++] = ' ';
                ch = s2.pop();
            }
            i++;
        }
        else {
            if (s2.isEmpty())
                s2.push(buffer[i++]);
            else { //스택에 있는 자기보다 높거나 같은 연산자들을 모두 postfix에 출력하고 자신은 스택에 push
                while (!s2.isEmpty() && priority(s2.getTop()) >= priority(buffer[i])) {
                    ch = s2.pop();
                    postfix[j++] = ch;
                    postfix[j++] = ' ';
                }
                s2.push(buffer[i]);
                i++;
            }
        }
    }
    while (!s2.isEmpty()) { //수식이 끝나면 stack내용 pop
        ch = s2.pop();
        postfix[j++] = ch;
        postfix[j++] = ' ';
    }
    postfix[j] = NULL;


    cout << "postfix : " << postfix << endl;
}

void Calculator::result() {
    int i = 0, k;
    char token[5];
    int num, number, num1, num2;
    char ch;

    while (postfix[i] != NULL) {
        if (isdigit(postfix[i])) {//postfix의 값이 숫자면 반환(true), 연산자 이면(false)
            k = 0;
            while (isdigit(postfix[i]))
                token[k++] = postfix[i++];
            token[k] = NULL;
            num = atoi(token); //문자열을 int형으로 변환
            s1.push(num);
        }
        else if (postfix[i] == ' ')
            i++;
        else { //연산자는 스택에서 두 수를 pop하여 연산하고 다시 push
            ch = postfix[i++];
            num1 = s1.pop();
            num2 = s1.pop();
            if (ch == '+') number = num2 + num1;
            else if (ch == '-') number = num2 - num1;
            else if (ch == '*') number = num2 * num1;
            else if (ch == '/') number = num2 / num1;
            else if (ch == '/' && num1 == 0) number = 0;
            s1.push(number);
        }
        i++;
    }
    if (ch == '(')
        cout << "result = " << "괄호의 짝이 맞지 않습니다" << endl;
    else
        cout << "result = " << s1.pop() << endl;
}

void main()
{
    char infix[80];
    char infix1[40] = { '(','(','(','5','-','7',')','/','2','+','2',')','*',
     '(','3','*','2','/','6', ')','-','3','*','3',')' };
    char infix3[40] = { '(','(','(','5','-','7',')','/','2','+','2',')','*',
     '(','3','*','2','/','6','-','3','*','3',')' };
        
    Calculator myInput;

    //무한 루프 - 값 입력 받아 수행
    while (1) {
        cout << "중위연산자(infix) 수식 입력" << endl;
        cout << "infix : ";
        cin >> infix;
        myInput.calculate(infix);
        cout << "_____________________________________________________________" << endl << endl;
    }
}