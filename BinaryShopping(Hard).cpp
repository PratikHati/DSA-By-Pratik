string binaryShopping(string S, int P)
{
    // Write your code here.
    int size=s.length();
    int count=2;
    for(int i=size-1;i>=0;i--){
        if(s[i]=='1'){
         	if(count>0){
                s[i]='0';
            	count--;
        	}   
        }
        
    }
    return s;
}