#1. 创建数据库test01_office,指明字符集为utf8。并在此数据库下执行下述操作
CREATE DATABASE IF NOT EXISTS test01_office CHARACTER SET 'utf8';
USE test01_office;
#2. 创建表dept01
/*
字段     类型
id INT(7)
NAME VARCHAR(25)
*/
CREATE TABLE dept01(
    id INT(7),
    `NAME` VARCHAR(25)
    );
#3. 将表departments中的数据插入新表dept02中
CREATE TABLE dept02
AS
SELECT *
FROM atguigudb.departments;

#4. 创建表emp01
/*
字段         类型
id INT(7)
first_name VARCHAR (25)
last_name VARCHAR(25)
dept_id INT(7)
*/
CREATE TABLE emp01(
  id INT(7),
  first_name VARCHAR(25),
  last_name VARCHAR(25),
  dept_id INT(7)
  );
  
#5. 将列last_name的长度增加到50
ALTER TABLE emp01
MODIFY last_name VARCHAR(50);
DESCRIBE emp01;
#6. 根据表employees创建emp02
CREATE TABLE emp02
AS
SELECT *
FROM atguigudb.employees
WHERE 1 = 2;
SELECT *
FROM emp02;
#7. 删除表emp01
DROP TABLE IF EXISTS emp01;
#8. 将表emp02重命名为emp01
RENAME TABLE emp02 TO emp01;
#9.在表dept02和emp01中添加新列test_column，并检查所作的操作
ALTER TABLE dept02
ADD test_column VARCHAR(20);
DESC dept02;
ALTER TABLE emp01
ADD test_column VARCHAR(20);
DESC emp01;
#10.直接删除表emp01中的列 department_id
ALTER TABLE emp01
DROP department_id;

SELECT *
FROM emp01;

# 1、创建数据库 test02_market
CREATE DATABASE IF NOT EXISTS test02_market CHARACTER SET 'utf8';
# 2、创建数据表 customers
/*
字段名 数据类型
c_num int
c_name varchar(50)
c_contact varchar(50)
c_city varchar(50)
c_birth date

*/
USE test02_market;
CREATE TABLE customer(
  c_num INT,
  c_name VARCHAR(50),
  c_contact VARCHAR(50),
  c_city VARCHAR(50),
  c_brith DATE
  );
# 3、将 c_contact 字段移动到 c_birth 字段后面
ALTER TABLE customer 
MODIFY c_contact VARCHAR(50) AFTER c_brith;
DESCRIBE customer;
# 4、将 c_name 字段数据类型改为 varchar(70)
ALTER TABLE customer 
MODIFY c_name VARCHAR(70);
# 5、将c_contact字段改名为c_phone
ALTER TABLE customer 
CHANGE c_contact c_phone VARCHAR(50);
# 6、增加c_gender字段到c_name后面，数据类型为char(1)
ALTER TABLE customer 
ADD c_gender CHAR(1) AFTER c_name;
# 7、将表名改为customers_info
RENAME TABLE customer TO customer_info;
# 8、删除字段c_city
ALTER TABLE customer_info
DROP c_city;
DESCRIBE customer_info;


# 1、创建数据库test03_company
CREATE DATABASE IF NOT EXISTS test03_company CHARACTER SET 'utf8';
USE  test03_company;
# 2、创建表offices
/*
officeCode int
city varchar(30)
address varchar(50)
country varchar(50)
postalCode varchar(25)

*/
CREATE TABLE offices(
  officeCode INT,
  city VARCHAR(30),
  address VARCHAR(50),
  country VARCHAR(50),
  postalCode VARCHAR(25)
  );
  DESCRIBE offices;
# 3、创建表employees
/*
字段名 数据类型
empNum int
lastName varchar(50)
firstName varchar(50)
mobile varchar(25)
code int
jobTitle varchar(50)
birth date
note varchar(255)
sex varchar(5)
*/
CREATE TABLE employees(
  empNum INT,
  lastName VARCHAR(50),
  firstName VARCHAR(50),
  mobile VARCHAR(25),
  `code` INT,
  jobtitle VARCHAR(50),
  brith DATE,
  note VARCHAR(250),
  sex VARCHAR(5)
  );
  DESC employees ;
  # 4、将表employees的mobile字段修改到code字段后面
  ALTER TABLE employees
  MODIFY mobile VARCHAR(25) AFTER `code`;
# 5、将表employees的birth字段改名为birthday
ALTER TABLE employees 
CHANGE brith birthday DATE;
# 6、修改sex字段，数据类型为char(1)
ALTER TABLE employees 
MODIFY sex CHAR(1);

# 7、删除字段note
ALTER TABLE employees 
DROP note;
# 8、增加字段名favoriate_activity，数据类型为varchar(100)
ALTER TABLE employees
ADD favoriate_activity VARCHAR(100);
# 9、将表employees的名称修改为 employees_info
RENAME TABLE employees TO employees_info;



#1. 创建数据库dbtest11
CREATE DATABASE IF NOT EXISTS dbtest11 CHARACTER SET 'utf8';
#2. 运行以下脚本创建表my_employees
USE dbtest11;
CREATE TABLE my_employees(
 id INT(10),
 first_name VARCHAR(10),
 last_name VARCHAR(10),
 userid VARCHAR(10),
 salary DOUBLE(10,2)
);
CREATE TABLE users(
 id INT,
 userid VARCHAR(10),
 department_id INT
);
#3. 显示表my_employees的结构
DESCRIBE my_employees;
#4. 向my_employees表中插入下列数据
/*
ID FIRST_NAME   LAST_NAME  USERID   SALARY
1  patel        Ralph      Rpatel   895
2  Dancs        Betty      Bdancs   860
3  Biri         Ben        Bbiri    1100
4  Newman       Chad       Cnewman  750
5  Ropeburn     Audrey     Aropebur 1550
 */
 INSERT INTO my_employees(id,first_name,last_name,userid,salary)
 VALUES(1,'patel','Ralph','Rpatel',895),
       (2,'Dancs','Betty','Bdancs',860),
       (3,'Biri','Ben','Bbiri',1100),
       (4,'Newman','Chad','Cnewman',750),
       (5,'Ropeburn','Audrey','Aropebur',1550);
 SELECT *
 FROM my_employees;
#5. 向users表中插入数据
/*

*/
INSERT INTO users(id,userid,department_id)
VALUES(1,'Rpatel', 10),
      (2 ,'Bdancs',10),
      (3 ,'Bbiri' ,20),
      (4 ,'Cnewman', 30),
      (5 ,'Aropebur', 40);
      SELECT *
      FROM users;
#6. 将3号员工的last_name修改为“drelxer”
UPDATE my_employees SET last_name = 'drelxer'
WHERE id = 3;
#7. 将所有工资少于900的员工的工资修改为1000
UPDATE my_employees SET salary = 1000
WHERE salary < 900;
#8. 将userid为Bbiri的user表和my_employees表的记录全部删除
DELETE u,e 
FROM `users` u JOIN my_employees e 
ON u.userid = e.userid
WHERE u.userid = 'Bbiri';
#9. 删除my_employees、users表所有数据
DELETE FROM users;
DELETE FROM my_employees;
#10. 检查所作的修正答案：
SELECT *
FROM users;
SELECT *
FROM my_employees;
#11. 清空表my_employees
TRUNCATE TABLE my_employees;


# 1. 使用现有数据库dbtest11
USE dbtest11;
# 2. 创建表格pet
/*
                字段名  字段说明  数据类型
                name    宠物名称  VARCHAR(20)
                owner   宠物主人  VARCHAR(20)
                species 种类      VARCHAR(20)
                sex     性别      CHAR(1)
                birth   出生日期  YEAR
                death   死亡日期  YEAR
                */

CREATE TABLE pet(
                name VARCHAR(20),
                owner VARCHAR(20),
                species VARCHAR(20),
                sex CHAR(1),
                birth YEAR,
                death YEAR
                );
DESCRIBE pet;
                
 # 3. 添加记录 
 /*              
name owner species sex birth death
Fluffy harold Cat f 2003 2010
Claws gwen Cat m 2004  
Buffy   Dog f 2009  
Fang benny Dog m 2000  
bowser diane Dog m 2003 2009
Chirpy   Bird f 2008  
*/
SELECT *
FROM pet;
INSERT INTO pet(name,owner,species, sex,birth,death)
VALUES('Fluffy',' harold','Cat','f', 2003, 2010),
      ('bowser','diane','Dog','m', 2003, 2009);
INSERT INTO pet(name,owner,species,sex,birth)      
VALUES('Claws','gwen','Cat','m',2004); 

INSERT INTO pet(name,owner,species,sex,birth)      
VALUES('Fang','benny','Dog','m',2000); 
  
INSERT INTO pet(`name`,species,sex,birth) VALUES('Chirpy','Bird','f','2008');
INSERT INTO pet(`name`,species,sex,birth) VALUES('Buffy','Dog','f','2009');

DELETE FROM pet WHERE `name` = 'Buffy' OR `name` = 'Chirpy';
# 4. 添加字段:主人的生日owner_birth DATE类型。
ALTER TABLE pet 
ADD owner_birth DATE;
# 5. 将名称为Claws的猫的主人改为kevin
UPDATE pet SET owner = 'kevin'
WHERE `name` = 'Claws';
# 6. 将没有死的狗的主人改为duck
UPDATE pet SET `owner` = 'duck'
WHERE `owner` IS NOT NULL;
# 7. 查询没有主人的宠物的名字；
SELECT `name`
FROM pet 
WHERE `owner` IS NULL;
# 8. 查询已经死了的cat的姓名，主人，以及去世时间；
SELECT `name`,`owner`,death
FROM pet 
WHERE death IS NOT NULL;
# 9. 删除已经死亡的狗
DELETE FROM pet 
WHERE death IS NOT NULL;
# 10. 查询所有宠物信息
SELECT *
FROM pet;

# 1. 使用已有的数据库dbtest11
USE dbtest11;
# 2. 创建表employee，并添加记录：
 /*
  id    name     sex tel          addr    salary
10001   张一一    男 13456789000 山东青岛 1001.58
10002   刘小红    女 13454319000 河北保定 1201.21
10003   李四      男 0751-1234567 广东佛山 1004.11
10004   刘小强    男 0755-5555555 广东深圳 1501.23
10005   王艳      女 020-1232133 广东广州 1405.16

*/
 
CREATE TABLE employee(
  id INT,
  name VARCHAR(8),
  sex VARCHAR(2),
  tel VARCHAR(20),
  addr VARCHAR(10),
  salary DECIMAL(9,2)
  );
DESCRIBE employee;
INSERT INTO employee(id,name,sex,tel,addr,salary)
VALUES(10001,'张一一','男',' 13456789000',' 山东青岛', 1001.58),
(10002,'刘小红','女',' 13454319000',' 河北保定' ,1201.21),
(10003 ,'李四','男',' 0751-1234567',' 广东佛山', 1004.11),
(10004,'刘小强','男','0755-5555555','广东深圳', 1501.23),
(10005,'王艳','女', '020-1232133', '广东广州', 1405.16);

# 3. 查询出薪资在1200~1300之间的员工信息。
SELECT *
FROM employee 
WHERE salary BETWEEN 1200 AND 1300;
# 4. 查询出姓“刘”的员工的工号，姓名，家庭住址。
SELECT id,`name`,addr 
FROM employee 
WHERE `name` LIKE '刘%';
# 5. 将“李四”的家庭住址改为“广东韶关”
UPDATE employee SET addr = '广东韶关'
WHERE `name` = '李四';
# 6. 查询出名字中带“小”的员工
SELECT *
FROM employee 
WHERE `name` LIKE '%小%';




# 1、创建数据库test01_library
CREATE DATABASE IF NOT EXISTS test01_library CHARACTER SET 'utf8';
USE test01_library;
# 2、创建表 books，表结构如下：
/*
  字段名   字段说明    数据类型
    id      书编号     INT
    name    书名       VARCHAR(50)
    authors 作者       VARCHAR(100)
    price   价格       FLOAT
    pubdate 出版日期   YEAR
    note    说明       VARCHAR(100)
    num     库存       INT

*/
CREATE TABLE books(
  id INT,
  `name` VARCHAR(50),
  author VARCHAR(100),
  price DECIMAL(10,3),
  pubdate YEAR,
  note VARCHAR(100),
  num INT
  );

# 3、向books表中插入记录
    # 1）不指定字段名称，插入第一条记录
    INSERT INTO books
    VALUES(1 ,'Tal of AAA','Dickes',23,1995,'novel',11);
    # 2）指定所有字段名称，插入第二记录
    INSERT INTO books(id,name,author,price,pubdate,note,num)
    VALUES(2 ,'EmmaT','Jane lura', 35,1993,'joke',22);
    # 3）同时插入多条记录（剩下的所有记录）
    INSERT INTO books(id,name,author,price,pubdate,note,num)
    VALUES(3 ,'Story of Jane','Jane Tim' ,40 ,2001 ,'novel', 0),
          (4 ,'Lovey Day George', 'Byron', 20, 2005, 'novel', 30),
          (5 ,'Old land Honore','Blade', 30, 2010, 'law', 0),
          (6 ,'The Battle Upton','Sara' ,30, 1999, 'medicine' ,40),
          (7 ,'Rose Hood', 'Richard haggard', 28, 2008 ,'cartoon' ,28);
          SELECT *
          FROM books;
/*
1 ,Tal of AAA,Dickes,23,1995,novel,11
2 ,EmmaT,Jane lura, 35,1993,joke,22
3 ,Story of Jane,Jane,Tim ,40 ,2001 ,novel, 0
4 ,Lovey Day George, Byron, 20, 2005, novel, 30
5 ,Old land Honore, Blade, 30, 2010, law, 0
6 ,The Battle Upton, Sara ,30, 1999, medicine ,40
7 ,Rose Hood, Richard haggard, 28, 2008 ,cartoon ,28

*/
# 4、将小说类型(novel)的书的价格都增加5。
UPDATE books SET price = price + 5
WHERE note = 'novel';
# 5、将名称为EmmaT的书的价格改为40，并将说明改为drama。
UPDATE books SET price = 40,note = 'drama'
WHERE name = 'EmmaT';
# 6、删除库存为0的记录。
DELETE FROM books
WHERE num = 0;
# 7、统计书名中包含a字母的书
SELECT COUNT(*)
FROM books
WHERE name LIKE '%a%';
# 8、统计书名中包含a字母的书的数量和库存总量
SELECT SUM(num)
FROM books
WHERE name LIKE '%a%';
# 9、找出“novel”类型的书，按照价格降序排列
SELECT *
FROM books
WHERE note = 'novel'
ORDER BY price DESC;
# 10、查询图书信息，按照库存量降序排列，如果库存量相同的按照note升序排列
SELECT *
FROM books
ORDER BY num DESC,note ASC;
# 11、按照note分类统计书的数量
SELECT SUM(num),note 
FROM books
GROUP BY note;
# 12、按照note分类统计书的库存量，显示库存量超过30本的
SELECT SUM(num),note 
FROM books
GROUP BY note
HAVING SUM(num) > 30;
# 13、查询所有图书，每页显示5本，显示第二页
SELECT *
FROM books
LIMIT 5,10;
# 14、按照note分类统计书的库存量，显示库存量最多的
SELECT SUM(num),note 
FROM books
GROUP BY note
ORDER BY sum(num) DESC
LIMIT 0,1;
# 15、查询书名达到10个字符的书，不包括里面的空格
SELECT *
FROM books
WHERE CHAR_LENGTH(REPLACE(name,' ','')) > 10;

# 16、查询书名和类型，其中note值为novel显示小说，law显示法律，medicine显示医药，cartoon显示卡通，
#joke显示笑话
SELECT name "名称",CASE note 
	WHEN 'novel' THEN '小说'
  WHEN 'law' THEN '法律'
  WHEN 'medicine' THEN '医药'
  WHEN 'cartoon' THEN '卡通'
	ELSE '其他'
END "类型"
FROM books;

# 17、查询书名、库存，其中num值超过30本的，显示滞销，大于0并低于10的，显示畅销，为0的显示需要无货
SELECT name,num,CASE 
  WHEN num > 30 THEN '滞销'
  WHEN num > 0 AND num < 10 THEN '畅销'
  WHEN num = 0 THEN '无货'
  ELSE '正常'
  END "库存状态"
FROM books;

# 18、统计每一种note的库存量，并合计总量
SELECT SUM(num)
FROM books
GROUP BY note;

SELECT IFNULL(note,'合计总数') AS note,COUNT(*) FROM books GROUP BY note WITH ROLLUP;

# 19、统计每一种note的数量，并合计总量
# 20、统计库存量前三名的图书
SELECT *
FROM books
ORDER BY num DESC
LIMIT 0,3;
# 21、找出最早出版的一本书
SELECT *
FROM books
ORDER BY pubdate ASC
LIMIT 0,1;
# 22、找出novel中价格最高的一本书
SELECT *
FROM books
ORDER BY price DESC
LIMIT 0,1;
# 23、找出书名中字数最多的一本书，不含空格

SELECT *
FROM books
ORDER BY CHAR_LENGTH(REPLACE(name,' ','')) DESC
LIMIT 0,1;






