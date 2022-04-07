bool isPossible(petrolPump p[],int n,int start){
        
        int i=0;
        int prevpetrol = 0;
        while(i < n){
            
            int index = (start+i) % n;
            
            int currpetrol = p[index].petrol+prevpetrol;
            
            if(currpetrol < p[index].distance){
                return false;
            }
            else{
                prevpetrol = currpetrol - p[index].distance;
            }
            i++;
        }
        
        return true;
    }
    int tour(petrolPump p[],int n)
    {
       //Your code here
       for(int i=0;i<n;i++){
            if(isPossible(p,n,i))
                return i;
       }
       
       return -1;
    }