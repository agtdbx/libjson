#include <Json.hpp>
#include <limits.h>

////////////////////////////////////////////////////////////////////////////////
// Static functions
////////////////////////////////////////////////////////////////////////////////
static std::string	strPos(int lign, int col)
{
	return "Ln " + std::to_string(lign) + ", Col " + std::to_string(col + 1);
}


static bool	strContains(std::string &str, char c)
{
	for (std::size_t i = 0; i < str.size(); i++)
		if (str[i] == c)
			return (true);
	return (false);
}


static bool	strContainsNotInSubstr(std::string &str, char c)
{
	bool	inSubstr = false;
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '"')
			inSubstr = !inSubstr;
		if (str[i] == c && !inSubstr)
			return (true);
	}
	return (false);
}


static jsonType	checkNumber(std::string &str, int lign, int col)
{
	bool	dotPassed = false;
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if ((str[i] == '+' || str[i] == '-'))
		{
			if (str.size() == 1 || i != 0)
			{
				std::string	error = "";
				error = str[i];
				throw JsonParseError(error + " in number on "
										+ strPos(lign, col + i - 1));
			}
		}
		else if (str[i] == '.')
		{
			if (dotPassed || i == str.size() - 1)
			{
				throw JsonParseError("Incorrect dot in number on "
									+ strPos(lign, col + i - 1));
			}
			dotPassed = true;
		}
		else if (str[i] == 'f')
		{
			if (!dotPassed || i != str.size() - 1)
			{
				throw JsonParseError("Incorrect f in number on "
									+ strPos(lign, col + i - 1));
			}
		}
		else if (str[i] < '0' || str[i] > '9')
		{
			std::string	error = "";
			error = str[i];
			throw JsonParseError(error + " in number on "
									+ strPos(lign, col + i - 1));
		}
	}
	if (dotPassed)
	{
		if (str[str.size() - 1] == 'f')
			return jTypeFloat;
		return jTypeDouble;
	}
	return jTypeInt;
}


static jsonType	getTypeOfContent(std::string &content, int lign, int i)
{
	if (content.size() == 0)
	{
		throw JsonParseError("Empty content on "
								+ strPos(lign, i - 1));
	}

	// Content is a char
	if (content[0] == '\'')
	{
		if (content.size() == 1 || content[content.size() - 1] != '\'')
			throw JsonParseError("Char not close on "
								+ strPos(lign, i - 1));
		else if (content.size() == 2)
			throw JsonParseError("Char empty on "
								+ strPos(lign, i - 1));
		else if (content.size() > 3)
			throw JsonParseError("Char have more than 1 character on "
								+ strPos(lign, i - 1));
		return (jTypeChar);
	}
	// Content is a string
	else if (content[0] == '"')
	{
		if (content.size() == 1 || content[content.size() - 1] != '"')
			throw JsonParseError("String not close on "
								+ strPos(lign, i - 1));
		return (jTypeString);
	}
	// Content is a number
	else if (content[0] == '-' || content[0] == '+' ||
			(content[0] >= '0' && content[0] <= '9'))
	{
		return (checkNumber(content, lign, i));
	}
	// Content is a list
	else if (content[0] == '[')
	{
		throw JsonParseError("List of list not supported on "
								+ strPos(lign, i - 1));
	}
	// Content is a json
	else if (content[0] == '{')
	{
		return (jTypeJson);
	}
	// Content is a bool
	else if (content == "true" || content == "false")
	{
		return (jTypeBool);
	}
	// Content is Null
	else if (content == "Null")
	{
		return (jTypeNull);
	}
	// Content is unknow
	else
	{
		throw JsonParseError("Unknow content type on "
								+ strPos(lign, i - 1));
	}
}


static bool	isLongOverflow(std::string &str)
{
	std::string overflow = "9223372036854775807";
	if (str[0] == '-')
		overflow = "-9223372036854775808";
	else if (str[0] == '+')
		overflow = "+9223372036854775807";

	if (overflow.size() > str.size())
		return (false);
	else if (overflow.size() < str.size())
		return (true);

	for (std::size_t i = 0; i < str.size(); i++)
		if (overflow[i] < str[i])
			return (true);

	return (false);
}


static std::string	removeWhiteSpace(std::string &str)
{
	int	size = str.size();
	int	start = 0;
	int end = size - 1;

	while (start < size)
	{
		if (str[start] != ' ' && str[start] != '\t' && str[start] != '\n')
			break;
		start++;
	}

	while (end >= start)
	{
		if (str[end] !=  ' ' && str[end] != '\t' && str[end] != '\n')
			break;
		end--;
	}

	return (str.substr(start, end - start + 1));
}


static std::vector<std::string>	split(std::string &str, char c)
{
	std::vector<std::string>	vector;

	int	size = str.size();
	int	start = 0;
	int	len = 0;
	bool	inString = false;

	while (start < size)
	{
		len = 0;
		while (start + len < size)
		{
			if (str[start + len] == '"')
				inString = !inString;
			if (str[start + len] == c && !inString)
				break;
			len++;
		}

		vector.push_back(str.substr(start, len));
		start += len;
		start++;
	}

	return (vector);
}


////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
Json::Json( void )
{

}


Json::Json(const Json &json)
{
	this->data = json.data;
}


Json::~Json( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters
////////////////////////////////////////////////////////////////////////////////
JsonContent	&Json::getContent(std::string &key)
{
	JsonContent	*content = NULL;
	try
	{
		content = &this->data.at(key);
	}
	catch (std::exception e)
	{
		throw JsonKeyError();
	}
	return (*content);
}


////////////////////////////////////////////////////////////////////////////////
// Setters
////////////////////////////////////////////////////////////////////////////////
void	Json::setContent(std::string key, JsonContent content)
{
	this->data[key] = content;
}


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
Json	&Json::operator=(Json const &json)
{
	if (this == &json)
		return (*this);

	this->data = json.data;

	return (*this);
}

JsonContent	&Json::operator[](int key)
{
	std::string realKey = std::to_string(key);
	try
	{
		JsonContent	&content = this->data[realKey];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[realKey] = content;
		return this->data[realKey];
	}
}

JsonContent	&Json::operator[](unsigned int key)
{
	std::string realKey = std::to_string(key);
	try
	{
		JsonContent	&content = this->data[realKey];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[realKey] = content;
		return this->data[realKey];
	}
}

JsonContent	&Json::operator[](long key)
{
	std::string realKey = std::to_string(key);
	try
	{
		JsonContent	&content = this->data[realKey];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[realKey] = content;
		return this->data[realKey];
	}
}

JsonContent	&Json::operator[](unsigned long key)
{
	std::string realKey = std::to_string(key);
	try
	{
		JsonContent	&content = this->data[realKey];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[realKey] = content;
		return this->data[realKey];
	}
}

JsonContent	&Json::operator[](bool key)
{
	std::string realKey = "false";
	if (key)
		realKey = "true";
	try
	{
		JsonContent	&content = this->data[realKey];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[realKey] = content;
		return this->data[realKey];
	}
}

JsonContent	&Json::operator[](char key)
{
	std::string realKey;
	realKey += key;
	try
	{
		JsonContent	&content = this->data[realKey];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[realKey] = content;
		return this->data[realKey];
	}
}

JsonContent	&Json::operator[](float key)
{
	std::string realKey = std::to_string(key);
	try
	{
		JsonContent	&content = this->data[realKey];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[realKey] = content;
		return this->data[realKey];
	}
}

JsonContent	&Json::operator[](double key)
{
	std::string realKey = std::to_string(key);
	try
	{
		JsonContent	&content = this->data[realKey];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[realKey] = content;
		return this->data[realKey];
	}
}

JsonContent	&Json::operator[](char const *key)
{
	std::string realKey = std::string(key);
	try
	{
		JsonContent	&content = this->data[realKey];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[realKey] = content;
		return this->data[realKey];
	}
}

JsonContent	&Json::operator[](std::string key)
{
	try
	{
		JsonContent	&content = this->data[key];
		return (content);
	}
	catch (std::exception e)
	{
		JsonContent content;

		this->data[key] = content;
		return this->data[key];
	}
}


std::ostream	&operator<<(std::ostream &os, Json &json)
{
	os << json.toStringIndented(0);
	return (os);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////
std::string	Json::toString(bool indented)
{
	if (indented)
		return (this->toStringIndented(0));
	return (this->toStringOneLine());
}


std::string	Json::toStringOneLine(void)
{
	std::string	print = "{";

	std::map<std::string, JsonContent>::iterator it = this->data.begin();

	bool	start = true;
	while (it != this->data.end())
	{
		if (start)
			start = false;
		else
		{
			print += ", ";
		}
		print += "\"" + it->first + "\" : " + it->second.toStringOneLine();
		it++;
	}

	print += "}";
	return (print);
}


std::string	Json::toStringIndented(int indentLevel)
{
	if (this->data.size() == 0)
		return ("{}");

	std::string	print = "{\n";
	indentLevel++;

	std::map<std::string, JsonContent>::iterator it = this->data.begin();

	bool	start = true;
	while (it != this->data.end())
	{
		if (start)
			start = false;
		else
		{
			print += ",\n";
		}
		for (int i = 0; i < indentLevel; i++)
			print += "\t";
		print += "\"" + it->first + "\" : " +
					it->second.toStringIndented(indentLevel);
		it++;
	}

	indentLevel--;
	print += "\n";
	for (int i = 0; i < indentLevel; i++)
		print += "\t";
	print += "}";
	return (print);
}


void	Json::parseFromString(std::string str)
{
	std::map<std::string, JsonContent>	newData;
	int	size = str.size();
	int	lign = 1;
	int i = 0;
	int iEND = 0;
	int	len = 0;
	bool	inString = false;
	int	containerLevel = 0;
	while (i < size)
	{
		// Get the start of the json
		while (i < size)
		{
			if (str[i] == '"')
				inString = !inString;
			if (str[i] == '\n')
				lign++;
			if (str[i] == '{' && !inString)
				break;
			i++;
		}
		if (i == size)
			throw JsonParseError("No json in string");


		// Get the start of the key
		std::cout << "Start of json" << std::endl;
		while (i < size && str[i] != '"' && str[i] != '}')
		{
			if (str[i] == '\n')
				lign++;
			i++;
		}
		if (i == size)
			throw JsonParseError("Unclose json on " + strPos(lign, i - 1));
		if (str[i] == '}') // The json is empty
		{
			std::cout << "Empty json\n";
			this->data = newData;
			return ;
		}

		// Get the end of the key
		i++;
		len = 0;
		std::string key;
		while (i + len < size && str[i + len] != '"')
		{
			if (str[i] == '\n')
				lign++;
			len++;
		}
		if (i + len == size)
			throw JsonParseError("Unclose string on " + strPos(lign, i - 1));

		key = str.substr(i, len);
		std::cout << "Key found : |" << key << "|\n";

		// Search the separator beetween
		i += len + 1;
		while (i < size)
		{
			if (str[i] == '"')
				inString = !inString;
			if (str[i] == '\n')
				lign++;
			if (str[i] == ':' && !inString)
				break;
			i++;
		}
		if (i == size || str[i] == '"')
			throw JsonParseError("Separator beetween key not found on "
									+ strPos(lign, i - 1));

		// Get the start of content
		i++;
		while (i < size)
		{
			if (str[i] == '\n')
				lign++;
			if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
				break;
			i++;
		}
		if (i == size || str[i] == ',' || str[i] == '}')
			throw JsonParseError("Missing content after key on "
									+ strPos(lign, i - 1));

		// Get the content
		len = 0;
		containerLevel = 0;
		while (i + len < size)
		{
			if (str[i + len] == '"')
				inString = !inString;
			else if (str[i + len] == '[' || str[i + len] == '{')
				containerLevel++;
			else if (str[i + len] == ']' || str[i + len] == '}')
				containerLevel--;
			else if (str[i + len] == '\n')
				lign++;
			if ((str[i + len] == ',' || str[i + len] == '}') && !inString
				&& containerLevel <= 0)
				break;
			len++;
		}
		if (i + len == size)
			throw JsonParseError("Missing content after key on "
									+ strPos(lign, i - 1));
		std::string	content = str.substr(i, len);
		std::cout << "Content found : |" << content << "|\n";
		iEND = i + len;

		//Remove whitespace after content
		len -= 1;
		while (len >= 0)
		{
			if (content[len] != ' ' && content[len] != '\n' && content[len] != '\t')
				break;
			len--;
		}
		content = content.substr(0, len + 1);
		std::cout << "Content trim : |" << content << "|\n";

		// Get the type of the content

		// Content is a char
		if (content[0] == '\'')
		{
			if (content.size() == 1 || content[content.size() - 1] != '\'')
				throw JsonParseError("Char not close on "
									+ strPos(lign, i - 1));
			else if (content.size() == 2)
				throw JsonParseError("Char empty on "
									+ strPos(lign, i - 1));
			else if (content.size() > 3)
				throw JsonParseError("Char have more than 1 character on "
									+ strPos(lign, i - 1));
			newData[key] = content[1];
		}
		// Content is a string
		else if (content[0] == '"')
		{
			if (content.size() == 1 || content[content.size() - 1] != '"')
				throw JsonParseError("String not close on "
									+ strPos(lign, i - 1));
			newData[key] = content.substr(1, content.size() - 2);
		}
		// Content is a number
		else if (content[0] == '-' || content[0] == '+'  ||
				(content[0] >= '0' && content[0] <= '9'))
		{
			jsonType	jtype = checkNumber(content, lign, i);

			if (jtype == jTypeFloat)
			{
				newData[key] = (float)atof(content.c_str());
			}
			else if (jtype == jTypeDouble)
			{
				newData[key] = atof(content.c_str());
			}
			else
			{
				if (isLongOverflow(content))
					throw JsonParseError("Int overflow on "
										+ strPos(lign, i - 1));
				newData[key] = atol(content.c_str());
			}
		}
		// Content is a list
		else if (content[0] == '[')
		{
			if (content[content.size() - 1] != ']')
				throw JsonParseError("List never close on "
									+ strPos(lign, i - 1));
			if (content.size() == 2)
			{
				std::vector<long>	vector;
				newData[key] = vector;
			}
			content = content.substr(1, content.size() - 2);
			std::cout << "List content : |" << content << "|\n";

			if (!strContainsNotInSubstr(content, ','))
			{
				std::string element = removeWhiteSpace(content);
				std::cout << "One element : |" << element << "|\n";

				if (element == "") // List empty
				{
					std::vector<long>	vector;
					newData[key] = vector;
				}
				else
				{
					jsonType	elementType = getTypeOfContent(element, lign, i);
					if (elementType == jTypeNull)
						throw JsonParseError("List not support Null on "
									+ strPos(lign, i - 1));
					else if (elementType == jTypeInt)
					{
						std::vector<long>	vector;
						vector.push_back(atol(element.c_str()));
						newData[key] = vector;
					}
					else if (elementType == jTypeFloat)
					{
						std::vector<float>	vector;
						vector.push_back(atof(element.c_str()));
						newData[key] = vector;
					}
					else if (elementType == jTypeDouble)
					{
						std::vector<double>	vector;
						vector.push_back(atof(element.c_str()));
						newData[key] = vector;
					}
					else if (elementType == jTypeBool)
					{
						std::vector<bool>	vector;
						if (element == "true")
							vector.push_back(true);
						else
							vector.push_back(false);
						newData[key] = vector;
					}
					else if (elementType == jTypeChar)
					{
						std::vector<char>	vector;
						vector.push_back(element[1]);
						newData[key] = vector;
					}
					else if (elementType == jTypeString)
					{
						std::vector<std::string>	vector;
						vector.push_back(element.substr(1, element.size()-2));
						newData[key] = vector;
					}
					else if (elementType == jTypeJson)
					{
						std::vector<Json>	vector;
						Json	json;
						json.parseFromString(element);
						vector.push_back(json);
						newData[key] = vector;
					}
					else
					{
						throw JsonParseError("Unkown type in list on "
									+ strPos(lign, i - 1));
					}
				}
			}
			else
			{
				std::cout << "Many elements\n";
				std::vector<std::string>	elements = split(content, ',');

				std::cout << "Element : |" << elements[0];
				std::string first = removeWhiteSpace(elements[0]);
				std::cout << "| -> |" << first << "|\n";

				jsonType	vectorType = getTypeOfContent(first, lign, i);

				if (vectorType == jTypeNull)
					throw JsonParseError("List not support Null on "
								+ strPos(lign, i - 1));
				else if (vectorType == jTypeInt)
				{
					std::vector<long>	vector;

					vector.push_back(atol(first.c_str()));
					for (std::size_t j = 1; j < elements.size(); j++)
					{
						std::cout << "Element : |" << elements[j];
						std::string element = removeWhiteSpace(elements[j]);
						std::cout << "| -> |" << element << "|\n";

						jsonType elementType = getTypeOfContent(element, lign, i);
						if (elementType != vectorType)
							throw JsonParseError("Bad type in vector<int> on "
									+ strPos(lign, i - 1));

						vector.push_back(atol(element.c_str()));
					}
					newData[key] = vector;
				}
				else if (vectorType == jTypeFloat)
				{
					std::vector<float>	vector;

					vector.push_back(atof(first.c_str()));
					for (std::size_t j = 1; j < elements.size(); j++)
					{
						std::cout << "Element : |" << elements[j];
						std::string element = removeWhiteSpace(elements[j]);
						std::cout << "| -> |" << element << "|\n";

						jsonType elementType = getTypeOfContent(element, lign, i);
						if (elementType != vectorType)
							throw JsonParseError("Bad type in vector<int> on "
									+ strPos(lign, i - 1));
						vector.push_back(atof(element.c_str()));
					}
					newData[key] = vector;
				}
				else if (vectorType == jTypeDouble)
				{
					std::vector<double>	vector;

					vector.push_back(atof(first.c_str()));
					for (std::size_t j = 1; j < elements.size(); j++)
					{
						std::cout << "Element : |" << elements[j];
						std::string element = removeWhiteSpace(elements[j]);
						std::cout << "| -> |" << element << "|\n";

						jsonType elementType = getTypeOfContent(element, lign, i);
						if (elementType != vectorType)
							throw JsonParseError("Bad type in vector<int> on "
									+ strPos(lign, i - 1));
						vector.push_back(atof(element.c_str()));
					}
					newData[key] = vector;
				}
				else if (vectorType == jTypeBool)
				{
					std::vector<bool>	vector;


					if (first == "true")
						vector.push_back(true);
					else
						vector.push_back(false);
					for (std::size_t j = 1; j < elements.size(); j++)
					{
						std::cout << "Element : |" << elements[j];
						std::string element = removeWhiteSpace(elements[j]);
						std::cout << "| -> |" << element << "|\n";

						jsonType elementType = getTypeOfContent(element, lign, i);
						if (elementType != vectorType)
							throw JsonParseError("Bad type in vector<int> on "
									+ strPos(lign, i - 1));
						if (element == "true")
							vector.push_back(true);
						else
							vector.push_back(false);
					}
					newData[key] = vector;
				}
				else if (vectorType == jTypeChar)
				{
					std::vector<char>	vector;

					vector.push_back(first[1]);
					for (std::size_t j = 1; j < elements.size(); j++)
					{
						std::cout << "Element : |" << elements[j];
						std::string element = removeWhiteSpace(elements[j]);
						std::cout << "| -> |" << element << "|\n";

						jsonType elementType = getTypeOfContent(element, lign, i);
						if (elementType != vectorType)
							throw JsonParseError("Bad type in vector<int> on "
									+ strPos(lign, i - 1));
						vector.push_back(element[1]);
					}
					newData[key] = vector;
				}
				else if (vectorType == jTypeString)
				{
					std::vector<std::string>	vector;

					vector.push_back(first.substr(1, first.size()-2));
					for (std::size_t j = 1; j < elements.size(); j++)
					{
						std::cout << "Element : |" << elements[j];
						std::string element = removeWhiteSpace(elements[j]);
						std::cout << "| -> |" << element << "|\n";

						jsonType elementType = getTypeOfContent(element, lign, i);
						if (elementType != vectorType)
							throw JsonParseError("Bad type in vector<int> on "
									+ strPos(lign, i - 1));
						vector.push_back(element.substr(1, element.size()-2));
					}
					newData[key] = vector;
				}
				else if (vectorType == jTypeJson)
				{
					std::vector<Json>	vector;

					Json	firstJson;
					firstJson.parseFromString(first);
					vector.push_back(firstJson);
					for (std::size_t j = 1; j < elements.size(); j++)
					{
						std::cout << "Element : |" << elements[j];
						std::string element = removeWhiteSpace(elements[j]);
						std::cout << "| -> |" << element << "|\n";

						jsonType elementType = getTypeOfContent(element, lign, i);
						if (elementType != vectorType)
							throw JsonParseError("Bad type in vector<int> on "
									+ strPos(lign, i - 1));
						Json	json;
						json.parseFromString(element);
						vector.push_back(json);
					}
					newData[key] = vector;
				}
				else
				{
					throw JsonParseError("Unkown type in list on "
								+ strPos(lign, i - 1));
				}
			}
		}
		// Content is a json
		else if (content[0] == '{')
		{
			content += '}';
			std::cout << "Json sub parse on |" << content << "|\n\n";
			Json json;
			json.parseFromString(content);
			std::cout << "\n";
			newData[key] = json;
		}
		// Content is a bool
		else if (content == "true")
		{
			newData[key] = true;
		}
		// Content is a bool
		else if (content == "false")
		{
			newData[key] = false;
		}
		// Content is Null
		else if (content == "Null")
		{
			newData[key] = JsonContent();
		}
		// Content is unknow
		else
		{
			throw JsonParseError("Unknow content type on "
									+ strPos(lign, i - 1));
		}

		// Go to , or }
		i = iEND;



		// End of the json
		if (str[i] == '}')
		{
			std::cout << "End of json" << std::endl;
			this->data = newData;
			return ;
		}

		i++;
	}
	throw JsonParseError("Empty string");
}


////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////
