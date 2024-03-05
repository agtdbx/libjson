#include <Json.hpp>

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
	os << json.toString();
	return (os);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////
std::string	Json::toString(void)
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
		print += "\"" + it->first + "\" : " + it->second.toString();
		it++;
	}

	print += "}";
	return (print);
}


////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////
