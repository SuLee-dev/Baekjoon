select YEAR(SALES_DATE) as YEAR, MONTH(SALES_DATE) as MONTH, GENDER, count(distinct U.USER_ID) as USERS from (select * from USER_INFO where GENDER is not null) as U inner join ONLINE_SALE as O on U.USER_ID = O.USER_ID group by 1, 2, 3 order by 1, 2, 3;