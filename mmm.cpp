#include<iostream>
using namespace std;
int main()
{
    int item,vi,wi;
    int maximum;
    int i,j;

    cin>>item;
    int profit[item];
    int weight[item];

    for(i=0;i<item;i++)
    {
        cin>>profit[i]>>weight[i];

    }
    int capacity;
    cin>>capacity;

    int row=item+1;
    int col=item+1;
    int array[row][col];

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            array[i][j]=0;
        }

    }

     for(i=0;i<row;i++){
        for(j=0;j<col;j++){
                if (i==0||j==0){
            array[i][j]=0;
        }


     else if (weight[i-1]>j){
        array[i][j]=array[i-1][j];

     }
     else {
        maximum=max (profit[i-1]+array[i-1][j-weight[i-1]],array[i-1][j]);
        maximum=array[i][j];
     }

}

     }
   cout<<"Maximum Value="<<array[item][capacity];
}