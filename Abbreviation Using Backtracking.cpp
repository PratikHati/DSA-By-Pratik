#include<iostream>
#include<string>
#include<vector>
using namespace std;

    void solution(string str, string asf,int count, int pos)
    {
        // write your code here
        if(pos==str.length()){
            if(count==0){
                cout<<asf<<endl;;
            }
            else{
                auto c=to_string(count);
                cout<<asf+c<<endl;
            }
            return;
        }

        

        //add it
        if(count==0){
            solution(str,asf+str[pos],0,pos+1);
        }
        else{
            auto c=to_string(count);
            solution(str,asf+c+str[pos],0,pos+1);
        }

        //do not add it
        solution(str,asf,count+1,pos+1);
        return;
    }
	int main() {
        string str;
        cin >> str;
        solution(str,"",0,0);
        return 0;
    }