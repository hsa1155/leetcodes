# Write your MySQL query statement below
select name
from Customer
where referee_id <> 2 OR referee_id IS NULL;
# Be careful of the NULL value