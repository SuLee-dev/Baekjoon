select G.EMP_NO, EMP_NAME, 
case when avg(SCORE) >= 96 then 'S'
     when avg(SCORE) >= 90 then 'A'
     when avg(SCORE) >= 80 then 'B'
     else 'C' end as GRADE,
case when avg(SCORE) >= 96 then SAL * 0.2
     when avg(SCORE) >= 90 then SAL * 0.15
     when avg(SCORE) >= 80 then SAL * 0.1
     else 0 end as BONUS
from HR_GRADE G
inner join HR_EMPLOYEES E on G.EMP_NO = E.EMP_NO
group by G.EMP_NO
order by G.EMP_NO;