#include <iostream>
#include <ctype.h> 
#include <stdlib.h>
using namespace std;

//������ ������ �ٲٱ� ���� ����
class CharStack {
private: //class ���� ����
    int stack[100];
    int top;
public: // ����/�ܺ� ���� ����
    CharStack() { top = -1; }
    void push(char val) { stack[++top] = val; }  //stack �� val �� �ֱ�
    char pop() { return stack[top--]; }   //stack �� �� ����
    int isEmpty() { return top == -1; }
    int isFull() { return top == 99; }
    char getTop() { return stack[top]; }
};

//intStack  -- postfix result �������� stack
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

//calculator class ����
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

int Calculator::priority(char ch) { // �����ڿ� �켱������ ������ �ش�
    if (ch == ')')
        return 4;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 1;
}

void Calculator::calculate(char infix[]) { // ���� ǥ����� ������� buffer[i]�� �־��ش�
    for (int i = 0; i < 80; i++)
        buffer[i] = infix[i];
    infixTopostfix();
    result();
}

void Calculator::infixTopostfix() { //���� ǥ��� -> ���� ǥ���
    int i = 0, j = 0;
    char ch;

    while (buffer[i] != NULL) {
        if (buffer[i] == ' ') //�����̸� ���� ���۷� �Ѿ��
            i++;
        else if (isdigit(buffer[i])) { //buffer[i]�� ���� ���ڸ� postfix�� ���
            while (isdigit(buffer[i]))
                postfix[j++] = buffer[i++];
            postfix[j++] = ' ';
        }

        else if (buffer[i] == '(') { //���� ��ȣ�� ���ÿ� �־��ش�
            s2.push(buffer[i]);
            i++;
        }
        else if (buffer[i] == ')') { //��ħ ��ȣ�� �߰� �Ҷ����� �����ڵ��� pop
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
            else { //���ÿ� �ִ� �ڱ⺸�� ���ų� ���� �����ڵ��� ��� postfix�� ����ϰ� �ڽ��� ���ÿ� push
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
    while (!s2.isEmpty()) { //������ ������ stack���� pop
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
        if (isdigit(postfix[i])) {//postfix�� ���� ���ڸ� ��ȯ(true), ������ �̸�(false)
            k = 0;
            while (isdigit(postfix[i]))
                token[k++] = postfix[i++];
            token[k] = NULL;
            num = atoi(token); //���ڿ��� int������ ��ȯ
            s1.push(num);
        }
        else if (postfix[i] == ' ')
            i++;
        else { //�����ڴ� ���ÿ��� �� ���� pop�Ͽ� �����ϰ� �ٽ� push
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
        cout << "result = " << "��ȣ�� ¦�� ���� �ʽ��ϴ�" << endl;
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

    //���� ���� - �� �Է� �޾� ����
    while (1) {
        cout << "����������(infix) ���� �Է�" << endl;
        cout << "infix : ";
        cin >> infix;
        myInput.calculate(infix);
        cout << "_____________________________________________________________" << endl << endl;
    }
}