#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const double eps=1e-154,inf=1e154;

bool checkNum(double x){
	return x>inf||x<-inf;
}

int main(){
	double a,b,c;
	setlocale(LC_ALL,"Russian");
	//do{
		cout<<"������� �����, �� ����������� �� ������ "<<inf<<". ��������� ��������� ����� � ���������, �� ����������� "<<eps<<".\n";
		cin>>a>>b>>c;
	//}while(checkNum(a)||checkNum(b)||checkNum(c));
	if(a<eps&&a>-eps){
		a=0;
	}
	if(b<eps&&b>-eps){
		b=0;
	}
	if(c<eps&&c>-eps){
		c=0;
	}
	if(a==0){
		if(b==0){
			if(c==0){
				cout<<"����� �����.";
			}else{
				cout<<"��� �������.";
			}
		}else{
			cout<<-c/b;
		}
	}else{
		double D=b*b-4*a*c;
		if(D<eps&&D>-eps){
			D=0;
		}
		if(D<0){
			cout<<"��� �������.";
		}else if(D==0){
			cout<<-b/(2*a);
		}else{
			cout<<(-b-sqrt(D))/(2*a)<<" "<<(-b+sqrt(D))/(2*a);
		}
	}
	return 0;
}
