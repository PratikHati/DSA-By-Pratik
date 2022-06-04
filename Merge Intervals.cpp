vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    
    vector<vector<int>> ans;
    
    vector<int> v ;
    v.push_back(intervals[0][0]);
    v.push_back(intervals[0][1]);
    
    
    for(auto x: intervals){
        if(x[0] <= v[1]){
            v[1] = max(v[1],x[1]);
        }
        else{
            ans.push_back(v);
            v = x;
        }
    }
    ans.push_back(v);
    return ans;
}
