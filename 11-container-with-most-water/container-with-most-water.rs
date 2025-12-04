impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut l = 0;
        let mut r = height.len()-1;
        while l < r {
            ans = ans.max((r - l) as i32 * height[l].min(height[r]));
            if height[l] < height[r] {
                l += 1;
            } else {
                r -= 1;
            }
        }
        return ans;
    }
}