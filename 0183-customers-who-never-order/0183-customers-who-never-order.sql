# Write your MySQL query statement below

SELECT name as Customers from Customers WHERE Customers.id not in(select customerId from Orders);