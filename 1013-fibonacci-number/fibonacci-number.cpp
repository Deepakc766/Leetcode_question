class Solution {
public:
int recfib(int n){
    if(n==0 || n==1)return n;
    int ans=recfib(n-1)+recfib(n-2);
    return ans;
}
    int fib(int n) {
        return recfib(n);
    }
};