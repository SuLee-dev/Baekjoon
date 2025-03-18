select
case when SKILL_CODE & (select sum(CODE) from SKILLCODES where CATEGORY = 'Front End') and SKILL_CODE & (select CODE from SKILLCODES where NAME = 'Python') then 'A'
when SKILL_CODE & (select CODE from SKILLCODES where NAME = 'C#') then 'B'
when SKILL_CODE & (select sum(CODE) from SKILLCODES where CATEGORY = 'Front End') then 'C' end as GRADE, ID, EMAIL
from DEVELOPERS group by 1, 2, 3 having GRADE is not null order by 1, 2;