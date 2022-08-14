SELECT Employees.`employee_id`
FROM Employees
LEFT JOIN Salaries
ON Employees.`employee_id` = Salaries.`employee_id`
WHERE Employees.`name` IS NULL OR Salaries.`salary` IS NULL

UNION

SELECT Salaries.`employee_id`
FROM Salaries
LEFT JOIN Employees
ON Salaries.`employee_id` = Employees.`employee_id`
WHERE Employees.`name` IS NULL OR Salaries.`salary` IS NULL

ORDER BY 1 ASC;