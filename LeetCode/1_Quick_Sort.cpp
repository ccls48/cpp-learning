#include<iostream>
#include<vector>
using namespace std;
void change(vector<int>&num,int left,int right);
int main()
{
    vector<int>num;
    int n=0;
    cout<<"请输入一串数字(输入114514终止):";
    while(cin>>n&&n!=114514)
    {
        cout<<n<<" ";
        num.push_back(n);
    }
    int l=0,r=num.size()-1;
    return 0;
}
void change( vector<int>&num,int left,int right)
{
    int l=left,r=right;
    int criterion=num[(left+right)];
    while(left<=right)
    {
        if(num[left]>num[right])
        {
            int temp=num[left];
            num[left]=num[right];
            num[right]=temp;
            left++;
            right--;
        }
    }
    change(num,l,left);
    change(num,right,r);
}
