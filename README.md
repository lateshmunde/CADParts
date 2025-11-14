class Material -> from this 2 classes are inherited,metal and ceramic 
(we can inherit more as per out requirement)

Structure of classes
Material.h / Material.cpp

Parts.h / Parts.cpp ( Abstract/ Pure virtual)
|
|-- Flange.h / Flange.cpp
|-- Pipe.h / Pipe.cpp
|-- Valve.h / Valve.cpp
|-- Elbow.h / Elbow.cpp

Manager.h/ Manager.cpp

- All .h(headers) file conatains in headers folder
- All .cpp(source) file conatains in src folder

About classes:
Material class : contains name of material and its component , 
what that material is made of, as material can be alloy, ceramic,etc

Parts class(Parent) : 
data members(all protected, can accesed by derived classes) 
: name, ID(unique), material, diameter.
this class is abstract as "display" is pure virtual function.
other memebr functions are getters abd setters for data memebrs,
they will be inherited to child classes.
static variable and function is present to keep track of nunber of parts

4 child classes:
all has private members, getters and setters to access them, 
Pipe :data members : length, thickness
Flange : data members : length, max strength
Elbow : data members : angle, corner radius
Valve : data members : type, presure limit

Manager Class
It containd menu and all working things
It does all works of displaying, creation and stroing of object






