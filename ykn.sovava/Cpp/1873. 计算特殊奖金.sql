# select employee_id,
# (case when mod(employee_id,2)!=0 and LEFT(name,1)!='M' THEN salary
#         when mod(employee_id,2)=0 or LEFT(name,1)='M' THEN 0
#  END) bonus
#  from Employees
#  ORDER BY employee_id;

# select employee_id , 
# if(mod(employee_id,2)!=0 and LEFT(name , 1)!='M' , salary,0) bonus
# from Employees
# order by employee_id;

select employee_id,
case 
    when MOD(employee_id,2)!=0 and LEFT(name,1)!='M' then salary
    when MOD(employee_id,2)=0 or LEFT(name,1) = 'M' then 0
end as bonus
from Employees
order by employee_id
