void printTheDiamond(int r, int c, int s)
{
	// Write your code here.
    
    for(int row=0;row<r;row++){
        int size=s*2;
        int start=(size/2)-1,end=(size/2);
        for(int i=0;i<size;i++){
            if(i<size/2){
                bool flag=false;
                int temp1=start,temp2=end;
                for(int j=0;j<size*c;j++){
               		if(j==start){
                   		cout<<"/";
                        start+=size;
                        flag=true;
                	}
               		else if(j==end){
                   		cout<<"\\";
                        end+=size;
                        flag=false;
                    }               		
                   	else{
                        if(flag=true)
                   			cout<<"o";
                        else
                            cout<<"e";
                   		}   
					}
                    start=temp1-1;
                    end=temp2+1;
                    cout<<endl;
                }
            else{
                if(i==size/2){
                    start=0,end=size-1;
                }
                bool flag1=false;
                int temp1=start,temp2=end;
                for(int j=0;j<size*c;j++){
                	if(j==start){
                        cout<<"\\";
                        start+=size;
                        flag1=true;
                    }
                    else if(j==end){
                        cout<<"/";
                        end+=size;
                        flag1=false;
                    }
                    else{
                        if(flag1==true){
                           cout<<"o"; 
                        }
                        else{
                            cout<<"e";
                        }
                    }
            	}
                start=temp1+1;
                end=temp2-1;
                cout<<endl;
            }
            
        }
    }
}