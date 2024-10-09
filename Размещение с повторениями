void makeAllComb(vector<vector<int>>& allComb, int n, int k) {

    vector<int> oneComb(n);
    allComb.push_back(oneComb);

    for (int i = 0; i < n; i++) {
        if (oneComb[i] < k - 1) {
            oneComb[i]++;
            for (int ii = 0; ii < i; ii++) {
                oneComb[ii] = 0;
            }
            allComb.push_back(oneComb);
            i = -1;
        }
    }
}
