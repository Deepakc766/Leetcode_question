class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                char ch = num1[i];
                int chtonum = ch - '0';
                sum = sum + chtonum;
                i--;
            }
            if (j >= 0) {
                char ch = num2[j];
                int chtonum = ch - '0';
                sum = sum + chtonum;
                j--;
            }

            int last = sum % 10;
            carry = sum / 10;
            char ch = last + '0';
            ans = ans + ch;   
        }

       
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
