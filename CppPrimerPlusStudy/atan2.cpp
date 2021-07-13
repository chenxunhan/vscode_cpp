#include<cmath>
#include<cstdio>

int main(){
	const double Rad_to_deg=57.29577951;
	double a=2,b=sqrt(12);
	printf("%lf",atan2(b,a)*Rad_to_deg);
	return 0;
}