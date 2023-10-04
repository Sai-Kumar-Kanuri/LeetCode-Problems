# Write your MySQL query statement below
select e2.employee_id , e2.name, count(e2.employee_id) as reports_count, round(avg(e1.age),0) as average_age from Employees e1 inner join Employees e2 on
e1.reports_to = e2.employee_id group by e2.employee_id ,e2.name order by e2.employee_id asc