#1.Creating the Employee table

CREATE TABLE Employee (
  EMPNO INT,
  ENAME VARCHAR(50),
  JOB VARCHAR(50),
  MGR INT,
  SAL DECIMAL(10,2)
);


#2. Add a column commission with domain to the Employee table.



ALTER TABLE Employee
ADD COLUMN COMMISSION DECIMAL(10,2);


#3. Insert any five records into the table.

INSERT INTO Employee (EMPNO, ENAME, JOB, MGR, SAL, COMMISSION)
VALUES
 (101, 'John Doe', 'Manager', NULL, 5000.00, 500.00),
 (102, 'Jane Smith', 'Developer', 101, 4500.00, 400.00),
 (103, 'Michael Johnson', 'Analyst', 101, 4000.00, 300.00),
 (104, 'Emily Brown', 'Designer', 102, 3800.00, 250.00),
 (105, 'David Lee', 'Intern', 103, 2500.00, 150.00);





#4. Update the column details of job


UPDATE Employee
SET JOB = 'Senior Manager'
WHERE EMPNO = 101;

UPDATE Employee
SET JOB = 'Senior Developer'
WHERE EMPNO = 102;

UPDATE Employee
SET JOB = 'Senior Analyst'
WHERE EMPNO = 103;

UPDATE Employee
SET JOB = 'Senior Designer'
WHERE EMPNO = 104;

UPDATE Employee
SET JOB = 'Associate Intern'
WHERE EMPNO = 105;
#4a.
desc Employee;




#5.Rename the column of Employ table using alter command.

ALTER TABLE Employee
RENAME COLUMN EMPNO TO Employee_ID;


#6.Delete the employee whose Empno is 105

DELETE FROM Employee
WHERE Employee_ID = 105;
