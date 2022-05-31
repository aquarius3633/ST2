
string findNumber(vector<int> arr, int k) {
    string retv = "";
    for(int i : arr){
        if(i == k) 
            retv = "YES";
        else 
            retv = "NO";
    }
    return retv;
}


vector<int> oddNumbers(int l, int r) {
    vector<int> v;
    for(int i = l; i <= r; i++)
    {
        if(i%2 == 0) v.push_back(i);
        return v;
    }
}



