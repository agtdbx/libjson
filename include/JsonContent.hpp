#ifndef JSONCONTENT_HPP
# define JSONCONTENT_HPP

# include <iostream>
# include <stdexcept>

class JsonContent;

enum jsonType
{
	jsonInt = 0,
	jsonChar,
	jsonFloat,
	jsonString,
	jsonObject
};

union JsonContainer
{
	int			asInt;
	char		asChar;
	float		asFloat;
	std::string	asString;
	JsonContent	asJson;
};

class JsonContent
{
public:
	JsonContent(void);
	JsonContent(const int content);
	JsonContent(const char content);
	JsonContent(const float content);
	JsonContent(const std::string &content);
	JsonContent(const JsonContent &content);
	~JsonContent();

	jsonType	getType(void);
	int			getInt(void);
	char		getChar(void);
	float		getFloat(void);
	std::string	getString(void);
	JsonContent	getJson(void);
	void		setContent(int content);
	void		setContent(char content);
	void		setContent(float content);
	void		setContent(std::string &content);
	void		setContent(JsonContent &content);

	class JsonContentTypeError : public std::exception
	{
	public:
		const char	*what(void) const throw()
		{
			return ("JsonContent : Wrong type");
		}
	};

private:
	jsonType		type;
	JsonContainer	content;
};

#endif
