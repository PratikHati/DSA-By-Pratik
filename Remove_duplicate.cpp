using namespace std;
#include"iostream"
string remove_duplicate(string s)//Only work for non repeating strings
{
    if(s.length()==0)
        return "";
    char c=s[0];
    string temp=remove_duplicate(s.substr(1));
    if(c==temp[0])
        return temp;
    return c+temp;
}
main()
{
    string s;
    cin>>s;
    cout<<remove_duplicate(s);
}