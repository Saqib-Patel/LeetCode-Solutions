select query_name,
round(avg(rating/position),2) as quality,
round(SUM(CASE WHEN rating<3 THEN 1 ELSE 0 END) / COUNT(*),4)*100 AS poor_query_percentage
from queries
group by query_name;