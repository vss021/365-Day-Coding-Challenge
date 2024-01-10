#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
      int RESULT_HAI=2;  

        if(a==e){  
            int left_will =min(b,f);  
            int right_will=max(b,f);  
            if(c!=e){RESULT_HAI=1;}  
            else if(d<left_will  or d>right_will){RESULT_HAI=1;}  
        }  
        if(b==f){  
            int left_will =min(a,e);  
            int right_will=max(a,e);  
            if(d!=b){
                RESULT_HAI=1;
                }  
            else if(c<left_will  or c>right_will){RESULT_HAI=1;}  
        }  
        if((c+d)%2!=(e+f)%2){return RESULT_HAI;}  
        if(e-c==f-d){  
            int fo_will =0;  
            int cur_x=c;  
            int cur_y=d;  
            int add_ =0;  
            if(c<e){add_ =1;}  
            else{add_ =-1;}  
            while(true){  
                cur_x=cur_x+add_ ;  
                cur_y=cur_y+add_ ;  
                if(cur_x==a and cur_y==b){fo_will =1;break;}  
                if(cur_x==e and cur_y==f){break;}  
            }  
            if(fo_will ==0){RESULT_HAI=1;}  
        }  
        if(c-e==f-d){  
               
            int fo_will =0;  
               
            int cur_x=c;  
            int cur_y=d;  
            int add_ =0;  
            if(c<e){add_ =1;}  
            else{add_ =-1;}  
            while(true){  
                cur_x=cur_x+add_ ;  
                cur_y=cur_y-add_ ;  
                  
                if(cur_x==a and cur_y==b){fo_will =1;break;}  
                if(cur_x==e and cur_y==f){break;}  
            }  
            if(fo_will ==0){RESULT_HAI=1;}  
        }  
          
        return RESULT_HAI;  
}

int main() {
    // Example usage
    int result = minMovesToCaptureTheQueen(1, 1, 3, 3, 2, 2);
    cout << "Minimum moves to capture the queen: " << result << endl;

    return 0;
}
