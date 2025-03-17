select HISTORY_ID, round(DAILY_FEE * DATEDIFF * (100 - coalesce(DISCOUNT_RATE, 0)) / 100) as FEE from
(select distinct HISTORY_ID, DAILY_FEE, datediff(END_DATE, START_DATE) + 1 as DATEDIFF,
case when datediff(END_DATE, START_DATE) + 1 < 7 then null
     when datediff(END_DATE, START_DATE) + 1 < 30 then '7일 이상'
     when datediff(END_DATE, START_DATE) + 1 < 90 then '30일 이상'
     else '90일 이상' end as DURATION_TYPE
from CAR_RENTAL_COMPANY_CAR A
inner join CAR_RENTAL_COMPANY_RENTAL_HISTORY B
on A.CAR_ID = B.CAR_ID
where A.CAR_TYPE = '트럭') as C
left join
(select DURATION_TYPE, DISCOUNT_RATE from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where CAR_TYPE = '트럭') as D
on C.DURATION_TYPE = D.DURATION_TYPE
order by 2 desc, 1 desc;