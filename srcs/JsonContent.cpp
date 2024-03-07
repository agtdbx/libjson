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
	this->content = new long(content);
}

JsonContent::JsonContent(unsigned int const &content)
{
	this->type = jTypeInt;
	this->content = new long(content);
}

JsonContent::JsonContent(long const &content)
{
	this->type = jTypeInt;
	this->content = new long(content);
}

JsonContent::JsonContent(unsigned long const &content)
{
	this->type = jTypeInt;
	this->content = new long(content);
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
	std::vector<long> tmp;
	for (std::size_t i = 0; i < content.size(); i++)
		tmp.push_back(content[i]);
	this->content = new std::vector<long>(tmp);
}

JsonContent::JsonContent(std::vector<unsigned int> const &content)
{
	this->type = jTypeVectorInt;
	std::vector<long> tmp;
	for (std::size_t i = 0; i < content.size(); i++)
		tmp.push_back(content[i]);
	this->content = new std::vector<long>(tmp);
}

JsonContent::JsonContent(std::vector<long> const &content)
{
	this->type = jTypeVectorInt;
	this->content = new std::vector<long>(content);
}

JsonContent::JsonContent(std::vector<unsigned long> const &content)
{
	this->type = jTypeVectorInt;
	std::vector<long> tmp;
	for (std::size_t i = 0; i < content.size(); i++)
		tmp.push_back(content[i]);
	this->content = new std::vector<long>(tmp);
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
		this->content = new long(*((int *)jsonContent.content));
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
		this->content = new std::vector<long>
							(*((std::vector<long> *)jsonContent.content));
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

long	&JsonContent::getInt(void) const
{
	if (this->type != jTypeInt)
		throw JsonContentTypeError();
	return *((long *)this->content);
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

std::vector<long>	&JsonContent::getVectorInt(void) const
{
	if (this->type != jTypeVectorInt)
		throw JsonContentTypeError();
	return *((std::vector<long> *)this->content);
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
	this->content = new long(content);
}

void	JsonContent::setContent(unsigned int const &content)
{
	this->clearContent();
	this->type = jTypeInt;
	this->content = new long(content);
}

void	JsonContent::setContent(long const &content)
{
	this->clearContent();
	this->type = jTypeInt;
	this->content = new long(content);
}

void	JsonContent::setContent(unsigned long const &content)
{
	this->clearContent();
	this->type = jTypeInt;
	this->content = new long(content);
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
	std::vector<long>	tmp;
	for (std::size_t i = 0; i < content.size(); i++)
		tmp.push_back(content[i]);
	this->content = new std::vector<long>(tmp);
}

void	JsonContent::setContent(std::vector<unsigned int> const &content)
{
	this->clearContent();
	this->type = jTypeVectorInt;
	std::vector<long>	tmp;
	for (std::size_t i = 0; i < content.size(); i++)
		tmp.push_back(content[i]);
	this->content = new std::vector<long>(tmp);
}

void	JsonContent::setContent(std::vector<long> const &content)
{
	this->clearContent();
	this->type = jTypeVectorInt;
	this->content = new std::vector<long>(content);
}

void	JsonContent::setContent(std::vector<unsigned long> const &content)
{
	this->clearContent();
	this->type = jTypeVectorInt;
	std::vector<long>	tmp;
	for (std::size_t i = 0; i < content.size(); i++)
		tmp.push_back(content[i]);
	this->content = new std::vector<long>(tmp);
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
JsonContent	&JsonContent::operator=(void const *content)
{
	return (*this);
}


JsonContent	&JsonContent::operator=(std::nullptr_t const content)
{
	return (*this);
}


JsonContent	&JsonContent::operator=(int const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(unsigned int const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(long const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}


JsonContent	&JsonContent::operator=(unsigned long const &content)
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

JsonContent	&JsonContent::operator=(std::vector<unsigned int> const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(std::vector<long> const &content)
{
	this->clearContent();
	this->setContent(content);
	return (*this);
}

JsonContent	&JsonContent::operator=(std::vector<unsigned long> const &content)
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

	this->clearContent();
	this->type = jsonContent.type;
	if (this->type == jTypeInt)
		this->content = new long(*((long *)jsonContent.content));
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
		this->content = new std::vector<long>
							(*((std::vector<long> *)jsonContent.content));
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


bool	JsonContent::operator==(JsonContent const &jsonContent) const
{
	if (this->type != jsonContent.type)
		return (false);

	if (this->type == jTypeInt)
		return ((*(long *)this->content) == (*(long *)jsonContent.content));
	else if (this->type == jTypeBool)
		return ((*(bool *)this->content) == (*(bool *)jsonContent.content));
	else if (this->type == jTypeChar)
		return ((*(char *)this->content) == (*(char *)jsonContent.content));
	else if (this->type == jTypeFloat)
		return ((*(float *)this->content) == (*(float *)jsonContent.content));
	else if (this->type == jTypeDouble)
		return ((*(double *)this->content) == (*(double *)jsonContent.content));
	else if (this->type == jTypeJson)
		return ((*(Json *)this->content) == (*(Json *)jsonContent.content));
	else if (this->type == jTypeString)
		return ((*(std::string *)this->content) ==
				(*(std::string *)jsonContent.content));
	else if (this->type == jTypeVectorInt)
		return (isVectorEqual((std::vector<long> *)this->content,
								(std::vector<long> *)jsonContent.content));
	else if (this->type == jTypeVectorBool)
		return (isVectorEqual((std::vector<bool> *)this->content,
								(std::vector<bool> *)jsonContent.content));
	else if (this->type == jTypeVectorChar)
		return (isVectorEqual((std::vector<char> *)this->content,
								(std::vector<char> *)jsonContent.content));
	else if (this->type == jTypeVectorFloat)
		return (isVectorEqual((std::vector<float> *)this->content,
								(std::vector<float> *)jsonContent.content));
	else if (this->type == jTypeVectorDouble)
		return (isVectorEqual((std::vector<double> *)this->content,
								(std::vector<double> *)jsonContent.content));
	else if (this->type == jTypeVectorJson)
		return (isVectorEqual((std::vector<Json> *)this->content,
								(std::vector<Json> *)jsonContent.content));
	else if (this->type == jTypeVectorString)
		return (isVectorEqual((std::vector<std::string> *)this->content,
								(std::vector<std::string> *)jsonContent.content));

	return (true);
}

bool	JsonContent::operator!=(JsonContent const &jsonContent) const
{
	if (this->type != jsonContent.type)
		return (true);

	if (this->type == jTypeInt)
		return ((*(long *)this->content) != (*(long *)jsonContent.content));
	else if (this->type == jTypeBool)
		return ((*(bool *)this->content) != (*(bool *)jsonContent.content));
	else if (this->type == jTypeChar)
		return ((*(char *)this->content) != (*(char *)jsonContent.content));
	else if (this->type == jTypeFloat)
		return ((*(float *)this->content) != (*(float *)jsonContent.content));
	else if (this->type == jTypeDouble)
		return ((*(double *)this->content) != (*(double *)jsonContent.content));
	else if (this->type == jTypeJson)
		return ((*(Json *)this->content) != (*(Json *)jsonContent.content));
	else if (this->type == jTypeString)
		return ((*(std::string *)this->content) !=
				(*(std::string *)jsonContent.content));
	else if (this->type == jTypeVectorInt)
		return (!isVectorEqual((std::vector<long> *)this->content,
								(std::vector<long> *)jsonContent.content));
	else if (this->type == jTypeVectorBool)
		return (!isVectorEqual((std::vector<bool> *)this->content,
								(std::vector<bool> *)jsonContent.content));
	else if (this->type == jTypeVectorChar)
		return (!isVectorEqual((std::vector<char> *)this->content,
								(std::vector<char> *)jsonContent.content));
	else if (this->type == jTypeVectorFloat)
		return (!isVectorEqual((std::vector<float> *)this->content,
								(std::vector<float> *)jsonContent.content));
	else if (this->type == jTypeVectorDouble)
		return (!isVectorEqual((std::vector<double> *)this->content,
								(std::vector<double> *)jsonContent.content));
	else if (this->type == jTypeVectorJson)
		return (!isVectorEqual((std::vector<Json> *)this->content,
								(std::vector<Json> *)jsonContent.content));
	else if (this->type == jTypeVectorString)
		return (!isVectorEqual((std::vector<std::string> *)this->content,
								(std::vector<std::string> *)jsonContent.content));

	return (false);
}



std::ostream	&operator<<(std::ostream &os, JsonContent &jsonContent)
{
	os << jsonContent.toString(true);
	return (os);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////
std::string	JsonContent::toString(bool indented)
{
	if (indented)
		return (this->toStringIndented(0));
	return (this->toStringOneLine());
}


std::string	JsonContent::toStringOneLine(void)
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
		std::string	print = this->getJson().toStringOneLine();
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
		std::vector<long>	vector = this->getVectorInt();
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
			print += vector[i].toStringOneLine();
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


std::string	JsonContent::toStringIndented(int indentLevel)
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
		std::string	print = this->getJson().toStringIndented(indentLevel);
		return (print);
	}
	else if (this->type == jTypeString)
	{
		std::string	print = this->getString();
		return ("\"" + print + "\"");
	}
	else if (this->type == jTypeVectorInt)
	{
		std::string	print = "[\n";
		indentLevel++;
		std::vector<long>	vector = this->getVectorInt();
		if (vector.size() == 0)
			return ("[]");
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ",\n";
			for (int i = 0; i < indentLevel; i++)\
				print += "\t";
			print += std::to_string(vector[i]);
		}
		print += "\n";
		indentLevel--;
		for (int i = 0; i < indentLevel; i++)\
			print += "\t";
		return (print + "]");
	}
	else if (this->type == jTypeVectorBool)
	{
		std::string	print = "[\n";
		indentLevel++;
		std::vector<bool>	vector = this->getVectorBool();
		if (vector.size() == 0)
			return ("[]");
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ",\n";
			for (int i = 0; i < indentLevel; i++)\
				print += "\t";
			if (vector[i])
				print += "true";
			else
				print += "false";
		}
		print += "\n";
		indentLevel--;
		for (int i = 0; i < indentLevel; i++)\
			print += "\t";
		return (print + "]");
	}
	else if (this->type == jTypeVectorChar)
	{
		std::string	print = "[\n";
		indentLevel++;
		std::vector<char>	vector = this->getVectorChar();
		if (vector.size() == 0)
			return ("[]");
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ",\n";
			for (int i = 0; i < indentLevel; i++)\
				print += "\t";
			print += "'";
			print += vector[i];
			print += "'";
		}
		print += "\n";
		indentLevel--;
		for (int i = 0; i < indentLevel; i++)\
			print += "\t";
		return (print + "]");
	}
	else if (this->type == jTypeVectorFloat)
	{
		std::string	print = "[\n";
		indentLevel++;
		std::vector<float>	vector = this->getVectorFloat();
		if (vector.size() == 0)
			return ("[]");
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ",\n";
			for (int i = 0; i < indentLevel; i++)\
				print += "\t";
			print += std::to_string(vector[i]) + "f";
		}
		print += "\n";
		indentLevel--;
		for (int i = 0; i < indentLevel; i++)\
			print += "\t";
		return (print + "]");
	}
	else if (this->type == jTypeVectorDouble)
	{
		std::string	print = "[\n";
		indentLevel++;
		std::vector<double>	vector = this->getVectorDouble();
		if (vector.size() == 0)
			return ("[]");
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ",\n";
			for (int i = 0; i < indentLevel; i++)\
				print += "\t";
			print += std::to_string(vector[i]);
		}
		print += "\n";
		indentLevel--;
		for (int i = 0; i < indentLevel; i++)\
			print += "\t";
		return (print + "]");
	}
	else if (this->type == jTypeVectorJson)
	{
		std::string	print = "[\n";
		indentLevel++;
		std::vector<Json>	vector = this->getVectorJson();
		if (vector.size() == 0)
			return ("[]");
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ",\n";
			for (int i = 0; i < indentLevel; i++)\
				print += "\t";
			print += vector[i].toStringIndented(indentLevel);
		}
		print += "\n";
		indentLevel--;
		for (int i = 0; i < indentLevel; i++)\
			print += "\t";
		return (print + "]");
	}
	else if (this->type == jTypeVectorString)
	{
		std::string	print = "[\n";
		indentLevel++;
		std::vector<std::string>	vector = this->getVectorString();
		if (vector.size() == 0)
			return ("[]");
		for (std::size_t i = 0; i < vector.size(); i++)
		{
			if (i != 0)
				print += ",\n";
			for (int i = 0; i < indentLevel; i++)\
				print += "\t";
			print += "\"" + vector[i] + "\"";
		}
		print += "\n";
		indentLevel--;
		for (int i = 0; i < indentLevel; i++)\
			print += "\t";
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
