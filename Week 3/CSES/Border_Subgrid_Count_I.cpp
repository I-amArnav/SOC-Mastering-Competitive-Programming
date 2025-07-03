#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 3000;
//incomplete!!!!!!!!!!!!!
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<string> G(n);
    for(int i = 0; i < n; i++){
        cin >> G[i];
    }

    // hor[r][c] = length of horizontal run of the current letter ending at (r,c)
    // down[r][c] = length of vertical run of the current letter ending at (r,c)
    static int hor[MAXN][MAXN], down[MAXN][MAXN];

    vector<long long> answer(k, 0);

    // process each letter separately
    for(int li = 0; li < k; li++){
        char ch = 'A' + li;

        // build hor & down
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(G[r][c] == ch){
                    hor[r][c]  = 1 + (c > 0 ? hor[r][c-1] : 0);
                    down[r][c] = 1 + (r > 0 ? down[r-1][c] : 0);
                } else {
                    hor[r][c] = down[r][c] = 0;
                }
            }
        }

        long long cnt = 0;
        static bitset<MAXN> topMask, bottomMask, horizMask, vertMask;

        // enumerate square size s
        for(int s = 1; s <= n; s++){
            // for each possible top row r1
            for(int r1 = 0; r1 + s - 1 < n; r1++){
                int r2 = r1 + s - 1;

                // build bitsets of valid left‑columns c for top & bottom borders
                topMask.reset();
                bottomMask.reset();

                // we want c such that the s‑length segment [c..c+s-1] in row r1 is all ch
                // that is hor[r1][c+s-1] >= s
                // mark bit c if that holds
                for(int c = 0; c + s - 1 < n; c++){
                    if(hor[r1][c+s-1] >= s) topMask.set(c);
                    if(hor[r2][c+s-1] >= s) bottomMask.set(c);
                }

                horizMask = topMask & bottomMask;
                if(horizMask.none()) continue;

                // build bitset of columns c where the left border (column c) is valid vertically:
                // down[r2][c] >= s  ⇒  the vertical segment [r1..r2] in col c is all ch
                vertMask.reset();
                for(int c = horizMask._Find_first(); c < n; c = horizMask._Find_next(c)){
                    if(down[r2][c] >= s)
                        vertMask.set(c);
                }

                // now ensure also the right border at col c+s-1 is valid:
                // i.e. down[r2][c+s-1] >= s  ⇒  bit c+s-1 must be set in vertMask
                // shifting vertMask >> (s-1) aligns bit c+s-1 to position c
                auto vertShift = vertMask & (vertMask >> (s - 1));

                // Intersection of horizMask and vertShift marks exactly the top-left corners
                // of size-s squares whose all four borders are ch.
                cnt += (horizMask & vertShift).count();
            }
        }

        answer[li] = cnt;
    }

    // output
    for(int i = 0; i < k; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}
