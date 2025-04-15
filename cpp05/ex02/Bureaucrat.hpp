/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:12 by sting             #+#    #+#             */
/*   Updated: 2025/04/14 16:41:33 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class AForm;

class Bureaucrat {
public:
	// Constructor
	Bureaucrat(std::string name, int grade);
	// Copy Constructor
	Bureaucrat(const Bureaucrat& other);
	// Copy Assignment Operator
	Bureaucrat& operator=(const Bureaucrat& other);
	// Destructor
	~Bureaucrat();
	

	std::string getName() const;
	int			getGrade() const;
	void		increment();
	void		decrement();
	void		signForm(AForm& form);

	class GradeTooHighException : public std::exception {
	public:
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw() { 
            return "Grade is too high.";
        }

	};

	class GradeTooLowException : public std::exception {
	public:
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw() {
            return "Grade is too low";
        }

	};

private:
	const std::string	_name;
	int					_grade; // range: 150-1

};


std::ostream & operator<<( std::ostream & o, Bureaucrat const & bureaucrat );

#endif

