#1.Creating the Employee table

CREATE TABLE Employee (
  EMPNO INT,
  ENAME VARCHAR(50),
  JOB VARCHAR(50),
  MANAGER_NO INT,
  SAL DECIMAL(10, 2),
  COMMISSION DECIMAL(10, 2)
);


#2.  Creating a user and granting permissions


CREATE USER 'po'@'localhost' IDENTIFIED BY 'root';
GRANT ALL PRIVILEGES ON mysql.* TO 'po'@'localhost';


#3.Inserting three records into the Employee table

INSERT INTO Employee (EMPNO, ENAME, JOB, MANAGER_NO, SAL, COMMISSION) VALUES
(1, 'John Doe', 'Manager', NULL, 50000.00, 1000.00),
(2, 'Jane Smith', 'Assistant', 1, 40000.00, 800.00),
(3, 'Michael Johnson', 'Clerk', 2, 30000.00, 600.00);


#3a.
START TRANSACTION;

#3b.
DELETE FROM Employee WHERE EMPNO = 1;

#3c.
SELECT * FROM Employee;

#3d.
ROLLBACK;

#3e.
SELECT * FROM Employee;



#4.Adding primary key constraint and not null constraint

ALTER TABLE Employee
ADD CONSTRAINT pk_Employee PRIMARY KEY (EMPNO),
MODIFY EMPNO INT NOT NULL,
MODIFY ENAME VARCHAR(50) NOT NULL,
MODIFY JOB VARCHAR(50) NOT NULL,
MODIFY SAL DECIMAL(10, 2) NOT NULL;

#4a.
desc Employee;




#5.Inserting null values to the Employee table

INSERT INTO Employee (EMPNO, ENAME, JOB, MANAGER_NO, SAL, COMMISSION) VALUES
(NULL, NULL, NULL, NULL, NULL, NULL);

#5a.
SELECT * FROM Employee;


