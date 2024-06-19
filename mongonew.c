**1. Display the marks scored by student named ram**

```
db.student.find({ name: "ram" }, { Marks: 1, _id: 0 })
```

**2. Display the details of tho student who scored the following marks [25, 35, 45, 12, 9 ].**

```
db.student.find({ Marks: [25, 35, 45, 12, 9] })
```

**3. Display the details of the student who scored the following marks [45, 12, 9,25,35] $all .**

```
db.student.find({ Marks: { $all: [45, 12, 9, 35] } })
```

**4. Display the first three marks for all students $slice Projection**

```
db.student.find({}, { Marks: { $slice: 3 }, _id: 0 });
```

**5. Display only the first mark in the array for all students $slice.**

```
db.student.find({}, { Marks: { $slice: 1 }, _id: 0 });
```

**6. Display the last subject marks for all students $slice .**

```
db.student.find({}, { Marks: { $slice: -1 }, _id: 0 });
```

**7. Display the marks scored in the first subject by student by name jeff $slice .**

```
db.student.find({ name: "jeff" }, { Marks: { $slice: 1 }, _id: 0 });
```

**8. Display the student who has only three scores $size.**

```
db.student.find({ Marks: { $size: 3 } }).pretty()
```