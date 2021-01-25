#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;
/**
 * 有理数
 **/
struct Fraction{  
    LL  up,down;
};
/**
 * 求最大公约数
 **/
LL gcd( LL a , LL b )
{
   if( b == 0 ) return a;
   else return gcd( b, a%b );
}
/**
 * 有理数化简
 **/
Fraction reduction(Fraction res){
    if(res.down < 0) {
       res.up = -res.up;
       res.down = -res.down;
   }
    if(res.up == 0){
       res.down = 1;
   }else{
     int d = gcd(abs(res.up),abs(res.down));
     res.up /= d;
     res.down /= d;
    }
  return res;
 }
/**
 * 有理数加法
 **/
Fraction add( Fraction f1,Fraction f2){
  Fraction res;
  res.up = f1.up * f2.down+f2.up * f1.down;//分数和的分子
  res.down = f1.down * f2.down;            //分数和的分母
  return reduction(res);
}
/**
 * 有理数减法
 **/
Fraction minu(Fraction f1,Fraction f2){
  Fraction res;
  res.up = f1.up*f2.down - f2.up*f1.down;//分数差的分子
  res.down = f1.down * f2.down;            //分数差的分母
  return reduction(res);
}
/**
 * 有理数乘法
 **/
Fraction multi(Fraction f1,Fraction f2)
{
  Fraction res;
  res.up = f1.up * f2.up;      //分数乘积的分子
  res.down = f1.down * f2.down;//分数乘积的分母
  return reduction(res);
}
/**
 * 有理数除法
 **/
Fraction divide( Fraction f1,Fraction f2){
     Fraction res;
     res.up = f1.up * f2.down;   //分数商的分子
     res.down = f1.down * f2.up; //分数商的分母
     return reduction(res);
  
}
/**
 * 输出结果
 **/
void showResult(Fraction r){
   r = reduction(r);
   if(r.up<0) printf("(");
   if(r.down==1) printf("%lld",r.up);
   else if(abs(r.up)>r.down) printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
        else  printf("%lld/%lld",r.up,r.down);
   if(r.up<0) printf(")");
}

int main()
{
	Fraction num1,num2;
	scanf("%lld/%lld%lld/%lld",&num1.up,&num1.down,&num2.up,&num2.down);
	//加法运算 
	showResult(num1);
	printf(" + ");
	showResult(num2);
	printf(" = ");
	showResult(add(num1,num2)); 
	printf("\n");
	//减法运算
	showResult(num1);
	printf(" - "); 
	showResult(num2);
	printf(" = ");
	showResult(minu(num1,num2));
	printf("\n");
	//乘法运算
	showResult(num1);
	printf(" * ");
	showResult(num2);
	printf(" = ");
	showResult(multi(num1,num2));
	printf("\n");
	//除法运算
	showResult(num1);
	printf(" / ");
	showResult(num2);
	printf(" = ");
	if(num2.up == 0) printf("Inf");
	else showResult(divide(num1,num2)); 
	return 0;
}



