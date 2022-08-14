SELECT IFNULL(MAX(salary), null) AS SecondHighestSalary
FROM Employee
WHERE id NOT IN (
    SELECT id
    FROM Employee
    WHERE salary = (
        SELECT MAX(salary)
        FROM Employee
    )
);