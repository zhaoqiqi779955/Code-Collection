#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
void changPos(int *array, int left, int right, int pos, int n){
    while(true){
        if(left<= n&&right> n){
            if(array[left]< array[pos]){
                int temp= array[left];
                array[left]= array[pos];
                array[pos]= temp;
            }
             
            break;
        }
        else if(left> n&&right> n)
           break;
        else{
     
            if(array[pos]> array[left]&&array[pos]<= array[right]){
                   int temp= array[pos];
                   array[pos]= array[left];
                   array[left]= temp;
                    
                   pos= left;
                   left= pos* 2;
                   right= pos* 2+ 1;
            }
            else if(array[pos]> array[right]&&array[pos]<= array[left]){
                int temp= array[pos];
                array[pos]= array[right];
                array[right]= temp;
                 
                pos= right;
                left= pos* 2;
                right=  pos* 2+ 1;
            }
            else if(array[pos]> array[right]&&array[pos]> array[left]){
                int min= array[left];
                int po= left;
                if(array[left]> array[right]){
                    min= array[right];
                    po= right;
                }
                 
                int temp= array[pos];
                array[pos]= min;
                array[po]= temp;
                 
                pos= po;
                left= pos* 2;
                right= pos* 2+ 1;    
            }
            else
                  break;
             
        }
         
    }
}
int main(){
    int n;
    cin>>n;
    int *array= new int[n+ 5];
    for(int i= 1; i<= n; i++)
       cin>>array[i];
     
    int pos= n/2;
    int nn= n;
    while(pos>= 1){
        int child_r= pos* 2;
        int child_l= pos* 2+ 1;
        changPos(array, child_r, child_l, pos, n);
        nn-= 2;
        pos= nn/2;
    } 
    print(array, n);
       
   int end= n;
   while(end> 1){
      int temp= array[1];
      array[1]= array[end];
      array[end]= temp;
       
      end--;
      changPos(array, 2, 3, 1, end);
      print(array, n);
   }
   return 0;
}
