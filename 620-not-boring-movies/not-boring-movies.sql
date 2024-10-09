# Write your MySQL query statement below

select *
from Cinema as c
where MOD( id, 2) = 1 and c.description  <> "boring"
order by rating desc