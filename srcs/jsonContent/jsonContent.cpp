#include <JsonContent.hpp>

/*=============================================================================

=============================================================================*/
JsonContent::JsonContent(void)
{
	this->type = jsonInt;
	this->content.asInt = 0;
}

JsonContent::JsonContent(const int content)
{

}

JsonContent::JsonContent(const char content)
{

}

JsonContent::JsonContent(const float content)
{

}

JsonContent::JsonContent(const std::string &content)
{

}

JsonContent::JsonContent(const JsonContent &content)
{

}

JsonContent::~JsonContent(void)
{

}

jsonType	JsonContent::getType(void)
{

}

int	JsonContent::getInt(void)
{

}

char	JsonContent::getChar(void)
{

}

float	JsonContent::getFloat(void)
{

}

std::string	JsonContent::getString(void)
{

}

JsonContent	JsonContent::getJson(void)
{

}

void	JsonContent::setContent(int content)
{

}

void	JsonContent::setContent(char content)
{

}

void	JsonContent::setContent(float content)
{

}

void	JsonContent::setContent(std::string &content)
{

}

void	JsonContent::setContent(JsonContent &content)
{

}

