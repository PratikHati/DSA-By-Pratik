#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
bool isPossibleHorizontal(vector<string>& v, string word, int i, int j) {
    if (j - 1 >= 0 && v[i][j - 1] != '+') {
        return false;
    }
    if (j + word.length() < 10 && v[i][j + word.length()] != '+') {
        return false;
    }

    for (int x = 0; x < word.length(); x++) {
        if (j + x >= 10) {
            return false;
        }
        if (v[i][j + x] == '+') {
            return false;
        }

        if (v[i][j + x] == '-') {
            continue;
        }

        if(v[i][j + x] != '+' || v[i][j+x] != '-'){
            if( v[i][j + x] == word[x])
                continue;
            return false;
        }
        
    }

    return true;
}
bool isPossibleVertical(vector<string>& v, string word, int i, int j) {
    if (i - 1 >= 0 && v[i - 1][j] != '+') {
        return false;
    }
    if (i + word.length() < 10 && v[i + word.length()][j] != '+') {
        return false;
    }

    for (int x = 0; x < word.length(); x++) {
        if (i + x >= 10) {
            return false;
        }
        if (v[i + x][j] == '+') {
            return false;
        }

        if (v[i+x][j] == '-') {
            continue;
        }

        if(v[i+x][j] != '+' || v[i+x][j] != '-'){
            if( v[i+x][j] == word[x])
                continue;
            return false;
        }
    }

    return true;
}
vector<bool> PlaceHorizontal(vector<string>& v, string word, int i, int j) {
    vector<bool> b(word.length(), false);

    for (int x = 0; x < word.length(); x++) {

        if (v[i][j + x] == '-') {
            v[i][j + x] = word[x];
            b[x] = true;
        }
    }

    return b;
}
void UnPlaceHorizontal(vector<string>& v, vector<bool>& b, int i, int j, string word) {

    for (int x = 0; x < word.length(); x++) {

        if (b[x] == true) {
            v[i][j + x] = '-';
            //b[x] = false;
        }
    }
}
vector<bool> PlaceVertical(vector<string>& v, string word, int i, int j) {
    vector<bool> b(word.length(), false);

    for (int x = 0; x < word.length(); x++) {

        if (v[i + x][j] == '-') {
            v[i + x][j] = word[x];
            b[x] = true;
        }
    }

    return b;
}
void UnPlaceVertical(vector<string>& v, vector<bool>& b, int i, int j, string word) {

    for (int x = 0; x < word.length(); x++) {

        if (b[x] == true) {
            v[i + x][j] = '-';
            //b[x] = false;
        }
    }
}
void FillV(vector<string>& v, int n, vector<string>& city, int index) {
    if (index == city.size()) {
        for (auto x : v) {
            for (auto y : x) {
                cout << y;
            }
            cout << endl;
        }
        //cout<<endl;
        return;
    }
    string word = city[index];

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {

            if (v[i][j] == '-' || v[i][j] == word[0]) {
                if (isPossibleHorizontal(v, word, i, j)) {
                    vector<bool> b = PlaceHorizontal(v, word, i, j);
                    FillV(v, n, city, index + 1);
                    UnPlaceHorizontal(v, b, i, j, word);
                }
                if (isPossibleVertical(v, word, i, j)) {
                    vector<bool> b = PlaceVertical(v, word, i, j);
                    FillV(v, n, city, index + 1);
                    UnPlaceVertical(v, b, i, j, word);
                }
            }
        }
    }

    return;
}
int main() {

    vector<string> v;

    for (int i = 0; i < 10; i++) {
        string str;
        cin >> str;

        v.push_back(str);
    }

    int n;
    cin >> n;
    vector<string> city;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        city.push_back(str);
    }


    FillV(v, n, city, 0);

    return 0;
}
