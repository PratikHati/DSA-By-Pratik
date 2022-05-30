class Solution {
public:
    bool isVerticalLTR(vector<vector<char>> &board, string word,int i,int j){
        
        int r = board.size();
        int c = board[0].size();
        int x = word.length();
        
        if(i+x <r && board[i+x][j] != '#'){
            return false;
        }
        
        if(i-1 >= 0 && board[i-1][j] != '#'){
            return false;
        }
        
        
        
        for(int p=0;p<x;p++){
            
            if(i+p >= r)   {
                return false;
            } 
            
            if(board[i+p][j] == '#'){
                return false;
            }
            
            if(board[i+p][j] == ' '){
                continue;
            }
            
            if(board[i+p][j] != ' ' || board[i+p][j] != '#'){
                
                if(board[i+p][j] != word[p]){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    bool isVerticalRTL(vector<vector<char>> &board, string word,int i,int j){
        
        int r = board.size();
        int c = board[0].size();
        int x = word.length();
        
        if(i-x >=0 && board[i-x][j] != '#'){
            return false;
        }
        
        if(i+1 <r && board[i+1][j] != '#'){
            return false;
        }
        
        
        
        for(int p=0;p<x;p++){
            
            if(i-p < 0)   {
                return false;
            } 
            
            if(board[i-p][j] == '#'){
                return false;
            }
            
            if(board[i-p][j] == ' '){
                continue;
            }
            
            if(board[i-p][j] != ' ' || board[i-p][j] != '#'){
                
                if(board[i-p][j] != word[p]){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    bool isHorizontalLTR(vector<vector<char>> &board, string word,int i,int j){
        
        int r = board.size();
        int c = board[0].size();
        int x = word.length();
        
        if(j+x <c && board[i][j+x] != '#'){
            return false;
        }
        
        if(j-1 >= 0 && board[i][j-1] != '#'){
            return false;
        }
        
        
        
        for(int p=0;p<x;p++){
            if(j+p >= c)   {
                return false;
            } 
            
            if(board[i][j+p] == '#'){
                return false;
            }
            
            if(board[i][j+p] == ' '){
                continue;
            }
            
            if(board[i][j+p] != ' ' || board[i][j+p] != '#'){
                
                if(board[i][j+p] != word[p]){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    bool isHorizontalRTL(vector<vector<char>> &board, string word,int i,int j){
        
        int r = board.size();
        int c = board[0].size();
        int x = word.length();
        
        if(j-x >=0 && board[i][j-x] != '#'){
            return false;
        }
        
        if(j+1 < c && board[i][j+1] != '#'){
            return false;
        }
        
        
        
        for(int p=0;p<x;p++){
            
            if(j-p < 0)   {
                return false;
            } 
            
            if(board[i][j-p] == '#'){
                return false;
            }
            
            if(board[i][j-p] == ' '){
                continue;
            }
            
            if(board[i][j-p] != ' ' || board[i][j-p] != '#'){
                
                if(board[i][j-p] != word[p]){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        
        int r = board.size();
        int c = board[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                
                if(board[i][j] != '#'){
                    
                    if(isHorizontalLTR(board,word,i,j)){
                        return true;
                    }
                    
                    if(isHorizontalRTL(board,word,i,j)){
                        return true;
                    }
                    
                    if(isVerticalLTR(board,word,i,j)){
                        return true;
                    }
                    
                    if(isVerticalRTL(board,word,i,j)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};