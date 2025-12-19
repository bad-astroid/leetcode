impl Solution {
    const M: i64 = 1_000_000_007;

    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        let mut ret: i64 = 1;
        let n = complexity.len();

        for i in 1..n {
            if complexity[0] >= complexity[i] {
                return 0;
            }
        }

        for i in 1..n {
            ret = (ret * i as i64) % Self::M;
        }

        return ret as i32;
    }
}