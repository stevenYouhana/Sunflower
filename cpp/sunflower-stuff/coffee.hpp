//
//  coffee.hpp
//  sample
//
//  Created by emi on 9/12/17.
//  Copyright © 2017 emi. All rights reserved.
//

#ifndef coffee_hpp
#define coffee_hpp

#include <stdio.h>

#endif /* coffee_hpp */

class Coffee {
public:
    Coffee(int beans);
    ~Coffee(){};
    int getBeans();
    void printBeans();
    int coffeeBeans;
};
