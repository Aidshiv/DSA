create table Flight
(
Flight_number varchar(10),
airline char(10),
departure_airport char(50),
destination_airport char(50),
departure_date_time varchar(20),
arrival_date_time varchar(20),
seat_capacity int(10),
ticket_price int(10) not null,
primary key(Flight_number)
);


insert into flight values('234dge','indigo','mangalore','kochi','2024-01-15 5:25:00','2024-01-15 7:25:00',300,400000);


create table Passenger
(
Passenger_id varchar(10),
name char(10),
dob varchar(20),
gender char(10),
nationality char(10),
passenger_number int,
contact_number int,
email varchar(30),
address varchar(50),
primary key(Passenger_id)
);


create table booking
(
Passenger_ID varchar(10),
booking_id varchar(10),
flight_number varchar(10),
booking_date_time timestamp,
primary_status char(10),
total_fair int,
primary key(Passenger_ID),
foreign key(Passenger_ID) references Passenger(Passenger_id)
);


create table seat
(
seat_id varchar(10),
flight_number varchar(10),
seat_number int not null,
seat_class char(10),
availability char(10),
primary key(seat_id)
);


create table airport
(
airport_code varchar(10),
airport_name char(10),
location varchar(10),
counrty char(10) default 'India',
time_zone time,
primary key(airport_code)
);


create table payment
(
payment_ID varchar(10),
booking_ID varchar(10),
payment_date_time timestamp,
payment_method char(10),
amount int,
primary key(payment_ID),
foreign key(booking_ID) references booking(booking_ID)
);


create table flightcrew
(
crew_ID varchar(10),
name char(10),
DOB int(10),
gender char(10),
position char(10),
contact_number int(10),
email varchar(10),
address varchar(10)
);