/*Experiment 4:
Create and demonstrate how projection operators would be used:*/

//step 1 (a)

// Create a new database
use experiment4

// Create a new collection
db.createCollection("students2")


//step2

// Show databases
show dbs

// Show collections
show collections  


//step 3 
// Insert documents
db.students2.insertMany([
  {
    _id: 1,
    name: "John",
    grades: [
      { score: 90, grade: "A" },
      { score: 80, grade: "B" },
      { score: 95, grade: "A" }
    ]
  },
  {
    _id: 2,
    name: "Jane",
    grades: [
      { score: 85, grade: "B" },
      { score: 92, grade: "A" },
      { score: 88, grade: "B" }
    ]
  },
  {
    _id: 3,
    name: "Bob",
    grades: [
      { score: 78, grade: "C" },
      { score: 95, grade: "A" },
      { score: 92, grade: "A" }
    ]
  }
])





//step 4


// $ projection operator
db.students2.find({}, { grades: 1 })



//step 5

// $elemMatch projection operator
db.students.find({}, { grades: { $elemMatch: { score: { $gt: 80 } } } })


//step 6

// $slice projection operator
db.students2.find({}, { grades: { $slice: 2 } })
