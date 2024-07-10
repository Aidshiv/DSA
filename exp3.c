/*Experiment 3:
a. Execute query selectors (comparison selectors, logical selectors):
b. Execute query selectors (Geospatial selectors, Bitwise selectors):*/

//step 1 (a)

// Create a new database
use experiment3

// Create a new collection
db.createCollection("people1")


//step2

// Show databases
show dbs

// Show collections
show collections


//step 3
db.people1.createIndex({ location: "2dsphere" })

//step 4
// Insert documents
db.people1.insertMany([
  { name: "John", age: 25, gender: "male", location: { type: "Point", coordinates: [ -73.9667, 40.78 ] }, flags: 4 },
  { name: "Jane", age: 28, gender: "female", location: { type: "Point", coordinates: [ -73.9667, 40.79 ] }, flags: 2 },
  { name: "Bob", age: 40, gender: "male", location: { type: "Point", coordinates: [ -73.9667, 40.80 ] }, flags: 8 },
  { name: "Alice", age: 32, gender: "female", location: { type: "Point", coordinates: [ -73.9667, 40.81 ] }, flags: 1 },
  { name: "Michael", age: 35, gender: "male", location: { type: "Point", coordinates: [ -73.9667, 40.82 ] }, flags: 6 },
  { name: "Emily", age: 30, gender: "female", location: { type: "Point", coordinates: [ -73.9667, 40.83 ] }, flags: 3 },
  { name: "David", age: 38, gender: "male", location: { type: "Point", coordinates: [ -73.9667, 40.84 ] }, flags: 9 },
  { name: "Sarah", age: 29, gender: "female", location: { type: "Point", coordinates: [ -73.9667, 40.85 ] }, flags: 5 }
])

//step 5


// Comparison selectors
db.people1.find({ age: { $gt: 30 } })

// Logical selectors
db.people.find({ $and: [{ age: { $gt: 25 } }, { gender: "male" }] })


//step 6 (b)

// Geospatial selectors
db.people1.find({ location: { $near: { $geometry: { type: "Point", coordinates: [ -73.9667, 40.78 ] }, $maxDistance: 1000 } } })

// Bitwise selectors
db.people1.find({ flags: { $bitsAllSet: 4 } })
