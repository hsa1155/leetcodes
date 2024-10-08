# Write your MySQL query statement below
select DISTINCT p.email as Email
from Person as p
join Person as d
where p.id!=d.id and p.email=d.email

