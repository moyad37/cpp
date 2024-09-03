/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:46:44 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/01 16:08:49 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }

    std::ofstream outFile((target + "_shrubbery").c_str());

    if (outFile.is_open()) {
        outFile << "      # #### ####      " << std::endl;
        outFile << "     ### /#|### |/####     " << std::endl;
        outFile << "    ##/#/ ||/##/_/##/_#    " << std::endl;
        outFile << "   ###  /###|/ / # ###   " << std::endl;
        outFile << "  ##__#_## | #/###_/_####  " << std::endl;
        outFile << " ## #### #  #| /  #### ##/## " << std::endl;
        outFile << " __#_--###`  |{,###---###-~" << std::endl;
        outFile << "             }}{      " << std::endl;
        outFile << "             }}{      " << std::endl;
        outFile << "             }}{      " << std::endl;
        outFile << "        ejm  {{}      " << std::endl;
        outFile << "        , -=-~{ .-^- _      " << std::endl;

        outFile.close();
    } else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}
