#ifndef JSON_HPP
# define JSON_HPP

# include <JsonContent.hpp>

class Json
{
public:
	Json(void);
	Json(Json const &json);
	~Json();

	Json	&operator=(Json const &json);
};

#endif
