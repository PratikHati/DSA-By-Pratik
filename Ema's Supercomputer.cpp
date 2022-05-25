#include<vector>
#include<string>
using namespace std;
int twoPluses(vector<string> grid) {
  int n = grid.size();
  int m = grid[0].size();
  

  int ans = INT_MIN;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

        
        int R = 0;
        while(i+R <n && j+R <m &&i-R>=0 && j-R>=0 && grid[i+R][j]== 'G' && grid[i-R][j]== 'G' && grid[i][j-R]== 'G' && grid[i][j+R]== 'G'){
          
          grid[i+R][j]= grid[i-R][j]= grid[i][j-R]= grid[i][j+R]= 'x';
          //find second square
          for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
              
              int r= 0;
               while(x+r <n && y+r <m &&x-r>=0 && y-r>=0 && grid[x+r][y]== 'G' && grid[x-r][y]== 'G' && grid[x][y-r]== 'G' && grid[x][y+r]== 'G'){
                 
                 int temp1 = 4*r +1;
                 int temp2 = 4*R +1;
                 ans = max(ans, temp1*temp2);
                 r++;
               }
            }
          }
          R++;
        }
        R=0;
        //redo G again
        while (i + R < n && j + R < m && i - R >= 0 && j - R >= 0 && 
                grid[i + R][j] == 'x' && grid[i - R][j] == 'x' && grid[i][j - R] == 'x' && grid[i][j + R] == 'x') {

                grid[i + R][j] = grid[i - R][j] = grid[i][j - R] = grid[i][j + R] = 'G';
                R++;
            }
       
      
    }
    
  }

  return ans;
}

