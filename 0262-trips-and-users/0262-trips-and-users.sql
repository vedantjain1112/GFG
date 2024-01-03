SELECT request_at AS Day,
       ROUND(SUM(CASE WHEN status = 'cancelled_by_driver' OR status = 'cancelled_by_client' THEN 1 ELSE 0 END)
             / COUNT(DISTINCT id), 2) AS 'Cancellation Rate'
FROM Trips
JOIN Users AS client ON Trips.client_id = client.users_id AND client.banned = 'No'
JOIN Users AS driver ON Trips.driver_id = driver.users_id AND driver.banned = 'No'
WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at;

