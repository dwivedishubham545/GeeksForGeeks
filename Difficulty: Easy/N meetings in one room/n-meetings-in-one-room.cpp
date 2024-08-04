//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> meetings(n);
        for(int i = 0; i < n; i++) {
            meetings[i] = {end[i], start[i]};
        }
        sort(meetings.begin(), meetings.end());
        
        int ans = 1;
        int time = meetings[0].first;
        
        for(int i = 1; i < n; i++) {
            if(meetings[i].second > time) {
                ans++;
                time = meetings[i].first;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends