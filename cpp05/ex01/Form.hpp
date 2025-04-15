/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:57:03 by sting             #+#    #+#             */
/*   Updated: 2025/04/14 18:05:19 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class Form {
public:
	// Constructor
	Form(std::string name, int gradeToSign, int gradeToExecute);
	// Copy Constructor
	Form(const Form& other);
	// Copy Assignment Operator
	Form& operator=(const Form& other);
	// Destructor
	~Form();

	// Getters
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void	beSigned(Bureaucrat& bureaucrat);
	void	signForm();


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
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

};


std::ostream & operator<<( std::ostream & o, Form const & bureaucrat );

#endif

