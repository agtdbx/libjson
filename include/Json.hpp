#ifndef JSON_HPP
# define JSON_HPP

# include <map>

# include <JsonContent.hpp>

class Json
{
public:
	Json(void);
	Json(Json const &json);
	~Json();

	const JsonContent	&getContent(std::string key) const;

	void	setContent(std::string key, JsonContent content);

	Json		&operator=(Json const &json);
	JsonContent	&operator[](int key);
	JsonContent	&operator[](unsigned int key);
	JsonContent	&operator[](long key);
	JsonContent	&operator[](unsigned long key);
	JsonContent	&operator[](bool key);
	JsonContent	&operator[](char key);
	JsonContent	&operator[](float key);
	JsonContent	&operator[](double key);
	JsonContent	&operator[](char const *key);
	JsonContent	&operator[](std::string key);
	bool		operator==(Json const &json) const;
	bool		operator!=(Json const &json) const;

	std::string	toString(bool indented) const;
	std::string	toStringOneLine(void) const;
	std::string	toStringIndented(int indentLevel) const;
	void		parseFromString(std::string str);

	static Json	parse(std::string str);

private:
	std::map<std::string, JsonContent>	data;
};

std::ostream	&operator<<(std::ostream &os, Json const &json);

class JsonKeyError : public std::exception
	{
	public:
		const char	*what(void) const throw()
		{
			return ("Json : Key error");
		}
	};

class JsonParseError : public std::exception
{
public:
	JsonParseError(std::string str)
	{
		this->str = "Json : Parse error : " + str;
	}
	const char	*what(void) const throw()
	{
		return (this->str.c_str());
	}
private:
	std::string	str;
};

#endif
