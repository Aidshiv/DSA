Experiment 1:

a. Illustration of Where Clause, AND, OR operations in MongoDB:
b. Execute the Commands of MongoDB and operations in MongoDB:


//step 1 (a)

// Create a new database
use experiment1

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
  { name: "John", age: 25, gender: "male" },
  { name: "Jane", age: 28, gender: "female" },
  { name: "Bob", age: 40, gender: "male" },
  { name: "Alice", age: 32, gender: "female" }
])



//step 4


// Find documents where age is greater than 25 and gender is "male"
db.people.find({ $and: [{ age: { $gt: 25 } }, { gender: "male" }] })

// Find documents where age is greater than 30 or gender is "female"
db.people.find({ $or: [{ age: { $gt: 30 } }, { gender: "female" }] })



//step 5 (b)

// Insert document
db.people.insertOne({ name: "Michael", age: 35, gender: "male" })

// Query document
db.people.find({ age: { $gt: 30 } })

// Update document
db.people.updateOne({ name: "John" }, { $set: { age: 40 } })

// Delete document
db.people.deleteOne({ name: "John" })

// Projection
db.people.find({}, { name: 1, age: 1 })
