#1.Create Employee table containing all Records E_id, E_name, 
Age, Salary

CREATE TABLE Employee (
  E_id INT,
  E_name VARCHAR(50),
  Age INT,
  Salary DECIMAL(10,2)
);

#1a.

INSERT INTO Employee (E_id, E_name, Age, Salary)
VALUES
 (101, 'John Doe', 35, 5000.00),
 (102, 'Jane Smith', 28, 4500.00),
 (103, 'Michael Johnson', 42, 4000.00),
 (104, 'Emily Brown', 31, 3800.00),
 (105, 'David Lee', 25, 2500.00),
 (106, 'Sarah Williams', 38, 4200.00),
 (107, 'Robert Davis', 29, 3900.00);


#2. Count number of employee names from employeetable



SELECT COUNT(E_name) AS TotalEmployees
FROM Employee;


#3.  Find the Maximum age from employee table.

SELECT MAX(Age) AS MaxAge
FROM Employee;



#4. Find the Minimum age from employeetable.


SELECT MIN(Age) AS MinAge
FROM Employee;



#5.Find salaries of employee in Ascending Order.

SELECT Salary
FROM Employee
ORDER BY Salary ASC;


#6.Find grouped salaries of employees.

SELECT Salary, COUNT(*) AS EmployeeCount
FROM Employee
GROUP BY Salary
ORDER BY Salary;
