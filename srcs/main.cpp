#include <iostream>
#include <Json.hpp>

int	main(void)
{
	// Json	test;
	// test[0] = 0;
	// test[false] = false;
	// test['a'] = 'a';
	// test[42.0f] = 42.0f;
	// test[69.0] = 69.0;
	// test["id"] = "coucou";
	// test["path"] = "djksajdks";

	// std::vector<long> vecInt;
	// vecInt.push_back(0);
	// vecInt.push_back(1);
	// vecInt.push_back(-2);

	// std::vector<bool> vecBool;
	// vecBool.push_back(true);
	// vecBool.push_back(false);

	// std::vector<char> vecChar;
	// vecChar.push_back('a');
	// vecChar.push_back('@');

	// std::vector<float> vecFloat;
	// vecFloat.push_back(0.0f);
	// vecFloat.push_back(-12.3f);
	// vecFloat.push_back(238432849832904.0f);

	// std::vector<double> vecDouble;
	// vecDouble.push_back(0.0);
	// vecDouble.push_back(-3423.34);
	// vecDouble.push_back(324.25);

	// std::vector<std::string> vecString;
	// vecString.push_back("hector");
	// vecString.push_back("le");
	// vecString.push_back("vector");

	// std::vector<Json> vecJson;
	// vecJson.push_back(Json());

	// std::vector<long> vecEmpty;

	// Json	json;

	// json["0"] = 0;
	// json["10"] = 10;
	// json["-10"] = -10;
	// json["a"] = 'a';
	// json["@"] = '@';
	// json["true"] = true;
	// json["false"] = false;
	// json["0.0f"] = 0.0f;
	// json["42.42f"] = 42.42f;
	// json["-69.69f"] = -69.69f;
	// json["0.0"] = 0.0;
	// json["42.42"] = 42.42;
	// json["-69.69"] = -69.69;
	// json["json"] = test;
	// json["vecInt"] = vecInt;
	// json["vecBool"] = vecBool;
	// json["vecChar"] = vecChar;
	// json["vecFloat"] = vecFloat;
	// json["vecDouble"] = vecDouble;
	// json["vecString"] = vecString;
	// json["vecJson"] = vecJson;
	// json["vecEmpty"] = vecEmpty;
	// json["NULL0"];
	// json["NULL1"] = (void *)0;
	// json["NULL2"] = nullptr;
	// json["NULL"] = json["NULL0"];
	// json.setContent("uwu", 4);
	// json["uwuCpy"] = json.getContent("uwu");

	// std::string	strTest = json.toString(false);

	std::string	strTest = 	"{\n"
							"  \"test\" : [\n"
							"    {\"id\" : \"m-btn-off\", \"path\" : \"ui/btn\"},\n"
							"    {\"id\" : \"m-btn-on\", \"path\" : \"ui/btn2\"}\n"
							"  ]\n"
							"}\n";

	std::cout << "JSON STR\n" << strTest << "\n" << std::endl;

	try
	{
		Json jsonParse = Json::parse(strTest);
		std::cout << "\nJSON PARSE\n" << jsonParse << std::endl;
		// std::cout << "JSON EQUALITY TEST : " << (json == jsonParse) << std::endl;
		// json.parseFromString(test.toString(false));
		// std::cout << "\nJSON PARSE TEST\n" << json << std::endl;
		// std::cout << "JSON EQUALITY TEST : " << (json == jsonParse) << std::endl;
	}
	catch (JsonParseError e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
