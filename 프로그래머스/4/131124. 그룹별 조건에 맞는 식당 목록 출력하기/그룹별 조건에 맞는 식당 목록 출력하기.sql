with t as (select MEMBER_ID, count(*) as COUNT from REST_REVIEW group by MEMBER_ID order by COUNT desc limit 1)

select MEMBER_NAME, REVIEW_TEXT, date_format(REVIEW_DATE, '%Y-%m-%d') as REVIEW_DATE
from MEMBER_PROFILE M
inner join REST_REVIEW R
on M.MEMBER_ID = R.MEMBER_ID
inner join t
on M.MEMBER_ID = t.MEMBER_ID
order by 3, 2;