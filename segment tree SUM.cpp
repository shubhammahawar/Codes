
  
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int a[100001],st[200001];

void buildtree(int si,int ss,int se)
{
    if(ss==se)
    {
        st[si]=a[ss];
        return ;
    }
    
    int md=(ss+se)/2;
    buildtree(si*2,ss,md);
    buildtree(si*2+1,md+1,se);
    
    st[si]=st[si*2]+st[si*2+1];
    
    
}

int range(int si,int ss,int se,int qs,int qe)
{
 
    if(se<qs || ss>qe)
        return 0;
    
    if(ss>=qs && se<=qe)
        return st[si];
    
    int md=(ss+se)/2;
    
    int l=    range(si*2,ss,md,qs,qe);

     int r=   range(si*2+1,md+1,se,qs,qe);
    
    return (l+r);
    
    
}


void updateval(int si,int ss,int se,int qi)
{
    if(ss==se)
    {
        st[si]=a[qi];
        return;
    }
    int md=(ss+se)/2;
    
    if(qi<=md)
        updateval(si*2,ss,md,qi);
    else
        updateval(si*2+1,md+1,se,qi);
    
    st[si]=st[si*2]+st[si*2+1];
    
    
    
}



int main() {

long int n,i,q;
cin>>n;

for(i=1;i<=n;i++)
cin>>a[i];

cin>>q;

buildtree(1,1,n);   // building the segment tree

for(i=0;i<q;i++)
{
    int qs,qe;
    char ch;
    cin>>ch;
   
    
    if(ch=='Q')   // If its a query to find in a range
    {
         cin>>qs>>qe;
    int ans=range(1,1,n,qs,qe);   // for every query calling the function
    
    cout<<ans<<endl;
    }
    else if(ch=='U')  // If its a updation to update at particular position
    {
       int pos,val;
       cin>>pos>>val;
      
       a[pos]=val;
     
        updateval(1,1,n,pos);
    }
    
}

	return 0;
}

