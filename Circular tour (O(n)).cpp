int tour(petrolPump P[],int n)
    {
       //Your code here
       int start = 0;
       int currbal = 0;
       int track = 0;
       
       for(int i=0;i<n;i++){
           currbal +=  P[i].petrol - P[i].distance;
 
           if(currbal < 0){
               track += currbal;
               start = i+1;
               currbal = 0;
           }
       }
       
       if(currbal+track >= 0){
           return start;
       }
       
       return -1;
    }