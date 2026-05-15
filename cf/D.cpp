#include<iostream>
#include<iomanip>
using namespace std;
struct MyComplex{
    double Real;
    double Imaginary;
    MyComplex(){}
    MyComplex(double a,double b){
        this->Real=a;
        this->Imaginary=b;
    }
};
void cprint(double a,double b){
    if(a==0&&b==0){
            cout<<"0";
        }else{
            if(a!=0){
                cout<<a;
                if(b>0){
                    cout<<"+";
                }
            }
            if(b!=0){
                cout<<b<<"i";
            }
        }
}
void rprint(MyComplex num1, MyComplex num2, double res1, double res2, char op){
    cout<<"The result of (";
    cprint(num1.Real,num1.Imaginary);
    cout<<")"<<op<<"(";
    cprint(num2.Real,num2.Imaginary);
    cout<<") is ";
    cprint(res1,res2);
    cout<<"\n";
}
class Calculator{
    protected:
    MyComplex num1;
    MyComplex num2;
    public:
    Calculator(){}
    void set(MyComplex n1, MyComplex n2){
        this->num1=n1;
        this->num2=n2;
    }
    virtual void getResult()=0;
};
class AdditionCal: public Calculator{
    public:
    void getResult(){
        double res1=num1.Real+num2.Real;
        double res2=num1.Imaginary+num2.Imaginary;
        rprint(num1,num2,res1,res2,'+');
    }
};
class SubstractionCal: public Calculator{
    public:
    void getResult(){
        double res1=num1.Real-num2.Real;
        double res2=num1.Imaginary-num2.Imaginary;
        rprint(num1,num2,res1,res2,'-');
    }
};
class MultiplyCal: public Calculator{
    public:
    void getResult(){
        double res1=num1.Real*num2.Real-num1.Imaginary*num2.Imaginary;
        double res2=num1.Imaginary*num2.Real+num2.Imaginary*num1.Real;
        rprint(num1,num2,res1,res2,'*');  
    }
};
class DivisionCal: public Calculator{
    public:
    void getResult(){
        double res1;
        double res2;
        if(num2.Real==0&&num2.Imaginary==0){
            cout<<"Error: Division by zero!\n";
            res1=0;
            res2=0;
        }else{
            res1=(num1.Real*num2.Real+num1.Imaginary*num2.Imaginary)/(num2.Real*num2.Real+num2.Imaginary*num2.Imaginary);
            res2=(num1.Imaginary*num2.Real-num2.Imaginary*num1.Real)/(num2.Real*num2.Real+num2.Imaginary*num2.Imaginary);
        }
        rprint(num1,num2,res1,res2,'/');
    }
};
int main(){
    // cout<<fixed<<setprecision(6);
    cout<<"Input the first operand:\n";
    double a,b;
    cin>>a>>b;
    MyComplex num1(a,b);
    cout<<"Input the second operand:\n";
    double c,d;
    cin>>c>>d;
    MyComplex num2(c,d);
    Calculator *Cal;
    Cal=new AdditionCal();
    Cal->set(num1,num2);
    Cal->getResult();

    Cal=new SubstractionCal();
    Cal->set(num1,num2);
    Cal->getResult();

    Cal=new MultiplyCal();
    Cal->set(num1,num2);
    Cal->getResult();

    Cal=new DivisionCal();
    Cal->set(num1,num2);
    Cal->getResult();
}