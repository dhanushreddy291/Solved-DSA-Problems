SELECT E1.name AS Employee
FROM Employee AS E1, Employee AS E2
WHERE E1.managerID = E2.id AND E1.salary > E2.salary;


SELECT E1.name
FROM Employee E1, Employee E2
WHERE E1.managerID = E2.id AND E1.salary > E2.salary;