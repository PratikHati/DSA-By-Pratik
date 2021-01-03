#include"iostream"
#include"cstring"
using namespace std;
void replace_pi(string input)
{
    if(input.length()==0)
        return;
    else if(input[0]=='p' && input[1]=='i')
    {
        cout<<3.14;;
        
        replace_pi(input.substr(2));
    }
    else
    {
        cout<<input[0];
        
        replace_pi(input.substr(1));
    }
        
    
}
main()
{
    string s;
    cin>>s;
    replace_pi(s);
}