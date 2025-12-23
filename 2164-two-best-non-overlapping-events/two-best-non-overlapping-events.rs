impl Solution {
    pub fn get_max_suffix(events: &Vec<Vec<i32>>) -> Vec<i32> {
        let n = events.len();
        let mut result = vec![0; n+1];
        for j in (0..n).rev() {
            result[j] = events[j][2].max(result[j+1]);
        }
        return result;
    }

    pub fn max_two_events(events: Vec<Vec<i32>>) -> i32 {
        let events = {
            let mut events = events;
            events.sort_by_key(|event| event[0]);
            events
        };

        // println!("{:?}", events);

        let max_suffix = Self::get_max_suffix(&events);

        // println!("{:?}", max_suffix);

        let mut best_result = 0;

        for event_i in events.iter() {

            let j = events.partition_point(|event_j| event_j[0] <= event_i[1]);
            // println!("{} | {}", j, event_i[2]);
            best_result = best_result.max(max_suffix[j] + event_i[2]);
        }

        return best_result;
    }
}