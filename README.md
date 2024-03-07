# Json lib
This is a librairy for json in c++

## Usage
You can create a json object by the class Json;

To access or set a value in json, you can use the [] operator, or the method .setContent(key, value)

The key can only be an std::string.

Value is a JsonContent. This is the class for any content in Json.
The supported types are :
 - (void *)0
 - std::nullptr
 - int
 - unsigned int
 - long
 - unsigned long
 - float
 - double
 - bool
 - char
 - char *
 - std::string
 - Json
 - std::vector<int>
 - std::vector<unsigned int>
 - std::vector<long>
 - std::vector<unsigned long>
 - std::vector<float>
 - std::vector<double>
 - std::vector<bool>
 - std::vector<char>
 - std::vector<std::string>
 - std::vector<Json>

Any list in Json will be a std::vector.

To access of a value, you can use the [] operator, or the method .getContent(key)

## String usage
You can use the method toString(indented) to have a string of your json.
intented parameter is a boolean.
If it's false, the json is in one line.
If it's true, the json is in multiple line with tabs to indent it.

To have a Json from a string, you can use the static method Json::parse(string).
You can use too the method .parseFromString(string) on a Json object. Warning, it will loose it's previous data.

Unsupported type :
 - list of list
 - implicit list. Any list need to be between []

## Exception
You will have an JsonParseError if the format isn't correct for my class.
You can have a JsonKeyError if the key doesn't exist with the getContent method. The [] operator will create a null content if the key doesn't exist.

You can have a JsonContentTypeError if you tried to asign a not supported type to a JsonContent.

## Prebuild feature
In a build, you have 3 sub folders :
- include, that contains the .hpp of the lib. You only need to include Json.hpp
- lib, that contains libjson.a
- bin, taht contains libjson.so and libjson.dll
