class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n==0)
            return 1;
        
        int temp=n;
        int bit=0;
        while(temp!=0){
            bit++;
            temp/=2;
        }
        
        int andbit=0;
        for(int i=0;i<bit;i++){
            andbit=andbit<<1;       //left shift
            andbit=andbit | 1;      //bitwise OR
        }
        
        return (~n)&andbit;         //bitwise AND
    }
};