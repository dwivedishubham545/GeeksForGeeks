//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;

class GFG {
	public static void main (String[] args)throws IOException {
		
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out=new PrintWriter(System.out);
		int t = Integer.parseInt(in.readLine().trim());
        while(t-- > 0)
        {
            int n = Integer.parseInt(in.readLine().trim());
            String s[]=in.readLine().trim().split(" ");
            
            int gallery[] = new int[n];
            for(int i=0; i<n; i++)
                gallery[i] = Integer.parseInt(s[i]);
            Solution T = new Solution();
            out.println(T.min_sprinklers(gallery,n));
        }
		out.close();
		
	}
}





// } Driver Code Ends


//User function Template for Java

class Solution
{
    int min_sprinklers(int gallery[], int n)
    {
        int[][] v = new int[n][2];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (gallery[i] != -1) {
                v[count][0] = i - gallery[i];
                v[count][1] = i + gallery[i];
                count++;
            }
        }
        v = Arrays.copyOf(v, count);
        Arrays.sort(v, Comparator.comparingInt(a -> a[0]));
        int target = 0;
        int i = 0;
        int ans = 0;
        while (target < n && i < count) {
            if (v[i][0] > target) {
                return -1;
            }
            int maxi = v[i][1];
            i++;
            while (i < count && v[i][0] <= target) {
                maxi = Math.max(maxi, v[i][1]);
                i++;
            }
            target = maxi + 1;
            ans++;
        }
        if (target < n - 1) {
            return -1;
        } else {
            return ans;
        }
    }
}
