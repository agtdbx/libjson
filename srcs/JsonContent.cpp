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

JsonContent::JsonContent(std::string const &content)
{
	this->type = jTypeString;
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
	else if (this->type == jTypeChar)
		this->content = new char(*((char *)jsonContent.content));
	else if (this->type == jTypeFloat)
		this->content = new float(*((float *)jsonContent.content));
	else if (this->type == jTypeJson)
		this->content = new Json(*((Json *)jsonContent.content));
	else if (this->type == jTypeString)
		this->content = new std::string(*((std::string *)jsonContent.content));
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
JsonContent	&JsonContent::operator=(JsonContent const &jsonContent)
{
	if (this == &jsonContent)
		return (*this);

	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////


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
