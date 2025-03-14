select F.FLAVOR from 
(select FLAVOR, sum(TOTAL_ORDER) as SUM from FIRST_HALF group by FLAVOR) F
inner join (select FLAVOR, sum(TOTAL_ORDER) as SUM from JULY group by FLAVOR) J 
on F.FLAVOR = J.FLAVOR order by (F.SUM + J.SUM) desc limit 3;