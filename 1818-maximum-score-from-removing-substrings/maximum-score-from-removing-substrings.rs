impl Solution {
    pub fn remove_pattern(s: String, first_char: char, second_char: char, value: i32) -> (String, i32){
        let mut ret = 0;
        let mut stack: Vec<char> = vec![];

        for c in s.chars() {
            if c == second_char && stack.last() == Some(&first_char) {
                stack.pop();
                ret += value;
            } else {
                stack.push(c);
            }
        }

        return (stack.into_iter().collect(), ret)
    }

    pub fn maximum_gain(s: String, x: i32, y: i32) -> i32 {
        let mut ret = 0;
        let (a, b) = if x >= y { ('a', 'b') } else { ('b', 'a') };
        let (x , y) = if x >= y { (x, y) } else { (y, x) };
        
        let (s, res1) = Self::remove_pattern(s, a, b, x);
        let (_, res2) = Self::remove_pattern(s, b, a, y);

        
        return res1 + res2;
    }
}