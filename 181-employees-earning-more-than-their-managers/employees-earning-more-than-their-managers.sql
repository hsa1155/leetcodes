# Write your MySQL query statement below
select e.name as Employee
from Employee as e
join Employee as m
where e.managerId=m.id And e.salary>m.salary
