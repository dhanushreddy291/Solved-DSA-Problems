# Write your MySQL query statement below
SELECT W1.id FROM Weather W1, Weather W2
WHERE W1.temperature > W2.temperature AND W2.recordDate + interval 1 day = W1.recordDate