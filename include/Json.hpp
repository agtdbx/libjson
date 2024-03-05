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

	JsonContent	&getContent(std::string &key);

	void	setContent(std::string key, JsonContent content);

	Json	&operator=(Json const &json);
	JsonContent	&operator[](int key);
	JsonContent	&operator[](bool key);
	JsonContent	&operator[](char key);
	JsonContent	&operator[](float key);
	JsonContent	&operator[](double key);
	JsonContent	&operator[](char const *key);
	JsonContent	&operator[](std::string key);

	class JsonKeyError : public std::exception
	{
	public:
		const char	*what(void) const throw()
		{
			return ("Json : Key error");
		}
	};

	std::string	toString(void);

private:
	std::map<std::string, JsonContent>	data;
};

std::ostream	&operator<<(std::ostream &os, Json &json);

#endif
