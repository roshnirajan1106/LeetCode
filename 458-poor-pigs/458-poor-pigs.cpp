class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int coord = minutesToTest/minutesToDie;
        return ceil(log(buckets)/log(coord+1));
    }
};