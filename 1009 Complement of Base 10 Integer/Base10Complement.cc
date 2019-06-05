class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int pow = 1;
        while (pow < N) {
            pow = pow * 2;
        }
        pow--;
        return pow & (N ^ -1);
    }
};