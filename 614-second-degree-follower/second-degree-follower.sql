# Write your MySQL query statement below
select
    f2.followee as follower,
    count(DISTINCT f2.follower) as num
from Follow f1
join Follow f2
on f1.follower = f2.followee
group by f2.followee
order by f2.followee;