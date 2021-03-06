-- source include/not_embedded.inc

use test;
let $MYSQLD_DATADIR= `select @@datadir`;

create table log_test (col1 int, col2 int);
create table log_test2 (col1 int, col2 int);
insert into log_test values (1, 2);
insert into log_test values (3, 4);
insert into log_test2 values (5, 6);
insert into log_test2 values (7, 8);
select * from log_test;
select * from log_test limit 2;
select * from log_test where col1=1;
select * from log_test where col1=0;
insert into log_test select * from log_test2;
delete from log_test where col1=1;
update log_test set col1=2 where col1=3;
delete from log_test2 where col1=5;
select * from log_test2;
update log_test2 set col2=12 where col2=8;
drop table log_test;
drop table log_test2;
ping;

# Show the log content (timestamp is removed)
--exec sed -e '/Query/!d;s/^.*Query[ \t]*//' $MYSQLD_DATADIR/auditlog.000001
