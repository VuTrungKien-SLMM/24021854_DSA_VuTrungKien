#include <iostream>
using namespace std;
int tinhTong(int n, int m, int **a) {
    int sum = 0;
    for (int i=0;i<n;i++) {
        for (int j=0; j<m;j++) {
            sum+=a[i][j]; 
        }
    }
    return sum;
}

void xoaDong(int &n, int m, int i, int **a) {
    if (i<0 || i >= n) {
        cout << "Dong xoa khong hop le!" << endl;
        return;
    }
    for (int p=i;p<n-1;p++) {
        for (int q=0;q<m;q++) {
            a[p][q] = a[p+1][q]; 
        }
    }
    n--; 
}

void printArray(int n, int m, int **a){
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Nhap kich thuoc N va M cua mang: " << endl;
    cin >> n >> m;
    int temp=n;
    int **a = new int*[n];
    for (int i=0;i<n;i++) {
        a[i] = new int[m]; 
    }
    cout << "Nhap cac phan tu cua mang: " << endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> a[i][j]; 
        }
    }
    cout << "Tong cac phan tu: " << tinhTong(n,m,a) << endl;
    int i;
    cout << "Nhap dong thu i can xoa: " << endl;
    cin >> i;
    xoaDong(n,m,i,a);
    cout << "Mang sau khi xoa: " << endl;
    printArray(n, m, a);
    
    for (int i=0;i<temp;i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
//Độ phức tạp thời gian: O(N x M)
//Độ phức tạp bộ nhớ: O(N x M)
