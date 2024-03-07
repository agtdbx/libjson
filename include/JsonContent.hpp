#ifndef JSONCONTENT_HPP
# define JSONCONTENT_HPP

# include <iostream>
# include <vector>
# include <stdexcept>

class Json;

enum jsonType
{
	jTypeNull = 0,
	jTypeInt,
	jTypeBool,
	jTypeChar,
	jTypeFloat,
	jTypeDouble,
	jTypeJson,
	jTypeString,
	jTypeVectorInt,
	jTypeVectorBool,
	jTypeVectorChar,
	jTypeVectorFloat,
	jTypeVectorDouble,
	jTypeVectorJson,
	jTypeVectorString,
};

class JsonContent
{
public:
	JsonContent(void);
	JsonContent(int const &content);
	JsonContent(unsigned int const &content);
	JsonContent(long const &content);
	JsonContent(unsigned long const &content);
	JsonContent(bool const &content);
	JsonContent(char const &content);
	JsonContent(float const &content);
	JsonContent(double const &content);
	JsonContent(Json const &content);
	JsonContent(char const *str);
	JsonContent(std::string const &content);
	JsonContent(std::vector<int> const &content);
	JsonContent(std::vector<unsigned int> const &content);
	JsonContent(std::vector<long> const &content);
	JsonContent(std::vector<unsigned long> const &content);
	JsonContent(std::vector<bool> const &content);
	JsonContent(std::vector<char> const &content);
	JsonContent(std::vector<float> const &content);
	JsonContent(std::vector<double> const &content);
	JsonContent(std::vector<Json> const &content);
	JsonContent(std::vector<std::string> const &content);
	JsonContent(JsonContent const &jsonContent);
	~JsonContent();

	jsonType	getType(void) const;
	long		&getInt(void) const;
	bool		&getBool(void) const;
	char		&getChar(void) const;
	float		&getFloat(void) const;
	double		&getDouble(void) const;
	Json		&getJson(void) const;
	std::string	&getString(void) const;
	std::vector<long>			&getVectorInt(void) const;
	std::vector<bool>			&getVectorBool(void) const;
	std::vector<char>			&getVectorChar(void) const;
	std::vector<float>			&getVectorFloat(void) const;
	std::vector<double>			&getVectorDouble(void) const;
	std::vector<Json>			&getVectorJson(void) const;
	std::vector<std::string>	&getVectorString(void) const;

	void	setContent(int const &content);
	void	setContent(unsigned int const &content);
	void	setContent(long const &content);
	void	setContent(unsigned long const &content);
	void	setContent(bool const &content);
	void	setContent(char const &content);
	void	setContent(float const &content);
	void	setContent(double const &content);
	void	setContent(Json const &content);
	void	setContent(std::string const &content);
	void	setContent(std::vector<int> const &content);
	void	setContent(std::vector<unsigned int> const &content);
	void	setContent(std::vector<long> const &content);
	void	setContent(std::vector<unsigned long> const &content);
	void	setContent(std::vector<bool> const &content);
	void	setContent(std::vector<char> const &content);
	void	setContent(std::vector<float> const &content);
	void	setContent(std::vector<double> const &content);
	void	setContent(std::vector<Json> const &content);
	void	setContent(std::vector<std::string> const &content);

	JsonContent	&operator=(void const *content);
	JsonContent	&operator=(std::nullptr_t const content);
	JsonContent	&operator=(int const &content);
	JsonContent	&operator=(unsigned int const &content);
	JsonContent	&operator=(long const &content);
	JsonContent	&operator=(unsigned long const &content);
	JsonContent	&operator=(bool const &content);
	JsonContent	&operator=(char const &content);
	JsonContent	&operator=(float const &content);
	JsonContent	&operator=(double const &content);
	JsonContent	&operator=(Json const &content);
	JsonContent	&operator=(char const *content);
	JsonContent	&operator=(std::string const &content);
	JsonContent	&operator=(std::vector<int> const &content);
	JsonContent	&operator=(std::vector<unsigned int> const &content);
	JsonContent	&operator=(std::vector<long> const &content);
	JsonContent	&operator=(std::vector<unsigned long> const &content);
	JsonContent	&operator=(std::vector<bool> const &content);
	JsonContent	&operator=(std::vector<char> const &content);
	JsonContent	&operator=(std::vector<float> const &content);
	JsonContent	&operator=(std::vector<double> const &content);
	JsonContent	&operator=(std::vector<Json> const &content);
	JsonContent	&operator=(std::vector<std::string> const &content);
	JsonContent	&operator=(JsonContent const &jsonContent);
	bool		operator==(JsonContent const &jsonContent) const;
	bool		operator!=(JsonContent const &jsonContent) const;

	std::string	toString(bool indented);
	std::string	toStringOneLine(void);
	std::string	toStringIndented(int indentLevel);

private:
	jsonType	type;
	void		*content;

	void	clearContent(void);
};

std::ostream	&operator<<(std::ostream &os, JsonContent &jsonContent);

class JsonContentTypeError : public std::exception
{
public:
	const char	*what(void) const throw()
	{
		return ("JsonContent : Type error");
	}
};

template <typename T>
static bool	isVectorEqual(std::vector<T> *vec1, std::vector<T> *vec2)
{
	if (vec1->size() != vec2->size())
		return (false);

	for (std::size_t i = 0; i < vec1->size(); i++)
	{
		if (vec1->at(i) != vec2->at(i))
			return (false);
	}
	return (true);
}


#endif
