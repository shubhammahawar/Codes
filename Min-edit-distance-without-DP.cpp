#include<bits/stdc++.h>
                                 // Question is find minimum edit distance to convert one string into another just by doing 3 operations 
                              //   1.. Insert  2. Remove   3.. Replace
                              
                              // In this there are many overlapping subproblems came which makes T.C as 0(2^length of string) 
                            
                                 
using namespace std;

int minechanges(int i,int j,string s1,string s2)    
{
	if(i==s1.length())     // base case if one string is iterated completly then return lenth of another string - current i||j
	return s2.length()-j;   // This will tell you remaining operation we have to do as one string reached to its end 
	
	if(j==s2.length())
	return s1.length()-i;
	
	if(s1[i]==s2[j])            // if both are matched iterate both and return 
	return minechanges(i+1,j+1,s1,s2);
	
	
	else                              // Here we are checking in each case
	{
		int insert=1+minechanges(i,j+1,s1,s2);//while inserting the element & take recursively (Here only j moves cz i is at its own place just assume s2[j] inserted before i)
		int remove=1+minechanges(i+1,j,s1,s2);    // Here  same  while removing the element and take recursively(here element at i is removed and i incremented)
		int replace=1+minechanges(i+1,j+1,s1,s2); // Here same while replacing the element and take recursively (here i is replaced by j so both i& j are incremented)
		
		return (min(insert,min(remove,replace)));   // return the minimum of these three
		
	}
	
}





int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	int l1=s1.length();
	int l2=s2.length();
	
	int mine=minechanges(0,0,s1,s2);  // calling the function
	
	cout<<mine<<endl;
	
	return 0;
	
	
	
}
