#include <iostream>
#include <cmath>
using namespace std;
int UCLN(int x, int y){
    while (y != 0) {
        int du=x%y;
        x=y;
        y=du;
    }
    return abs(x);
}
void rutgonPhanSo(int &a, int &b){
    if (b==0){
        return;
    }
    int ucln=UCLN(a, b); 
    
    a/=ucln;
    b/=ucln;
    if (b<0) {
        a=-a;
        b=-b;
    }
}
int main(){
    int a,b;
    cin >> a >> b;
    if (b==0){
        cout << "Mau so khong hop le" << endl;
        return 1;
    }
    cout << "Phan so ban dau: " << a << "/" << b << endl;
    rutgonPhanSo(a, b);
    cout << "Phan so sau khi rut gon: " << a << "/" << b << endl;
    return 0;
}
// độ phức tạp thời gian O(min(|a|, |b|))
// độ phức tạp bộ nhớ:O(1)
