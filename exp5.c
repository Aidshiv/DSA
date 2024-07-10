/*Experiment 5:
Execute Aggregation operations:*/

//step 1

// Create a new database
use experiment5

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
  { name: "John", age: 25 },
  { name: "Jane", age: 28 },
  { name: "Bob", age: 30 },
  { name: "Alice", age: 32 },
  { name: "Michael", age: 35 },
  { name: "Emily", age: 30 },
  { name: "David", age: 38 },
  { name: "Sarah", age: 29 }
])


//step 4


// $avg
db.people.aggregate([{ $group: { _id: null, avgAge: { $avg: "$age" } } }])


//step 5

// $min
db.people.aggregate([{ $group: { _id: null, minAge: { $min: "$age" } } }])


//step 6

// $max
db.people.aggregate([{ $group: { _id: null, maxAge: { $max: "$age" } } }])


//step 7
// $push
db.people.aggregate([{ $group: { _id: null, allNames: { $push: "$name" } } }])

//step 8
// $addToSet
db.people.aggregate([{ $group: { _id: null, uniqueNames: { $addToSet: "$name" } } }])
