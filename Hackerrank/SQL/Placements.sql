SELECT Students.Name
FROM Friends, Students
JOIN Packages ON Packages.ID = Students.ID
WHERE Packages.Salary < (
    SELECT Packages.Salary
    FROM Packages
    WHERE Packages.ID = Friends.Friend_ID AND Friends.ID = Students.ID
)
ORDER BY (
    SELECT Packages.Salary
    FROM Packages
    WHERE Packages.ID = Friends.Friend_ID AND Friends.ID = Students.ID
)