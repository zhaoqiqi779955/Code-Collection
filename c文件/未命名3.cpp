#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

void tansform(int *ary, int left, int right, int pos, int n){
    while(true){
        if(left<= n&&right> n){
            if(ary[left]< ary[pos]){
                int temp= ary[left];
                ary[left]= ary[pos];
                ary[pos]= temp;
            }
             
            break;
        }
        else if(left> n&&right> n)
           break;
        else{
     
            if(ary[pos]> ary[left]&&ary[pos]<= ary[right]){
                   int temp= ary[pos];
                   ary[pos]= ary[left];
                   ary[left]= temp;
                    
                   pos= left;
                   left= pos* 2;
                   right= pos* 2+ 1;
            }
            else if(ary[pos]> ary[right]&&ary[pos]<= ary[left]){
                int temp= ary[pos];
                ary[pos]= ary[right];
                ary[right]= temp;
                 
                pos= right;
                left= pos* 2;
                right=  pos* 2+ 1;
            }
            else if(ary[pos]> ary[right]&&ary[pos]> ary[left]){
                int min= ary[left];
                int po= left;
                if(ary[left]> ary[right]){
                    min= ary[right];
                    po= right;
                }
                 
                int temp= ary[pos];
                ary[pos]= min;
                ary[po]= temp;
                 
                pos= po;
                left= pos* 2;
                right= pos* 2+ 1;    
            }
            else
                  break;
             
        }
         
    }
}


void show(int a[],int n)
{
	cout<<n<<" ";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
    int n;
    
    cin>>n;
    int *ary= new int[n+ 5];
    for(int i= 1; i<= n; i++)
       cin>>ary[i];
     
    int pos= n/2;
    int nn= n;
    while(pos>= 1){
        int child_r= pos* 2;
        int child_l= pos* 2+ 1;
        tansform(ary, child_r, child_l, pos, n);
        nn-= 2;
        pos= nn/2;
    } 
    show(ary, n);
       
   int end= n;
   while(end> 1){
      int temp= ary[1];
      ary[1]= ary[end];
      ary[end]= temp;
       
      end--;
      tansform(ary, 2, 3, 1, end);
      show(ary, n);
   }
   return 0;
}
