-- SELECT 
--     Person.firstName,
--     Person.lastName,
--     Address.city,
--     Address.state
-- FROM Person
-- LEFT JOIN Address
-- ON Person.personId = Address.personId;

select p.firstName,p.lastName,a.city,a.state from Person as p LEFT JOIN Address as a on p.personId=a.personId

