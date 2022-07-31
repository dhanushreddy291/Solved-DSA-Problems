SELECT Users.`name` AS name, IFNULL(SUM(Rides.`distance`), 0) AS travelled_distance
FROM Users
LEFT JOIN Rides
ON Users.`id` = Rides.`user_id`
GROUP BY Rides.`user_id`
ORDER BY SUM(Rides.`distance`) DESC, Users.`name`;