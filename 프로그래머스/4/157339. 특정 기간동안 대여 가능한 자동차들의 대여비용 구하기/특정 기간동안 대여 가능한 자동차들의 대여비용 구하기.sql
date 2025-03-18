select t1.CAR_ID, t1.CAR_TYPE, round(DAILY_FEE * 30 * (100 - DISCOUNT_RATE) / 100) as FEE from
(select CAR_ID, CAR_TYPE, DAILY_FEE from CAR_RENTAL_COMPANY_CAR where CAR_TYPE in ('SUV', '세단')) as t1
inner join
(select distinct CAR_ID from CAR_RENTAL_COMPANY_RENTAL_HISTORY where CAR_ID not in (select CAR_ID from CAR_RENTAL_COMPANY_RENTAL_HISTORY where START_DATE <= '2022-11-30' and END_DATE >= '2022-11-01')) as t2
on t1.CAR_ID = t2.CAR_ID
inner join
(select CAR_TYPE, DISCOUNT_RATE from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where CAR_TYPE in ('SUV', '세단') and DURATION_TYPE = '30일 이상') as t3
on t1.CAR_TYPE = t3.CAR_TYPE
where round(DAILY_FEE * 30 * (100 - DISCOUNT_RATE) / 100) between 500000 and 1999999
order by FEE desc, t1.CAR_TYPE, t1.CAR_ID desc