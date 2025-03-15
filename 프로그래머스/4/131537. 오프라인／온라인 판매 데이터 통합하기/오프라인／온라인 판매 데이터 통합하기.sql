with t as
(select SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT from ONLINE_SALE
union
select SALES_DATE, PRODUCT_ID, null as USER_ID, SALES_AMOUNT from OFFLINE_SALE)

select date_format(SALES_DATE, '%Y-%m-%d') as SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT from t where SALES_DATE like '2022-03%' order by 1, 2, 3