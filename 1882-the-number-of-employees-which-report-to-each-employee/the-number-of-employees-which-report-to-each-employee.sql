# Write your MySQL query statement below
select s.employee_id,s.name,count(*)as reports_count,round(avg(e.age)) as average_age
from Employees as e
join Employees as s on s.employee_id=e.reports_to 
group by e.reports_to 
order by s.employee_id