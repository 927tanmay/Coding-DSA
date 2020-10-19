int power(int a, int n){
    int res=1;
    while(n){
        if(n%2==1)
        {
            res=res*a;
            n--;
        }
        a=a*a;
        n=n/2;
    }
    return res;
}