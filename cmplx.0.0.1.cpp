#include <iostream>
using namespace std;

struct complex_t {
    float real;
    float imag;
};

complex_t add(complex_t lhs, complex_t rhs){
    complex_t res;
    res.real=lhs.real+rhs.real;
    res.imag=lhs.imag+rhs.imag;

    return res;
}
complex_t sub(complex_t lhs, complex_t rhs){
    complex_t res;
    res.real=lhs.real-rhs.real;
    res.imag=lhs.imag-rhs.imag;

    return res;
}
complex_t mul(complex_t lhs, complex_t rhs){
    complex_t res;
    res.real=lhs.real*rhs.real-lhs.imag*rhs.imag;
    res.imag=lhs.real*rhs.imag+rhs.real*lhs.imag;

    return res;
}
complex_t div(complex_t lhs, complex_t rhs){
    complex_t res;
    res.real=(lhs.real*rhs.real+lhs.imag*rhs.imag)/(rhs.real*rhs.real+rhs.imag*rhs.imag);

    res.imag=(lhs.imag*rhs.real-lhs.real*rhs.imag)/(rhs.real*rhs.real+rhs.imag*rhs.imag);

    return res;
}


istream & read( istream & stream, complex_t & complex ){
    char op1,op2,op3;
    float real;
    float imag;
    if (stream>>op1 && op1=='(' && stream>>real && stream>>op2 && op2 == ',' && stream>>imag && stream>>op3 && op3 == ')') {
        complex.real = real;
        complex.imag = imag;
    }
    else {
        stream.setstate(std::ios::failbit);
    }

    return stream;

}
ostream & write( ostream & stream, complex_t complex ){
    return stream<<'('<<complex.real<<','<<complex.imag<<')'<<endl;
}

int main() {

    complex_t complex1, complex2, complex_res;
    char op;

    if(read(cin,complex1)&&(cin>>op)&&read(cin,complex2)){

        switch(op){
            case '+':
                write(cout,add(complex1,complex2));
                break;
            case '-':
                write(cout,sub(complex1,complex2));
                break;
            case '*':
                write(cout,mul(complex1,complex2));
                break;
            case '/':
                write(cout,div(complex1,complex2));
                break;
            default:
                cout<<'\n'<<"An error has occured while reading input data";
                break;
        }
    }
    else {
        cout<<endl<<"An error has occured while reading input data";
    }

    return 0;
}
