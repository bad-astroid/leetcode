# Write your MySQL query statement below
select
    f1.followee as follower,
    count(DISTINCT f1.follower) as num
from Follow f1
join Follow f2
on f1.followee = f2.follower
group by f1.followee
order by f1.followee