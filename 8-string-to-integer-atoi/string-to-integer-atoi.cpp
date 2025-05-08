class Solution {
public:
    int myAtoi(string s) {
        bool isWhiteSpace = true;
        int sign = 1, ans = 0;
        long long num = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(isWhiteSpace && s[i] == ' ') {
                continue;
            }

            if(isWhiteSpace) {
                isWhiteSpace = false;
                if(s[i] == '-') {
                    sign = -1;
                    continue;
                }
                if(s[i] == '+') {
                    continue;
                }
                if(s[i] <= '9' && s[i] >= '0') {
                    num = s[i] - '0';
                    continue;
                }

                // not a number or a sign
                return 0;
            }

            if(!(s[i] <= '9' && s[i] >= '0')) {
                break;
            }

            num *= 10;
            num += s[i] - '0';

            if(num > (1ll<<31) + (sign == -1 ? 0 : -1)) {
                num = (1ll<<31) + (sign == -1 ? 0 : -1);
                break;
            }
        }

        return num * sign;
    }
};