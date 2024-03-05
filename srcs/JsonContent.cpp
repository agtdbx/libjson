#include <JsonContent.hpp>
#include <Json.hpp>

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
JsonContent::JsonContent(void)
{
	this->type = jTypeNull;
	this->content = NULL;
}

JsonContent::JsonContent(int const &content)
{
	this->type = jTypeInt;
	this->content = new int(content);
}

JsonContent::JsonContent(bool const &content)
{
	this->type = jTypeBool;
	this->content = new bool(content);
}

JsonContent::JsonContent(char const &content)
{
	this->type = jTypeChar;
	this->content = new char(content);
}

JsonContent::JsonContent(float const &content)
{
	this->type = jTypeFloat;
	this->content = new float(content);
}

JsonContent::JsonContent(double const &content)
{
	this->type = jTypeDouble;
	this->content = new double(content);
}

JsonContent::JsonContent(Json const &content)
{
	this->type = jTypeJson;
	this->content = new Json(content);
}

JsonContent::JsonContent(char const *str)
: JsonContent(std::string(str))
{

}


JsonContent::JsonContent(std::string const &content)
{
	this->type = jTypeString;
	std::cout << "STR : " << content << std::endl;
	this->content = new std::string(content);
}

JsonContent::JsonContent(std::vector<int> const &content)
{
	this->type = jTypeVectorInt;
	this->content = new std::vector<int>(content);
}

JsonContent::JsonContent(std::vector<bool> const &content)
{
	this->type = jTypeVectorBool;
	this->content = new std::vector<bool>(content);
}

JsonContent::JsonContent(std::vector<char> const &content)
{
	this->type = jTypeVectorChar;
	this->content = new std::vector<char>(content);
}

JsonContent::JsonContent(std::vector<float> const &content)
{
	this->type = jTypeVectorFloat;
	this->content = new std::vector<float>(content);
}

JsonContent::JsonContent(std::vector<double> const &content)
{
	this->type = jTypeVectorDouble;
	this->content = new std::vector<double>(content);
}

JsonContent::JsonContent(std::vector<Json> const &content)
{
	this->type = jTypeVectorJson;
	this->content = new std::vector<Json>(content);
}

JsonContent::JsonContent(std::vector<std::string> const &content)
{
	this->type = jTypeVectorString;
	this->content = new std::vector<std::string>(content);
}

JsonContent::JsonContent(JsonContent const &jsonContent)
{
	this->type = jsonContent.type;
	if (this->type == jTypeInt)
		this->content = new int(*((int *)jsonContent.content));
	else if (this->type == jTypeBool)
		this->content = new bool(*((bool *)jsonContent.content));
	else if (this->type == jTypeChar)
		this->content = new char(*((char *)jsonContent.content));
	else if (this->type == jTypeFloat)
		this->content = new float(*((float *)jsonContent.content));
	else if (this->type == jTypeDouble)
		this->content = new double(*((double *)jsonContent.content));
	else if (this->type == jTypeJson)
		this->content = new Json(*((Json *)jsonContent.content));
	else if (this->type == jTypeString)
		this->content = new std::string(*((std::string *)jsonContent.content));
	else if (this->type == jTypeVectorInt)
		this->content = new std::vector<int>
							(*((std::vector<int> *)jsonContent.content));
	else if (this->type == jTypeVectorBool)
		this->content = new std::vector<bool>
							(*((std::vector<bool> *)jsonContent.content));
	else if (this->type == jTypeVectorChar)
		this->content = new std::vector<char>
							(*((std::vector<char> *)jsonContent.content));
	else if (this->type == jTypeVectorFloat)
		this->content = new std::vector<float>
							(*((std::vector<float> *)jsonContent.content));
	else if (this->type == jTypeVectorDouble)
		this->content = new std::vector<double>
							(*((std::vector<double> *)jsonContent.content));
	else if (this->type == jTypeVectorJson)
		this->content = new std::vector<Json>
							(*((std::vector<Json> *)jsonContent.content));
	else if (this->type == jTypeVectorString)
		this->content = new std::vector<std::string>
							(*((std::vector<std::string> *)jsonContent.content));
	else
	{
		this->type = jTypeNull;
		this->content = NULL;
	}
}

JsonContent::~JsonContent(void)
{
	this->clearContent();
}


////////////////////////////////////////////////////////////////////////////////
// Getters
////////////////////////////////////////////////////////////////////////////////
jsonType	JsonContent::getType(void) const
{
	return (this->type);
}

int	&JsonContent::getInt(void) const
{
	if (this->type != jTypeInt)
		throw JsonContentTypeError();
	return *((int *)this->content);
}

bool	&JsonContent::getBool(void) const
{
	if (this->type != jTypeBool)
		throw JsonContentTypeError();
	return *((bool *)this->content);
}

char	&JsonContent::getChar(void) const
{
	if (this->type != jTypeChar)
		throw JsonContentTypeError();
	return *((char *)this->content);
}

float	&JsonContent::getFloat(void) const
{
	if (this->type != jTypeFloat)
		throw JsonContentTypeError();
	return *((float *)this->content);
}

double	&JsonContent::getDouble(void) const
{
	if (this->type != jTypeDouble)
		throw JsonContentTypeError();
	return *((double *)this->content);
}

Json	&JsonContent::getJson(void) const
{
	if (this->type != jTypeJson)
		throw JsonContentTypeError();
	return *((Json *)this->content);
}

std::string	&JsonContent::getString(void) const
{
	if (this->type != jTypeString)
		throw JsonContentTypeError();
	return *((std::string *)this->content);
}

std::vector<int>	&JsonContent::getVectorInt(void) const
{
	if (this->type != jTypeVectorInt)
		throw JsonContentTypeError();
	return *((std::vector<int> *)this->content);
}

std::vector<bool>	&JsonContent::getVectorBool(void) const
{
	if (this->type != jTypeVectorBool)
		throw JsonContentTypeError();
	return *((std::vector<bool> *)this->content);
}

std::vector<char>	&JsonContent::getVectorChar(void) const
{
	if (this->type != jTypeVectorChar)
		throw JsonContentTypeError();
	return *((std::vector<char> *)this->content);
}

std::vector<float>	&JsonContent::getVectorFloat(void) const
{
	if (this->type != jTypeVectorFloat)
		throw JsonContentTypeError();
	return *((std::vector<float> *)this->content);
}

std::vector<double>	&JsonContent::getVectorDouble(void) const
{
	if (this->type != jTypeVectorDouble)
		throw JsonContentTypeError();
	return *((std::vector<double> *)this->content);
}

std::vector<Json>	&JsonContent::getVectorJson(void) const
{
	if (this->type != jTypeVectorJson)
		throw JsonContentTypeError();
	return *((std::vector<Json> *)this->content);
}

std::vector<std::string>	&JsonContent::getVectorString(void) const
{
	if (this->type != jTypeVectorString)
		throw JsonContentTypeError();
	return *((std::vector<std::string> *)this->content);
}


////////////////////////////////////////////////////////////////////////////////
// Setters
////////////////////////////////////////////////////////////////////////////////
void	JsonContent::setContent(int const &content)
{
	this->clearContent();
	this->type = jTypeInt;
	this->content = new int(content);
}

void	JsonContent::setContent(bool const &content)
{
	this->clearContent();
	this->type = jTypeBool;
	this->content = new bool(content);
}

void	JsonContent::setContent(char const &content)
{
	this->clearContent();
	this->type = jTypeChar;
	this->content = new char(content);
}

void	JsonContent::setContent(float const &content)
{
	this->clearContent();
	this->type = jTypeFloat;
	this->content = new float(content);
}

void	JsonContent::setContent(double const &content)
{
	this->clearContent();
	this->type = jTypeDouble;
	this->content = new double(content);
}

void	JsonContent::setContent(Json const &content)
{
	this->clearContent();
	this->type = jTypeJson;
	this->content = new Json(content);
}

void	JsonContent::setContent(std::string const &content)
{
	this->clearContent();
	this->type = jTypeString;
	this->content = new std::string(content);
}

void	JsonContent::setContent(std::vector<int> const &content)
{
	this->clearContent();
	this->type = jTypeVectorInt;
	this->content = new std::vector<int>(content);
}

void	JsonContent::setContent(std::vector<bool> const &content)
{
	this->clearContent();
	this->type = jTypeVectorBool;
	this->content = new std::vector<bool>(content);
}

void	JsonContent::setContent(std::vector<char> const &content)
{
	this->clearContent();
	this->type = jTypeVectorChar;
	this->content = new std::vector<char>(content);
}

void	JsonContent::setContent(std::vector<float> const &content)
{
	this->clearContent();
	this->type = jTypeVectorFloat;
	this->content = new std::vector<float>(content);
}

void	JsonContent::setContent(std::vector<double> const &content)
{
	this->clearContent();
	this->type = jTypeVectorDouble;
	this->content = new std::vector<double>(content);
}

void	JsonContent::setContent(std::vector<Json> const &content)
{
	this->clearContent();
	this->type = jTypeVectorJson;
	this->content = new std::vector<Json>(content);
}

void	JsonContent::setContent(std::vector<std::string> const &content)
{
	this->clearContent();
	this->type = jTypeVectorString;
	this->content = new std::vector<std::string>(content);
}



////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
JsonContent	&JsonContent::operator=(int const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(bool const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(char const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(float const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(double const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(Json const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(char const *content)
{
	this->clearContent();
	this->setContent(std::string(content));
	return (*this);
}

JsonContent	&JsonContent::operator=(std::string const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(std::vector<int> const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(std::vector<bool> const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(std::vector<char> const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(std::vector<float> const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(std::vector<double> const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(std::vector<Json> const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(std::vector<std::string> const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(JsonContent const &jsonContent)
{
	if (this == &jsonContent)
		return (*this);

	std::cout << "test\n";

	this->clearContent();
	this->type = jsonContent.type;
	if (this->type == jTypeInt)
		this->content = new int(*((int *)jsonContent.content));
	else if (this->type == jTypeBool)
		this->content = new bool(*((bool *)jsonContent.content));
	else if (this->type == jTypeChar)
		this->content = new char(*((char *)jsonContent.content));
	else if (this->type == jTypeFloat)
		this->content = new float(*((float *)jsonContent.content));
	else if (this->type == jTypeDouble)
		this->content = new double(*((double *)jsonContent.content));
	else if (this->type == jTypeJson)
		this->content = new Json(*((Json *)jsonContent.content));
	else if (this->type == jTypeString)
		this->content = new std::string(*((std::string *)jsonContent.content));
	else if (this->type == jTypeVectorInt)
		this->content = new std::vector<int>
							(*((std::vector<int> *)jsonContent.content));
	else if (this->type == jTypeVectorBool)
		this->content = new std::vector<bool>
							(*((std::vector<bool> *)jsonContent.content));
	else if (this->type == jTypeVectorChar)
		this->content = new std::vector<char>
							(*((std::vector<char> *)jsonContent.content));
	else if (this->type == jTypeVectorFloat)
		this->content = new std::vector<float>
							(*((std::vector<float> *)jsonContent.content));
	else if (this->type == jTypeVectorDouble)
		this->content = new std::vector<double>
							(*((std::vector<double> *)jsonContent.content));
	else if (this->type == jTypeVectorJson)
		this->content = new std::vector<Json>
							(*((std::vector<Json> *)jsonContent.content));
	else if (this->type == jTypeVectorString)
		this->content = new std::vector<std::string>
							(*((std::vector<std::string> *)jsonContent.content));
	else
	{
		this->type = jTypeNull;
		this->content = NULL;
	}

	return (*this);
}

std::ostream	&operator<<(std::ostream &os, JsonContent &jsonContent)
{
	os << jsonContent.toString();
	return (os);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////
std::string	JsonContent::toString(void)
{
	if (this->type == jTypeInt)
	{
		std::string	print = std::to_string(this->getInt());
		return (print);
	}
	else if (this->type == jTypeBool)
	{
		std::string	print= "";
		if (this->getBool())
			print += "true";
		else
			print += "false";
		return (print);
	}
	else if (this->type == jTypeChar)
	{
		std::string	print = "";
		print += this->getChar();
		return ("'" + print + "'");
	}
	else if (this->type == jTypeFloat)
	{
		std::string	print = std::to_string(this->getFloat());
		return (print + "f");
	}
	else if (this->type == jTypeDouble)
	{
		std::string	print = std::to_string(this->getDouble());
		return (print);
	}
	else if (this->type == jTypeJson)
	{
		std::string	print = this->getJson().toString();
		return (print);
	}
	else if (this->type == jTypeString)
	{
		std::string	print = this->getString();
		return ("\"" + print + "\"");
	}
	else if (this->type == jTypeVectorInt)
	{
		std::string	print = "[";
		std::vector<int>	vector = this->getVectorInt();
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ", ";
			print += std::to_string(vector[i]);
		}
		return (print + "]");
	}
	else if (this->type == jTypeVectorBool)
	{
		std::string	print = "[";
		std::vector<bool>	vector = this->getVectorBool();
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ", ";
			if (vector[i])
				print += "true";
			else
				print += "false";
		}
		return (print + "]");
	}
	else if (this->type == jTypeVectorChar)
	{
		std::string	print = "[";
		std::vector<char>	vector = this->getVectorChar();
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ", ";
			print += "'";
			print += vector[i];
			print += "'";
		}
		return (print + "]");
	}
	else if (this->type == jTypeVectorFloat)
	{
		std::string	print = "[";
		std::vector<float>	vector = this->getVectorFloat();
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ", ";
			print += std::to_string(vector[i]) + "f";
		}
		return (print + "]");
	}
	else if (this->type == jTypeVectorDouble)
	{
		std::string	print = "[";
		std::vector<double>	vector = this->getVectorDouble();
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ", ";
			print += std::to_string(vector[i]);
		}
		return (print + "]");
	}
	else if (this->type == jTypeVectorJson)
	{
		std::string	print = "[";
		std::vector<Json>	vector = this->getVectorJson();
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ", ";
			print += vector[i].toString();
		}
		return (print + "]");
	}
	else if (this->type == jTypeVectorString)
	{
		std::string	print = "[";
		std::vector<std::string>	vector = this->getVectorString();
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ", ";
			print += "\"" + vector[i] + "\"";
		}
		return (print + "]");
	}
	else
	{
		std::string	print = "Null";
		return (print);
	}
}


////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////
void	JsonContent::clearContent(void)
{
	if (this->type == jTypeInt)
		delete (int *)this->content;
	else if (this->type == jTypeBool)
		delete (bool *)this->content;
	else if (this->type == jTypeChar)
		delete (char *)this->content;
	else if (this->type == jTypeFloat)
		delete (float *)this->content;
	else if (this->type == jTypeDouble)
		delete (double *)this->content;
	else if (this->type == jTypeJson)
		delete (Json *)this->content;
	else if (this->type == jTypeString)
		delete (std::string *)this->content;
	else if (this->type == jTypeVectorInt)
		delete (std::vector<int> *)this->content;
	else if (this->type == jTypeVectorBool)
		delete (std::vector<bool> *)this->content;
	else if (this->type == jTypeVectorChar)
		delete (std::vector<char> *)this->content;
	else if (this->type == jTypeVectorFloat)
		delete (std::vector<float> *)this->content;
	else if (this->type == jTypeVectorDouble)
		delete (std::vector<double> *)this->content;
	else if (this->type == jTypeVectorJson)
		delete (std::vector<Json> *)this->content;
	else if (this->type == jTypeVectorString)
		delete (std::vector<std::string> *)this->content;
	this->type = jTypeNull;
	this->content = NULL;
}
