impl Solution {
    const M: i64 = 1_000_000_007;
    pub fn mult(a: i64, b: i64) -> i32 {
        return ((a * b) % Self::M) as i32;
    }
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        let mut ret = 1;
        for (i, &c) in complexity.iter().enumerate() {
            if i == 0 { continue; }
            ret = Self::mult(i as i64, ret as i64);
            if c <= complexity[0] { return 0; }
        }

        return ret;
    }
}