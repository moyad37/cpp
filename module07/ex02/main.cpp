/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:19:45 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/13 18:01:29 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"
#include <cstdlib>
#include <ctime>

/*#define MAX_VAL 5
int	main(void)
{
	Array<int>	tab1(MAX_VAL);

	for (int i = 0; i != MAX_VAL; i++)
		tab1[i] = i;
	Array<int>	copy1(tab1);
	for (int i = 0; i != MAX_VAL; i++)
		std::cout << "tab1[" << i << "] = " << tab1[i] << std::endl << "copy1[" << i << "] = " << copy1[i] << std::endl;
	std::cout << std::endl;
	for (int i = 0; i != MAX_VAL; i++)
		tab1[i] = -i;
	Array<int>	copy2(tab1);
	for (int i = 0; i != MAX_VAL; i++)
		std::cout << "tab1[" << i << "] = " << tab1[i] << std::endl << "copy1[" << i << "] = " << copy1[i] << std::endl << "copy2[" << i << "] = " << copy2[i] << std::endl;
	return 0;
}*/

#define MAX_VAL 5
int	main(void)
{
	Array<char>	tab1(MAX_VAL);

	for (int i = 0; i != MAX_VAL; i++)
		tab1[i] = 'A' + i;
	Array<char>	copy1 = tab1;
	for (int i = 0; i != MAX_VAL; i++)
		std::cout << "tab1[" << i << "] = " << tab1[i] << std::endl << "copy1[" << i << "] = " << copy1[i] << std::endl;
	std::cout << std::endl;
	for (int i = 0; i != MAX_VAL; i++)
		tab1[i] = 'a' + i;
	Array<char>	copy2 = tab1;
	for (int i = 0; i != MAX_VAL; i++)
		std::cout << "tab1[" << i << "] = " << tab1[i] << std::endl << "copy1[" << i << "] = " << copy1[i] << std::endl << "copy2[" << i << "] = " << copy2[i] << std::endl;
}


/*#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}*/