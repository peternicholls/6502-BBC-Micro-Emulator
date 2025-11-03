//
//  BeebCore.cpp
//  BeebCore
//
//  Created by Peter Nicholls on 03/11/2025.
//

#include <iostream>
#include "BeebCore.hpp"
#include "BeebCorePriv.hpp"

void BeebCore::HelloWorld(const char * s)
{
    BeebCorePriv *theObj = new BeebCorePriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void BeebCorePriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

