#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int n;
int a[100001],st[200001];
void segmenttree(int si,int ss,int se)  ////// SEGMENT TREE IMPLEMENTATION
{
    if(ss==se)                        // if start and end is same store the valu ein segment tree
    {st[si]=a[ss];
    return ;}
    
    int md=(ss+se)/2;                  
    
    segmenttree(si*2,ss,md);           // move to left subtree
    segmenttree(si*2+1,md+1,se);       // move to right subtree
    
    st[si]=min(st[si*2],st[si*2+1]);   // store the min value youe got from left and right subtree
     
}

int query(int si,int ss,int se,int qs,int qe)   // function to perform query on range  qs- start query qe-end query
{ 
    if( (se<qs) || (ss>qe) )    // if ss or se completly outise the query  return MAX as we want min so it will not impact on result
    {
        return INT_MAX;
    }
     if((ss>=qs) && (se<=qe))   // if ss and se completly inside the query then return the value at particular segment index
     return st[si];
     
     int md=(ss+se)/2;
     
     int l=query(si,ss,md,qs,qe);   // move to the left part and find min
     int r=query(si,md+1,se,qs,qe);    // move to right part and find min
     
     return min(l,r);    // return min (left,right) subtree
     
     
}
    



int main() {

long int n,i,q;
cin>>n;

for(i=1;i<=n;i++)
cin>>a[i];

cin>>q;

segmenttree(1,1,n);   // building the segment tree

for(i=0;i<q;i++)
{
    int qs,qe;
    cin>>qs>>qe;
    
    int ans=query(1,1,n,qs,qe);   // for every query calling the function
    cout<<ans<<endl;
}

	return 0;
}
