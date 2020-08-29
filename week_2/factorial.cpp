using namespace std;

int Factorial(int num){
    if(num<=1) return 1;
    else{
        for(int i=num-1;i>1;--i){
            num*=i;
        }
    }
    return num;
}
