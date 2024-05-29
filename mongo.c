
1. Overview
In this t, we’llutorial explore the Geospatial support in MongoDB.
We’ll discuss how to store geospatial data, geo indexing, and geospatial search. We’ll also use multiple geospatial search queries like near, geoWithin, and geoIntersects.
2. Storing Geospatial Data
First, let’s see how to store geospatial data in MongoDB.
MongoDB supports multiple GeoJSON types to store geospatial data. Throughout our examples, we’ll mainly use the Point and Polygon types.
2.1. Point
This is the most basic and common GeoJSON type, and it’s used to represent one specific point on the grid.
Here, we have a simple object, in our places collection, that has field location as a Point:
{
  "name": "Big Ben",
  "location": {
    "coordinates": [-0.1268194, 51.5007292],
    "type": "Point"
  }
}
Note that the longitude value comes first, then the latitude.
2.2. Polygon
Polygon is a bit more complex GeoJSON type.
We can use Polygon to define an area with its exterior borders and also interior holes if needed.
Let’s see another object that has its location defined as a Polygon:
{
  "name": "Hyde Park",
  "location": {
    "coordinates": [
      [
        [-0.159381, 51.513126],
        [-0.189615, 51.509928],
        [-0.187373, 51.502442],
        [-0.153019, 51.503464],
        [-0.159381, 51.513126]
      ]
    ],
    "type": "Polygon"
  }
}
In this example, we defined an array of points that represent exterior bounds. We also have to close the bound so that the last point equals the first point.
Note that we need to define the exterior bounds points in counterclockwise direction and hole bounds in a clockwise direction.
In addition to these types, there are also many other types like LineString, MultiPoint, MultiPolygon, MultiLineString, and GeometryCollection.
3. Geospatial Indexing
To perform search queries on the geospatial data we stored, we need to create a geospatial index on our location field.
We basically have two options: 2d and 2dsphere.
But first, let’s define our places collection:
MongoClient mongoClient = new MongoClient();
MongoDatabase db = mongoClient.getDatabase("myMongoDb");
collection = db.getCollection("places");
3.1. 2d Geospatial Index
The 2d index enables us to perform search queries that work based on 2d plane calculations.
We can create a 2d index on the location field 
Of course, we can do the same in the mongo shell:
db.places.createIndex({location:"2d"})
3.2. 2dsphere Geospatial Index
The 2dsphere index supports queries that work based on sphere calculations.
Or in the mongo shell:
db.places.createIndex({location:"2dsphere"})
4. Searching Using Geospatial Queries
let’s search for objects based on their location using geospatial queries
4.1. Near Query
Let’s start with near. We can use the near query to search for places within a given distance.
The near query works with both 2d and 2dsphere indices.
In the next example, we’ll search for places that are less than 1 km and more than 10 meters away from the given position:
And the corresponding query in the mongo shell:
db.places.find({
  location: {
    $near: {
      $geometry: {
        type: "Point",
        coordinates: [-0.126821, 51.495885]
      },
      $maxDistance: 1000,
      $minDistance: 10
    }
  }
})
Note that the results are sorted from nearest to farthest.
Similarly, if we use a very far away location, we won’t find any nearby places:
We also have the nearSphere method, which acts exactly like near, except it calculates the distance using spherical geometry.
4.2. Within Query
Next, we’ll explore the geoWithin query.
The geoWithin query enables us to search for places that fully exist within a given Geometry, like a circle, box, or polygon. This also works with both 2d and 2dsphere indices.
In this example, we’re looking for places that exist within a 5 km radius from the given center position:
Note that we need to transform the distance from km to radian (just divide by Earth’s radius).
And the resulting query:
db.places.find({
  location: {
    $geoWithin: {
      $centerSphere: [
        [-0.1435083, 51.4990956],
        0.0007848061528802386
      ]
    }
  }
})
Next, we’ll search for all places that exist within a rectangle “box”. We need to define the box by its lower left position and upper right position:

Here’s the corresponding query in mongo shell:
db.places.find({
  location: {
    $geoWithin: {
      $box: [
        [-0.1427638, 51.4991288],
        [-0.1256209, 51.5030272]
      ]
    }
  }
})
Finally, if the area we want to search within isn’t a rectangle or a circle, we can use a polygon to define a more specific area:
And here’s the corresponding query:
db.places.find({
  location: {
    $geoWithin: {
      $polygon: [
        [-0.1439, 51.4952],
        [-0.1121, 51.4989],
        [-0.13, 51.5163],
        [-0.1439, 51.4952]
      ]
    }
  }
})
We only defined a polygon with its exterior bounds, but we can also add holes to it. Each hole will be a List of Points:
geoWithinPolygon("location", points, hole1, hole2, ...)
4.3. Intersect Query
Finally, let’s look at the geoIntersects query.
The geoIntersects query finds objects that at least intersect with a given Geometry. By comparison, geoWithin finds objects that fully exist within a given Geometry.
This query works with the 2dsphere index only.
Let’s see this in practice, with an example of looking for any place that intersects with a Polygon:
    

The resulting query:
db.places.find({
  location:{
    $geoIntersects:{
      $geometry:{
        type:"Polygon",
          coordinates:[
          [
            [-0.1439, 51.4952],
            [-0.1346, 51.4978],
            [-0.2177, 51.5135],
            [-0.1439, 51.4952]
          ]
        ]
      }
    }
  }
})