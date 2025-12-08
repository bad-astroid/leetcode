impl Solution {
    fn max_area_left_to_right(height: & Vec<i32>) -> i32 {
        let mut maxes = vec![];
        let mut ret = 0;

        for (i, h) in height.iter().enumerate() {
            if maxes.is_empty() {
                maxes.push((i, h));
            }

            let leftmost_greater_index = maxes.partition_point(|&(_, value)| value < h);
            if leftmost_greater_index < maxes.len() {
                let (index, _) = maxes[leftmost_greater_index];
                ret = ret.max((i - index) as i32 * h);
            }

            if let Some(&(_, max)) = maxes.last() && max < h{
                maxes.push((i, h));    
            }
        }
        return ret;
    }

    pub fn max_area(height: Vec<i32>) -> i32 {
        let reversed_height = height.iter().rev().cloned().collect();
        return Self::max_area_left_to_right(& height).max(Self::max_area_left_to_right(& reversed_height));
    }
}