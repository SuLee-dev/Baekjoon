select R.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, SCORE
from REST_INFO R,
(select REST_ID, round(avg(REVIEW_SCORE), 2) as SCORE
from  REST_REVIEW
group by REST_ID) as T
where R.REST_ID = T.REST_ID and ADDRESS like '서울%'
order by SCORE desc, FAVORITES desc;