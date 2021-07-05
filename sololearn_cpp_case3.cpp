#include <iostream>
using namespace std;

bool isPalindrome(long long x) {
    //complete the function
    int arr[30];
    long long dec=10;
    int a=0,b=0;
    while(1){
        arr[a] = (x%dec)/(dec/10);
        if(x/dec == 0){
            break;
        }
        a++;
        dec *=10;
    }
    while(1){
        if(b>=a){
            return 1;
        }
        if(arr[b]!=arr[a]){
            return 0;
        }
        b++;
        a--;
    }
}

int main() {
    int n;
    cin >>n;

    if(isPalindrome(n)) {
        cout <<n<<" is a palindrome";
    }
    else {
        cout << n<<" is NOT a palindrome";
    }
    return 0;
}
