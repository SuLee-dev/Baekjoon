with PERCENT as (select ID, percent_rank() over (order by SIZE_OF_COLONY desc) as PER from ECOLI_DATA)

select ID,
case when PER <= 0.25 then 'CRITICAL'
     when PER <= 0.5 then 'HIGH'
     when PER <= 0.75 then 'MEDIUM'
     else 'LOW' end as COLONY_NAME
from PERCENT order by ID;