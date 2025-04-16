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

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class AForm {
public:
	// Constructor
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	// Copy Constructor
	AForm(const AForm& other);
	// Copy Assignment Operator
	AForm& operator=(const AForm& other);
	// Destructor
	virtual ~AForm();

	// Getters
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void	beSigned(Bureaucrat& bureaucrat);
	void	signForm();
	virtual	void	execute(Bureaucrat const & executor) const = 0;


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
            return "Grade is too low.";
        }

	};
	class FormNotSignedException : public std::exception {
	public:
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw() {
            return "Form not signed.";
        }

	};
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

};


std::ostream & operator<<( std::ostream & o, AForm const & bureaucrat );

#endif

