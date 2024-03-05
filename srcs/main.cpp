#include <iostream>
#include <Json.hpp>

int	main(void)
{
	Json	test;
	test[0] = "haha";
	test[false] = "false";

	std::vector<std::string> vector;

	vector.push_back("hector");
	vector.push_back("le");
	vector.push_back("vector");

	Json	json;

	json["type"] = "Gugus";
	json["happy"] = true;
	json["x"] = 42.42f;
	json["y"] = 69.69f;
	json["test"] = test;
	json["vector"] = vector;

	std::cout << "JSON\n" << json << std::endl;

	return (0);
}
