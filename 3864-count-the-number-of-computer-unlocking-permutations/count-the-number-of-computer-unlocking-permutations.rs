impl Solution {
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        let n = complexity.len();

        for i in 1..n {
            if complexity[0] >= complexity[i] {
                return 0;
            }
        }

        let mut ret: i64 = 1;
        let mod_val: i64 = 1000000007;
        for i in 1..n {
            ret = (ret * i as i64) % mod_val;
        }

        return ret as i32;
    }
}