class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int step = countSteps(n, curr, curr + 1);
            if (step <= k) {
                curr++;
                k -= step;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }

private:
    int countSteps(int n, long prefix1, long prefix2) {
        /*
        假如只有0层，子结点只有1个，C o u n t ( 0 ) = 1 假如有1层，子结点有1+(20-10)=11个，C o u n t ( 1 ) = 11 假如有2层，子结点有1+(20-10)+(200-100)=111个，C o u n t ( 2 ) = 111 

        */
        int steps = 0;
        while (prefix1 <= n) {
            steps += min((long)(n + 1), prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};