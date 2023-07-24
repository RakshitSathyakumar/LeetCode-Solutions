class Solution {
public:
    double binpow(double a, int b) {
    if (b == 0)
        return 1;
    double res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
    double myPow(double x, int n) {
        if(n<0){
            x=1/x;
        }
        return binpow(x,n);
    }
};