/*Experiment 2:
a. Develop a MongoDB query to select certain fields and ignore some
fields of the documents:
b. Develop a MongoDB query to display the first 5 documents:*/

//step 1 (a)

// Create a new database
use experiment2

// Create a new collection
db.createCollection("people")



//step2

// Show databases
show dbs

// Show collections
show collections



//step 3 
// Insert documents
db.people.insertMany([
  { name: "John", age: 25, gender: "male", occupation: "Developer" },
  { name: "Jane", age: 28, gender: "female", occupation: "Designer" },
  { name: "Bob", age: 40, gender: "male", occupation: "Manager" },
  { name: "Alice", age: 32, gender: "female", occupation: "Engineer" },
  { name: "Michael", age: 35, gender: "male", occupation: "Consultant" },
  { name: "Emily", age: 30, gender: "female", occupation: "Teacher" },
  { name: "David", age: 38, gender: "male", occupation: "Lawyer" },
  { name: "Sarah", age: 29, gender: "female", occupation: "Doctor" }
])


//step 4


// Select certain fields and ignore some fields
db.people.find({}, { name: 1, age: 1, _id: 0 })



//step 5 (b)

// Display the first 5 documents
db.people.find().limit(5)
