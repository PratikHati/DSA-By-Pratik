#include<iostream>
#include<vector>
using namespace std;
int MaxScore(int n, vector<string>& s, int m, vector<int> &hash, vector<int> &count, int index) {

    if (index == n) {
        return 0;
    }
    //do not add it
    int sumnadd = MaxScore(n, s, m, hash, count, index + 1);

    //add it
    int sumadd = 0;

    string str = s.at(index);

    int size = str.length();

    bool b = false;

    for (int i = 0; i < size; i++) {

        char c = str[i];

        if (hash[c - 'a'] == 0) {
            b = true;
        }

        hash[c - 'a']-- ;
        sumadd += count[c - 'a'];
    }

    int secondsum = 0;

    if (b == false) {
        secondsum = sumadd + MaxScore(n, s, m, hash, count, index + 1);
    }



        for (int i = 0; i < size; i++) {

            char c = str[i];


            hash[c - 'a'] += 1;
        }


    return max(secondsum, sumnadd);

}
int main() {
    int n;
    cin >> n;

    vector<string> s;
    for (int i = 0; i < n; i++) {
        string ans;
        cin >> ans;
        s.push_back(ans);
    }

    int m;
    cin >> m;

    vector<char> c;
    for (int i = 0; i < m; i++) {
        char x;
        cin >> x;
        c.push_back(x);
    }

    vector<int> hash(26, 0);

    for (int i = 0; i < m; i++) {
        hash[c.at(i) - 'a'] ++;
    }

    vector<int> count( 26, 0);
    for (int i = 0; i < 26; i++) {
        int num;
        cin >> num;
        count[i] = num;
    }

    cout << MaxScore(n, s, m, hash, count, 0) << endl;
    return 0;
}