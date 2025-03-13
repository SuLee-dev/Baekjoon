select AUTHOR_ID, AUTHOR_NAME, CATEGORY, sum(합계) as TOTAL_SALES from
(select A.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY, SUM_SALES * PRICE as 합계
from BOOK B inner join
(select BOOK_ID, sum(SALES) as SUM_SALES from BOOK_SALES where SALES_DATE like '2022-01%' group by BOOK_ID) as t
on B.BOOK_ID = t.BOOK_ID
inner join AUTHOR A on B.AUTHOR_ID = A.AUTHOR_ID) as t2
group by 1, 3
order by 1, 3 desc;