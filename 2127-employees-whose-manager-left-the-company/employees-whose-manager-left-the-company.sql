# Write your MySQL query statement below
select e.employee_id as employee_id
from Employees as e
left join Employees as m on m.employee_id =e.manager_id 
where (not isnull(e.manager_id)) and isnull(m.employee_id) and e.salary<30000
order by e.employee_id 