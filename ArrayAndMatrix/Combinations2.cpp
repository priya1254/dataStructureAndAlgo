//permutations combination problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<int> chapters;
vector<int> index;
vector<int> charChapters;

int permute(vector<int> config, vector<bool> left, vector<vector<int> > nbr) {
    if (config.size() == left.size()) {
        return 1;
    }

    bool allClear = true;
	int sum = 0;
    for (int i=0; i<left.size(); ++i) {
        if (left[i] && (nbr[i].size() != 0 || (config.size() > 0 && charChapters[i] == charChapters[config[config.size()-1]]))) {
            allClear = false;
            break;
        }
    }
    if (allClear) {
        sum = 1;
        for (int i=1; i<=left.size()-config.size(); ++i) {
            sum *= i;
        }
        return sum;
    }
    for (int i=0; i<left.size(); ++i) {
        if (!left[i] or nbr[i].size() != 0 or (config.size() > 0 && charChapters[i] == charChapters[config[config.size()-1]])) continue;
        vector<vector<int> > newAdj = nbr;
        config.push_back(i);
        left[i] = false;
        for (int j=0; j<newAdj.size(); ++j) {
            newAdj[j].erase(remove(newAdj[j].begin(), newAdj[j].end(), i), newAdj[j].end());
        }
        sum += permute(config, left, newAdj);
        config.pop_back();
        left[i] = true;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int ti=1; ti<=t; ++ti) {
        int n,m;
        cin >> n >> m;
        chapters = vector<int>(n);
        index = vector<int>(n);
        charChapters = vector<int>();
        int sumOfChaps = 0;
        for (int i=0; i<n; ++i) {
            cin >> chapters[i];
            index[i] = sumOfChaps;
            sumOfChaps += chapters[i];
            for (int j=0; j<chapters[i]; ++j) {
                charChapters.push_back(i);
            }
        }
        vector<vector<int> > nbr(sumOfChaps);
        for (int i=0; i<n; ++i) {
            for (int j=1; j<chapters[i]; ++j) {
                for (int k=0; k<j; ++k) {
                    nbr[index[i]+j].push_back(index[i]+k);
                }
            }
        }
        for (int i=0; i<m; ++i) {
            int c,p,d,q;
            cin >> c >> p >> d >> q;
            nbr[index[d-1]+q-1].push_back(index[c-1]+p-1);
        }

        int sum = permute(vector<int>(), vector<bool>(sumOfChaps,1), nbr);


        cout << "Case #" << ti << ": " << sum << "\n";
    }
    return 0;
}
