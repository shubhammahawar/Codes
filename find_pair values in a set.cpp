#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int,int>pairs;
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,val,val1,j;
	    cin>>n;
	    
	    set<pairs>s;
	    
	    for(i=0;i<3;i++)
	    {
	        cin>>val;
	        
	        for(j=0;j<2;j++)
	        {
	            cin>>val1;
	            pairs x=make_pair(val,val1);
	          
	           
	            auto it=s.find(x);
	            if(it!=s.end())
	            {cout<<it->first<<" "<<it->second<<" "<<endl;}
	            else
	            {
	                s.insert(x);
	            } 
	           // cout<<it->first<<" "<<it->second<<" ";
	        }
	    }
	}
	return 0;
}
	    
	    
