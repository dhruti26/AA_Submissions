//Contributor : CE026 Dhruti Desai
//Time Complexity of Algorithm is O(Klog(n))
#include<bits/stdc++.h>
# define ll long long int
using namespace std;

ll gcd(ll a,ll b){
	ll r;
	while(b>0){
    	r=a%b;
    	a=b;
    	b=r;
	}
	return a;
}
ll power(ll a, ll x,ll n){
	ll res=1;
    a=a%n;  //if a>=n 
    //we want a^x % n
    while(x>0){
        if(x%2 == 1){
            //if odd number
            res=(res*a)%n;
        }
        x=x>>1;  // x/2
        a=(a*a)%n;
    }
	return res;
}
bool isPrime(ll n){
	if(n<=1 || n==4) return false;
	//checked for n=1,2,3,4
	if(n<=3) return true;   
    
	int k=20;
	while(k>0){
    	//to generate random number where p=2 and r=n-2 in range(p,r) =>rand()%(r-p+1)
    	ll a = 2 + rand()%(n-3);
   	 
    	//tc: log(a*b)
    	if(gcd(a,n) != 1) {
        	//some other factor exists not a prime number
        	return false;
    	}
   	 
    	if(power(a,n-1,n) != 1){
        	//checking condition a^n-1%n != 1 , it is not prime number
        	return false;
    	}
    	k--;
	}
  	return true;
}
int main() {
	cout<<"Enter any number to check it is prime or not :"<<endl;
	ll n;
	cin>>n;
	if(n!=2 && (n%2==0)) {
    	//even number not prime
    	cout<<n<<" is a not Prime Number"<<endl;
	}
	else if(isPrime(n)){
    	cout<<n<<" is a Prime Number"<<endl;
	}else{
     	cout<<n<<" is a not Prime Number"<<endl;
	}

	return 0;
}
