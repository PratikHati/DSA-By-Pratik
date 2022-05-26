vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    int size = 100000007;
    int* index = new int[size];
    //memset(index, -1, sizeof(index));
    for (int i = 0; i < size; i++) {
        index[i] = -1;
    }
    vector<int> ans;

    int idx = 1;

    for (int i = 0; i < ranked.size(); i++) {

        if (i != 0 && ranked[i] != ranked[i - 1]) {
            idx++;
        }

        int pos = ranked[i];
        if (index[pos] == -1)
            index[pos] = idx;
    }

    int j = ranked.size() - 1;

    for (int i = 0; i < player.size(); i++) {

        int val = player[i];

        while (j >= 0) {

            if (ranked[j] >= val) {

                if (ranked[j] == val) {
                    ans.push_back(index[ranked[j]]);
                }
                else
                    ans.push_back(index[ranked[j]] + 1);
                break;
            }
            j--;
        }

        if (j == -1) {
            ans.push_back(1);
        }
    }

    return ans;
}