//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.regex.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.ExtractNumber(S));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    long ExtractNumber(String sentence) {
        // code here
        long res = 0;
        long tmp = 0;
        boolean indicate= false;
        for(int i=0; i<sentence.length(); i++){
            char x = sentence.charAt(i);
            if(x>='0' && x<='9'){
                if(x == '9'){
                    indicate= true;
                }
                tmp = tmp*10+(x-'0');
            }
            else if(x == ' '){
                if(!indicate){
                    res = Math.max(res, tmp);
                }
                tmp = 0;
                indicate = false;
            }
        }
        if(!indicate){
            res = Math.max(res, tmp);
        }
        if(res == 0){
            return -1;
        }
        return res;
    }
}