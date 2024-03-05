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

	void	setContent(std::string &key, JsonContent &content);

	Json	&operator=(Json const &json);

	class JsonKeyError : public std::exception
	{
	public:
		const char	*what(void) const throw()
		{
			return ("Json : Key error");
		}
	};

private:
	std::map<std::string, JsonContent>	data;
};

#endif
