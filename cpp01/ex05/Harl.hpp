#ifndef HARL_HPP
#define HARL_HPP

#include <string>

typedef struct s_commentType {
	std::string type;
	void (*comment)( void );
	
} 				t_commentType;

class Harl {
public:
void	complain( std::string level );

private:
	// set to static as they don't need to access instance data
	static void	debug( void );
	static void	info( void );
	static void	warning( void );
	static void	error( void );
};


#endif
