#include<bits/stdc++.h>     
                             //   // Question is find minimum edit distance to convert one string into another just by doing 3 operations 
                              //   1.. Insert  2. Remove   3.. Replace
                              
                              // SOLVING IT WITH THE HELP OF DYANAMIC PROGRAMING
                              //      1.T.C =O(n*m)      W.C. =O(N*N)
                            //        2.S.C=O(n*m)

using namespace std;


int minechanges(int i,int j,string s1,string s2,vector<vector<int> > &dist)
{
	if(i==s1.length())     // base case if one string is iterated completly then return lenth of another string - current i||j
	return s2.length()-j;   // // This will tell you remaining operation we have to do as one string reached to its end 
	
	if(j==s2.length())
	return s1.length()-i;
	
	if(dist[i][j]!=-1)     // If any subproblem already been covered just return the value don't need to calculate it again thats advantage of DYNAMIC PROGRAMING
	return dist[i][j];
	
	if(s1[i]==s2[j])                      //    // if both are matched iterate both and return  and also stre in Dist Dp array
	return dist[i][j]=minechanges(i+1,j+1,s1,s2,dist);
	
	else                                      // If not macthed above condition we are checking each case
	{  
		int insert=1+minechanges(i,j+1,s1,s2,dist); //while inserting the element & take recursively (Here only j moves cz i is at its own place just assume s2[j] inserted before i)
		int remove=1+minechanges(i+1,j,s1,s2,dist);  //  Here  same  while removing the element and take recursively(here element at i is removed and i incremented)
		int replace=1+minechanges(i+1,j+1,s1,s2,dist);  // // Here same while replacing the element and take recursively (here i is replaced by j so both i& j are incremented)
		
		dist[i][j]=min(insert,min(remove,replace)); // return the minimum of these three and store it into the dist DP ARRAY
	}	
	
}




int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	int n=s1.length();
	int m=s2.length();
	
	vector<vector<int> >dist(n,vector<int>(m,-1));   // 2d vetor of size (n*m) that decide SPACE COMPLEXITY
	
	int mine=minechanges(0,0,s1,s2,dist);
	
	cout<<mine<<endl;
}
