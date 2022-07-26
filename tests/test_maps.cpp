/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_maps.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:37:28 by cproesch          #+#    #+#             */
/*   Updated: 2022/07/26 18:31:59 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>
 
void print_map(std::string comment, const std::map<std::string, int>& m)
{
    std::cout << comment ;
    for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << " = " << it->second << "; ";
    }
    std::cout << '\n';
}
 
int main()
{
    // Default constructor
    std::map<std::string, int> map1;
    // map1["something"] = 69;
    // map1["anything"] = 199;
    // map1["that thing"] = 199;
    print_map("1) Initial map   : ", map1);
    std::cout << "8) map1.size() = " << map1.size() << '\n';
    
    // Range constructor
    std::map<std::string, int> iter(map1.find("something"), map1.end());
    print_map("2) Iter map      : ", iter);

    // Copy constructor
    std::map<std::string, int> copied(map1);
    print_map("3) Copied map    : ", copied);

    map1["cPU"] = 25;  // update an existing value
    map1["DSD"] = 30;  // insert a new value
    print_map("4) Updated map   : ", map1);
 
    // using operator[] with non-existent key always performs an insert
    std::cout << "5) map1[UPS] = " << map1["UPS"] << '\n';
    print_map("6) Updated map   : ", map1);
 
    map1.erase("cPU");
    print_map("7) After erase   : ", map1);
 
    std::cout << "8) map1.size() = " << map1.size() << '\n';
 
    map1.clear();
    std::cout << std::boolalpha << "9) Map is empty: " << map1.empty() << '\n';

    return 0;
}