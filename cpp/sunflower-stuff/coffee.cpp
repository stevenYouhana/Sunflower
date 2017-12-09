//
//  coffee.cpp
//  sample
//
//  Created by emi on 9/12/17.
//  Copyright © 2017 emi. All rights reserved.
//

#include <stdio.h>
#include "coffee.hpp"
#include <iostream>

Coffee::Coffee(int beans) {
    coffeeBeans = beans;
}
int Coffee::getBeans() {
    return coffeeBeans;
}

void Coffee::printBeans() {
    std::cout << "Number of beans: " << coffeeBeans << std::endl ;
}
